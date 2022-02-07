// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// Circle - Circuit compiler

#include <map>
#include <set>

#include "olc.h"

#include "crcl.h"
#include "main.h"
#include "vars.h"
#include "eval.h"
#include "prep.h"

#include "using.h"

int e3::cr::g_instance_cntr = 0;
e3::cr::Context e3::cr::context;

bool Module::PRN = false;

Module::Module(string file, string prefix, bool noflatten)
    : filename(file), flat(!noflatten), reuse(false)
{
    Context oldcontext = context;
    context.prefix = prefix;
    context.file = file;

    instance_cntr = g_instance_cntr;

    static int depth = 0;
    if (++depth > MAXDEPTH)
        throw "Cannot load [" + file + "] because "
        "max depth (" + tos(MAXDEPTH) + ") is reached";
    {
        std::ifstream in(file);
        if (!in) throw "Cannot open [" + file + "]";
        load(in);
    }
    --depth;

    context = oldcontext;
    instance_cntr = g_instance_cntr - instance_cntr;
}

void Module::load(std::istream & is)
{
    int ln_cntr = 1;
    const int BIG = 1000;
    try
    {
        for (string line; std::getline(is, line); ++ln_cntr )
        {
            ol::cutline(line);
            if (line.empty() || line[0] == '#') continue;

            if (line.find('=') == string::npos)
            {
                if (PRN) cout << "ignore line [ " << line << "]\n";
                continue;
            }

            vstr lines = prep.expand(line);
            for (auto ln : lines)
            {

                if (!flat)
                {
                    statements.push_back(new Statement(ln));
                }
                else
                {
                    vector<Statement *> vsts = Statement::load(ln);
                    statements.insert(statements.end(), vsts.begin(), vsts.end());
                }
            }

            if ( ln_cntr > BIG && !(ln_cntr % BIG) ) cout << ln_cntr << " \r";
        }

        if ( ln_cntr > BIG ) cout << "read " << ln_cntr << " lines\n";
    }
    catch (string e)
    {
        throw "[" + filename + "] line " + tos(ln_cntr) + ": " + e;
    }
    catch (...)
    {
        throw "unexpected error at [" + filename + "] line " + tos(ln_cntr);
    }

    // now find inputs, outputs, middles
    // and last usage of middles
    initIOMs();

    // check var reuse
    reuse = !chkReuse().empty();
}

void Module::initIOMs()
{
    inputs.clear();
    outputs.clear();
    middles.clear();

    struct Index { int u1 = -1, u2 = -1; };
    std::map<string, Index> mi, mo;
    std::set<string> mm;

    int sz = size();
    for (int i = 0; i < sz; i++)
    {
        if (!statements[i]) continue;
        const Statement & s = *statements[i];

        vstr ins = s.getInVars();
        for (auto x : ins)
        {
            if (mi[x].u1 < 0) mi[x].u1 = i;
            mi[x].u2 = i;
            mm.insert(x);
        }

        vstr outs = s.getOutVars();
        for (auto x : outs)
        {
            if (mo[x].u1 < 0) mo[x].u1 = i;
            mo[x].u2 = i;
            mm.insert(x);
        }
    }

    middles.resize(statements.size());
    for (const auto & x : mm)
    {
        if (mo.find(x) == mo.end()) { inputs.push_back(x); continue; }
        if (mi.find(x) == mi.end()) { outputs.push_back(x); continue; }
        // now x in both mo and mi
        int mc = 0;
        if (mi[x].u1 <= mo[x].u1) inputs.push_back(x); else ++mc;
        if (mi[x].u2 <= mo[x].u2) outputs.push_back(x); else ++mc;
        if (mc == 2) middles[mi[x].u2].push_back(x);
    }

    // reorder inputs and output to human (alphanum) order

    struct anless
    {
        bool dig(string x) { return std::all_of(x.begin(), x.end(), ::isdigit); }
        bool operator()(string a, string b)
        {
            auto asz = a.size(), bsz = b.size();
            if (asz == bsz) return a < b;
            size_t i = 0;
            for (; i < asz && i < bsz; i++) if (a[i] != b[i]) break;
            if (i == asz) return true;
            if (i == bsz) return false;
            string as = a.substr(i);
            string bs = b.substr(i);
            if (!dig(as) || !dig(bs)) return a < b;
            int ai = std::stoi(as);
            int bi = std::stoi(bs);
            return ai < bi;
        }
    };

    std::sort(inputs.begin(), inputs.end(), anless());
    std::sort(outputs.begin(), outputs.end(), anless());
}

std::map<string, int> Module::chkReuse() const
{
    // returns list of reused vars with the first encounter
    // in the output of the secons assignement

    std::map<string, int> r;
    std::set<string> chk;
    chk.insert(inputs.begin(), inputs.end());

    for (int i = 0; i < size(); i++)
    {
        const Statement & s = *statements[i];

        vstr outs = s.getOutVars();
        for (auto x : outs)
        {
            if (chk.find(x) == chk.end())
                chk.insert(x);
            else if ( r.find(x) == r.end() )
                r[x] = i;
        }
    }

    return r;
}

std::set<string> fill_keys(const char * v[], int sz)
{
    std::set<string> r;
    for ( int i = 0; i < sz; i++ ) r.insert(v[i]);
    return r;
}

void wr_arr(std::ostream & os, const vstr & v,
            string prx, string pox, string inx,
            int br = 0, string ind = "")
{
    int cntr = 0;
    auto last = v[v.size() - 1];
    for (auto x : v)
    {
        if (br && cntr++ > br) { cntr = 0; os << ind; }
        os << prx << x << pox;
        if (x != last) os << inx;
    }
}

void Module::verilog(std::ostream & os, bool wire_decl)
{
    if ( inputs.empty() || outputs.empty() )
        throw "Cannot write verilog for empty inouts";

    const int VK_NUM = 99;
    static const char * vkeys[VK_NUM] =
    {
        "always", "and", "assign", "begin", "buf", "bufif0", "bufif1", "case", "casex", "casez",
        "cmos", "deassign", "default", "defparam", "disable", "edge", "else", "end", "endcase",
        "endfunction", "endmodule", "endprimitive", "endspecify", "endtable", "endtask",
        "event", "for", "force", "forever", "fork", "function", "highz0", "highz1", "if",
        "initial", "inout", "input", "integer", "join", "large", "macromodule", "medium",
        "module", "nand", "negedge", "nmos", "nor", "not", "notif0", "notif1", "or", "output",
        "pmos", "posedge", "primitive", "pull0", "pull1", "pulldown", "pullup", "rcmos", "reg",
        "release", "repeat", "rnmos", "rpmos", "rtran", "rtranif0", "rtranif1", "scalared",
        "small", "specify", "specparam", "strong0", "strong1", "supply0", "supply1", "table",
        "task", "time", "tran", "tranif0", "tranif1", "tri", "tri0", "tri1", "triand", "trior",
        "vectored", "wait", "wand", "weak0", "weak1", "while", "wire", "wor", "xnor", "xor",
        // extra for FPGA simulator
        "cell", "use"
    };

    static std::set<string> verilogKey = fill_keys(vkeys, VK_NUM);

    auto allvars = getAllVars();
    for (auto x : allvars)
        if ( verilogKey.find(x) != verilogKey.end() )
            replaceVar(x + "$", x);


    os << "// " << LogoF << '\n';

    string fn = filename;
    replaceAll(fn, ".", "_");
    os << "module " << fn << " (\n";

    os << "input wire";
    wr_arr(os, inputs, " ", ",", "", 10, "\n ");
    os << '\n';

    os << "output wire ";
    wr_arr(os, outputs, "", "", ", ", 10, "\n  ");
    os << '\n';

    os << ");\n\n";

    if ( wire_decl && !middles.empty() )
    {
        vstr mids;
        for ( auto a : middles ) for ( auto b : a ) mids.push_back(b);
        os << "wire";
        wr_arr(os, mids, " ", "", ",", 10, "\n  ");
        os << ";\n\n";
    }

    for (const auto & x : statements)
        if (x) os << "assign " << (*x) << ";\n";

    os << "\nendmodule\n";

    // check if input is 1,2,3 multiple of output
    int mul = 0;
    auto sz = outputs.size();
    for ( int i = 1; i <= 3; i++ ) if ( inputs.size() == i * sz ) mul = i;

    if ( mul )
    {
        string args = "(a,z)";
        if ( mul == 2 ) args = "(a,b,z)";
        if ( mul == 3 ) args = "(a,b,c,z)";

        os << "\nmodule " << fn << "_array " << args << ";\n";
        os << "input [" << sz - 1 << ":0] a;\n";
        if ( mul > 1) os << "input [" << sz - 1 << ":0] b;\n";
        if ( mul > 2) os << "input [" << sz - 1 << ":0] c;\n";
        os << "output [" << sz - 1 << ":0] z;\n";

        int cnt = 0;
        auto out = [&os, &cnt, sz](string n, bool cma)
        {
            for ( size_t i = 0; i < sz; i++ )
                os << (i || cma ? "," : "")
                   << (++cnt % 10 ? "" : "\n  ")
                   << n << "[" << i << "]";
        };

        os << fn << " " << fn << "1(";

        out("a", false);
        if ( mul > 1) out("b", true);
        if ( mul > 2) out("c", true);
        out("z", true);

        os << ");\nendmodule\n";
    }
}

void Module::out(std::ostream & os) const
{
    os << LogoF << '\n';
    os << "# inputs:";

    for ( auto x : inputs ) os << ' ' << x;
    os << '\n';

    if ( chkSameSz(inputs) ) cout << warnI();

    bool SHOW_REMOVES = false;
    if (!SHOW_REMOVES)
    {
        for (const auto & x : statements)
            if (x) os << (*x) << '\n';
    }
    else
    {
        int sz = size();
        for (int i = 0; i < sz; i++)
        {
            if (!statements[i]) continue;
            os << (*statements[i]) << '\n';

            if (middles[i].empty()) continue;
            os << "# -";
            for (auto s : middles[i]) os << ' ' << s;
            os << '\n';
        }
    }

    os << "# outputs:";
    for ( auto x : outputs ) os << ' ' << x;
    os << '\n';

    if ( chkSameSz(outputs) ) cout << warnO();
}

void Module::outc_replaceVars()
{
    if (inputs.empty() || outputs.empty())
        throw "Cannot write C for empty inouts";

    const int CK_NUM = 110;
    static const char * ckeys[CK_NUM] =
    {
        "alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit",
        "atomic_noexcept", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
        "char", "char16_t", "char32_t", "class", "co_await", "co_return", "co_yield",
        "compl", "concept", "const", "const_cast", "constexpr", "continue", "decltype",
        "default", "define", "defined", "delete", "do", "double", "dynamic_cast", "elif",
        "else", "endif", "enum", "error", "explicit", "export", "extern", "false",
        "final", "float", "for", "friend", "goto", "if", "ifdef", "ifndef", "import",
        "include", "inline", "int", "line", "long", "module", "mutable", "namespace",
        "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq",
        "override", "pragma", "private", "protected", "public", "register",
        "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static",
        "static_assert", "static_cast", "struct", "switch", "synchronized", "template",
        "this", "thread_local", "throw", "transaction_safe", "transaction_safe_dynamic",
        "true", "try", "typedef", "typeid", "typename", "undef", "union", "unsigned",
        "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
    };

    static std::set<string> cKey = fill_keys(ckeys, CK_NUM);

    auto allvars = getAllVars();
    auto sz = allvars.size();
    bool bco = (sz > 1000);
    for (auto y : allvars)
    {
        string x = y;
        ol::replaceAll(x, ".", "_");
        ol::replaceAll(x, ":", "_");
        ol::replaceAll(x, "/", "_");
        if ( x != y ) replaceVar(x, y);

        if (cKey.find(x) != cKey.end())
            replaceVar(x + "_", x);
        if ( bco && !((--sz) % 10) ) cout << sz << " \r";
    }
}

// this is the old fucntion which is not switched on
// this function outputs separate arguments instead of arrays
void Module::outc_arg(std::ostream & os)
{
    outc_replaceVars();

    os << "// " << LogoF << '\n';
    os << "typedef char bool;\n\n";

    string fn = filename;
    replaceAll(fn, ".", "_");
    os << "void " << fn << " (\n   ";

    wr_arr(os, inputs, " bool ", ",", "", 5, "\n   ");
    os << "\n   ";

    wr_arr(os, outputs, " bool *", "", ",", 4, "\n   ");
    os << '\n';

    os << ")\n{\n";

    for (const auto & x : statements)
    {
        if ( x->getOutVars().empty() ) continue;
        if ( ol::isin(outputs, x->getOutName() ) )
            os << "*";
        else
            os << "bool ";
        os << (*x) << ";\n";
    }

    os << "\n}\n";

    // output main function
    os << "\nint main()\n{\n  int i, j;\n  bool";
    wr_arr(os, inputs, " ", "=0", ",", 10, "\n    ");

    os << ";\n  bool";
    wr_arr(os, outputs, " ", "", ",", 17, "\n    ");
    os << ";\n";

    os << "  for (i = 0; i < 1; i++) for (j = 0; j < 1; j++)\n";
    os << "  {\n";
    os << "    " << fn << " (\n";
    os << "    ";
    wr_arr(os, inputs, "", ", ", "", 5, "\n      ");
    os << "\n    ";
    wr_arr(os, outputs, "&", "", ", ", 5, "\n      ");
    os << " );\n";
    os << "  }\n";
    os << "}\n";
}

void Module::outc_arr(std::ostream & os)
{
    outc_replaceVars();

    os << "// " << LogoF << '\n';
    //os << "typedef char bool;\n\n";

    auto isz = inputs.size();
    auto osz = outputs.size();

    int opn = 1;
    if (isz == 2 * osz) opn = 2;
    if (isz == 3 * osz) opn = 3;

    string fn = filename + "_" + tos(isz) + "_" + tos(osz);
    if ( opn == 2 ) fn = filename + "_binop_" + tos(osz);
    if ( opn == 3 ) fn = filename + "_triop_" + tos(osz);

    replaceAll(fn, ".", "_");
    replaceAll(fn, "/", "_");

    {
        string s = "x";
        if ( opn == 2 ) s = " a_, const char *b";
        if ( opn == 3 ) s = " a_, const char *b_, const char *c";

        os << "void " << fn << "(const char *"
           << s << "_, char *y_)\n{\n";
    }

    // output forward reassignments: x0 = x_[0]
    if ( opn == 1 )
    {
        int i = 0;
        for (auto x : inputs) os << "char " << x << " = x_[" << (i++) << "];\n";
    }
    else
    {
        for ( size_t i = 0; i < osz; i++ )
            os << "char " << inputs[i] << " = a_[" << (i) << "];\n";
        for ( size_t i = 0; i < osz; i++ )
            os << "char " << inputs[i + osz] << " = b_[" << (i) << "];\n";

        if (opn == 3)
        {
            for ( size_t i = 0; i < osz; i++ )
                os << "char " << inputs[i + 2 * osz] << " = c_[" << (i) << "];\n";
        }
    }

    // output main statements
    for (const auto & x : statements)
    {
        if ( x->getOutVars().empty() ) continue;
        os << "char " << (*x) << ";\n";
    }

    // output backward reassignments: y_[0] = y0
    {
        int i = 0;
        for (auto x : outputs)
            os << "y_[" << (i++) << "] = " << x << ";\n";
    }

    os << "}\n";

    // output main function
    os << "\nint test_" << fn << "()\n{\n  int i, j;\n";

    if (opn == 2)
        os << "  char a[" << osz << "], b[" << osz << "];\n";
    else if (opn == 3)
        os << "  char a[" << osz << "], b[" << osz << "], c[" << osz << "];\n";
    else
        os << "  char x[" << isz << "];\n";

    os << "  char y[" << osz << "];\n\n";

    os << "  for (i = 0; i < 1; i++) for (j = 0; j < 1000; j++)\n";
    os << "  {\n";
    os << "    " << fn << " (";
    os << (opn == 2 ? "a,b" : opn == 3 ? "a,b,c" : "x");
    os << ",y);\n";
    os << "    " << (opn > 1 ? "a" : "x") << "[0] = y[0]; /* no opt */\n";
    os << "  }\n  return 0;\n";
    os << "}\n";
}

bool Module::chkSameSz(const vstr & v)
{
    size_t sz = 0;
    bool warn = false;
    for ( auto x : v )
    {
        if ( sz && sz != x.size() )
        {
            warn = true;
            break;
        }
        sz = x.size();
    }
    return warn;
}


string Module::summary() const
{
    string r;
    // input flat output middle totals clean (no var reuse)

    int midsize = 0;
    for (auto x : middles) midsize += (int)x.size();

    r += "File: " + filename;
    r += "\nInout     : " + tos(inputs.size()) + 'x' + tos(outputs.size());
    r += "\nInputs    :"; for (auto x : inputs) r += " " + x;
    r += "\nOutputs   :"; for (auto x : outputs) r += " " + x;
    r += "\nMiddles   : " + tos(midsize);
    r += "\nTot vars  : " + tos(midsize + inputs.size() + outputs.size());
    r += "\nHierarchy : " + tos(flat ? "flat" : "shallow");
    r += "\nInst cntr : " + tos(instance_cntr);
    r += "\nVar reuse : " + tos(reuse ? "yes" : "no") + '\n';

    if ( chkSameSz(inputs) ) r += warnI();
    if ( chkSameSz(outputs) ) r += warnO();

    return r;

}

void Module::cleanVars()
{
    // function getAllVars fails due to modifications,
    // e.g. same name in outpus and middle renamed in outputs
    // disappears from allVars, hence using total vars
    auto totVars = getAllVars();

    // this function renames unclean (reused) variables

    // First we need to make sure that inputs and outputs have different names.
    // This is necessary because outputs cannot be renamed becasue it breaks
    // their order.
    if (0) //
    {
        vstr bads;
        for ( auto x : outputs )
            if ( ol::isin(inputs, x) )
                bads.push_back(x);

        if ( !bads.empty() )
        {
            ostr os;
            wr_arr(os, bads, "", "", ", ");
            cout << "Warning: Found same input/output names [ " + os.str() + " ]. ";
            cout << "All outputs will be renamed\n";

            // replace outputs
            auto allVars = getAllVars(); // watch out fot totVars
            Varman vm;
            int cntr = 0;
            for (auto & x : outputs)
            {
                string ov = x;
                string nv = vm.y(cntr++);
                while (allVars.find(nv) != allVars.end()) nv = vm.y(cntr++);
                x = nv;
                replaceVar(nv, ov);
            }

        } // bads
    } // fixing outputs

    bool out_affected = false;
    // core function
    if (1)
    {
        std::map<string, int> vars;
        int cntr = 0;
        Varman vm;
        while (!(vars = chkReuse()).empty())
        {
            {
                auto av = getAllVars();
                totVars.insert(av.begin(), av.end());
            }

            for (auto v : vars)
            {
                auto old = v.first;
                auto line = v.second;

                string n = vm.middle(cntr++);
                while (totVars.find(n) != totVars.end()) n = vm.middle(cntr++);

                for (int i = line; i < size(); i++)
                {
                    bool outonly = (i == line);
                    statements[i]->chVar(n, old, outonly);
                } // next statement

                // done with statements, now update outputs
                for (auto & x : outputs)
                    if (x == old)
                    {
                        x = n;
                        out_affected = true;
                    }
            } // next var
        } // try clean again
    } // core
    else
    {
        std::map<string, int> vars;
        int cntr_m = 0, cntr_y = 0;
        Varman vm;
        while (!(vars = chkReuse()).empty())
        {
            vstr order; // list of vars in which order we will process

            // first process outputs
            for ( auto o : outputs )
                if ( vars.find(o) != vars.end() )
                    order.push_back(o);

            // remember how many outputs
            auto o_cntr = order.size();

            // now all the remaining vars
            for ( auto x : vars )
                if ( !ol::isin(outputs, x.first) )
                    order.push_back(x.first);

            auto allVars = getAllVars();
            for (auto old : order)
            {
                auto line = vars[old];

                string n; // select name
                if ( !o_cntr )
                {
                    n = vm.middle(cntr_m++);
                    while (allVars.find(n) != allVars.end()) n = vm.middle(cntr_m++);
                }
                else // output
                {
                    o_cntr--;
                    n = vm.y(cntr_y++);
                    while (allVars.find(n) != allVars.end()) n = vm.y(cntr_y++);
                }

                for (int i = line; i < size(); i++)
                {
                    bool outonly = (i == line);
                    statements[i]->chVar(n, old, outonly);
                } // next statement

                // done with statements, now update outputs
                for (auto & x : outputs)
                    if (x == old)
                    {
                        x = n;
                        out_affected = true;
                    }
            } // next var
        } // try clean again
    } // core

    // now fix the order of outputs - can be broken
    if (out_affected)
    {
        for (auto & x : outputs)
        {
            string nv = "?" + x;
            replaceVar(nv, x);
            x = nv;
        }

        {
            auto av = getAllVars();
            totVars.insert(av.begin(), av.end());
        }

        Varman vm;
        int cntr = 0;
        for (auto & x : outputs)
        {
            string ov = x;
            string nv = vm.y(cntr++);
            while (totVars.find(nv) != totVars.end()) nv = vm.y(cntr++);
            x = nv;
            replaceVar(nv, ov);
        }
    }

    auto osz = outputs.size();
    initIOMs();
    if (osz != outputs.size())
        cout << "Warning: number of outputs changed due to superfluous vars\n";

    reuse = !chkReuse().empty();
}

std::set<string> Module::getAllVars() const
{
    std::set<string> r;

    r.insert(inputs.begin(), inputs.end());
    r.insert(outputs.begin(), outputs.end());

    for (const auto & x : middles)
        r.insert(x.begin(), x.end());

    return r;
}

void Module::replaceAllVars()
{
    if (!chkReuse().empty()) nevers("reuse");

    auto allvars = getAllVars();

    int cntr = 0;
    auto sz = middles.size();
    auto szd = sz / 1000;
    bool prned = (szd > 1);

    // this loop and the one below could be optimized O(n^2) to O(n)
    // no need so far
    for (auto x : allvars)
    {
        replaceVar("?" + x, x);
        if ( szd > 1 && !(++cntr % szd) )
            cout << int(100.*cntr /  middles.size() + 0.5 ) << "%  \r";
    }

    initIOMs();

    Varman vm;

    // replace inputs
    cntr = 0;
    for (auto & x : inputs)
    {
        string ov = x;
        string nv = vm.x(cntr++);
        x = nv;
        replaceVar(nv, ov);
    }

    // replace outputs
    cntr = 0;
    for (auto & x : outputs)
    {
        string ov = x;
        string nv = vm.y(cntr++);
        x = nv;
        replaceVar(nv, ov);
    }

    // replace middles
    cntr = 0;
    sz = middles.size();
    szd = sz / 1000;
    prned = ( prned || (szd > 1) );

    for ( auto & v : middles)
    {
        for (auto & x : v )
        {
            string ov = x;
            string nv = vm.middle(cntr++);
            x = nv;
            replaceVar(nv, ov);

            if ( szd > 1 && !(cntr % szd) )
                cout << int(100.*cntr /  middles.size() + 0.5 ) << "%  \r";
        }
    }

    initIOMs();
    if ( prned ) cout << "done\n";
}

void Module::replaceVar(string nv, string ov)
{
    for (auto x : statements) x->chVar(nv, ov, false);
}




Statement::Statement(string line)
{
    try
    {
        try
        {
            // not needed since preprocessor has been called in module
            //line = prep::tokenize(line);

            Pstream is(line);
            string s;
            is >> oexpr >> s;
            if (s != "=") throw "Expecting '=', got [" + s + "]";
            if (oexpr.name.empty()) iexpr.expectblock = true;
            is >> iexpr;
        }
        catch (const char * e) { throw string(e); }
    }
    catch (string e)
    {
        throw "line [" + line + "] : " + e;
    }
}

void Statement::out(std::ostream & os) const
{
    os << oexpr << " =" << iexpr;
}

vector<Statement *> Statement::load(string line)
{
    Statement st(line);
    if (!st.oexpr.name.empty()) return vector<Statement *> { new Statement(st) };

    // otherwise we have a module
    string file = Context::cookfile(context.file, st.iexpr.modname);
    string prefix = Context::cookprefix(st.iexpr.modname, ++g_instance_cntr);

    Module mod(file, prefix);

    auto r = bind_ios(mod.inputs, st.iexpr.args.names, true);
    r = ol::vplus(r, mod.statements);
    r = ol::vplus(r, bind_ios(st.oexpr.args.names, mod.outputs, false));
    return r;
}

vector<Statement *> Statement::bind_ios(vstr a, vstr b, bool in)
{
    auto sz = b.size();
    if (a.size() != sz)
    {
        string n;
        if (a.size() < sz) n = b[a.size()];
        else n = a[b.size()];
        if ( in )
            throw "Bad number of inputs: " + tos(sz) +
            ", module requires " + tos(a.size()) + ", see [" + n + "]";
        else
            throw "Bad number of outputs: " + tos(a.size()) +
            ", module requires " + tos(sz) + ", see [" + n + "]";
    }

    // there are two options here: either construct in place Statement
    // which is the proper way, or cheat and reuse Statement parser
    // in this case, however, need to switch off context
    Context oldcontext = context;
    context = Context();
    vector<Statement *> r;
    for (auto i = sz * 0; i < sz; i++ )
        r.push_back( new Statement(a[i] + " = " + b[i]) );
    context = oldcontext;

    return r;
}

void Statement::chVar(string nv, string ov, bool outonly)
{
    oexpr.chVar(nv, ov);
    if (outonly) return;
    iexpr.chVar(nv, ov);
}

string Statement::getOutName() const
{
    auto r = oexpr.getVars();
    if (r.size() != 1) never;
    return r[0];
}



string Context::cookfile(string oldfile, string name)
{
    auto i = oldfile.rfind('/');
    if (i == string::npos) return name;
    return oldfile.substr(0, i + 1) + name;
}

string Context::cookprefix(string name, int cntr)
{
    return name + ':' + tos(cntr) + ':';
}

int Module::findStatement(string oname) const
{
    for (int i = 0; i < size(); i++)
    {
        const Statement * s = statements[i];
        if ( !s ) continue;
        vstr x = s->getOutVars();
        if ( x.size() != 1 ) continue;
        if ( x[0] == oname ) return i;
    }

    return -1;
}

int Module::findLastUse(string mname) const
{
    for ( int i = 0; i < (int)middles.size(); i++ )
    {
        const vstr & v = middles[i];
        for ( auto s : v ) if ( s == mname ) return i;
    }

    return -1;
}

int Module::findNofUse(string name) const
{
    int r = 0;
    for (int i = 0; i < size(); i++)
    {
        const Statement * s = statements[i];
        if ( !s ) continue;
        vstr inv = s->getInVars();
        if ( ol::isin(inv, name) ) ++r;
    }

    return r;
}
