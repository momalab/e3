// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include "eval.h"

#include "ttbl.h"
#include "vars.h"
#include "main.h"
#include "crutil.h"
#include "olrnd.h"

#include "using.h"

using Val = ValTtbl;



string outputBitOrN(bool ari, const vector<Val> & v, int beg, int end)
{
    // first find the length of the gratest number
    int len = end - beg;
    auto maxnum = (1ull << len) - 1;
    auto maxsz = tos(maxnum).size();

    if (!ari)
    {
        ostr os;
        for (int i = beg; i < end; i++) os << int(v[i].bit);
        return os.str();
    }

    ol::ull x = 0;
    for (int i = beg; i < end; i++)
        if (v[i].bit) x |= ( 1ull << (i - beg) );

    string r = tos(x);
    while (r.size() < maxsz) r = ' ' + r;
    return r;
}

string outputBitOrN(bool ari, const vector<Val> & v, int what)
{
    int sz = (int)v.size();

    switch (what)
    {
        case 1: return outputBitOrN(ari, v, 0, sz / 2);
        case 2: return outputBitOrN(ari, v, sz / 2, sz);
    }

    return outputBitOrN(ari, v, 0, sz);
}

bool TableIterator::bit(int j) const
{
    if ( v ) return (*v)[(unsigned)i][j];
    return bool((1ull << j)&i);
}

static void writeTT4(
    std::ostream & of, const Module & prog,
    TableIterator & it, bool arith)
{
    int sz = prog.input_size();
    if (sz < 1) throw "Empty circle";

    if (arith)
    {
        of << "# ";
        if ( sz % 2 ) of << sz;
        else of << (sz / 2) << ' ' << (sz / 2);
        of << ' ' << prog.output_size() << '\n';
    }

    int cntr = 0;
    vector<Val> input(sz);
    for ( ; it.ok(); it.next() )
    {
        if (++cntr > 10000)
        {
            cout << int(10000.0 * it.idx() / it.size() ) / 100 << "%  \r";
            cntr = 0;
        }

        for (int j = 0; j < sz; j++)
            input[j] = Val { it.bit(j) };

        BitVisitorTtbl bitVisitor;
        vector<Val> out = prog.eval(bitVisitor, input);

        if ( arith ) of << ' ';

        if ( sz % 2 )
        {
            of << outputBitOrN(arith, input, 3) << ' ';
        }
        else
        {
            of << outputBitOrN(arith, input, 1) << ' ';
            of << outputBitOrN(arith, input, 2) << ' ';
        }
        of << outputBitOrN(arith, out, 3) << '\n';
    }
}


string ari2bit(string w, int sz)
{
    string r;
    ol::ull n; istr(w) >> n;
    for (int i = 0; i < sz; i++)
    {
        r += (n & 1ull) ? '1' : '0';
        n >>= 1;
    }
    return r;
}

void loadAriLine(string line,
                 string & sin1, string & sin2, string & sout,
                 int iin1, int iin2, int iout)
{
    istr(line) >> sin1 >> sin2 >> sout;
    sin1 = ari2bit(sin1, iin1);
    sin2 = ari2bit(sin2, iin2);
    sout = ari2bit(sout, iout);
}

void e3::cr::tt2Circle(std::istream & in, string file)
{
    int szi = -1, szo = -1, cntr = 0;
    ostr os;
    Varman vm;
    bool inited = false;

    using vbool = vector<bool>;
    vbool oinited;

    int iin1 = 0, iin2 = 0, iout = 0;
    for (string line; std::getline(in, line); )
    {
        if (line.empty() ) continue;

        if (line[0] == '#')
        {
            istr(line.substr(1)) >> iin1 >> iin2 >> iout;
            continue;
        }

        string sinp, sin1, sin2, sout;

        if ( line[0] == ' ' )
            loadAriLine(line, sin1, sin2, sout, iin1, iin2, iout);
        else
            istr(line) >> sin1 >> sin2 >> sout;


        // checks
        if (sin1.empty() || sin2.empty() ||
                (sin1 + sin2).find_first_not_of("01") != string::npos)
            throw "Bad table";

        if (sout.empty())
        {
            sinp = sin1;
            sout = sin2;
        }
        else
            sinp = sin1 + sin2;

        if (szi != (int)sinp.size() && inited ) throw "Bad table: bad input";
        if (szo != (int)sout.size() && inited ) throw "Bad table: bad output";

        // initialize
        if (!inited)
        {
            szi = (int)sinp.size();
            szo = (int)sout.size();
            oinited = vbool(szo, false);
            inited = true;
        }

        // check if need to output
        if (sout.find('1') == string::npos) continue;

        string mname = vm.middle(cntr++);

        // write formula
        os << mname << " = ";
        for (int i = 0; i < szi; i++)
        {
            if (i) os << " & ";
            if (sinp[i] == '0') os << '!';
            os << vm.input(i);
        }
        os << '\n';

        // write output
        for (int i = 0; i < szo; i++)
        {
            if (sout[i] == '0') continue;
            string vo = vm.output(i);
            os << vo << " = ";
            if ( oinited[i] ) os << vo << " | ";
            os << mname << '\n';
            oinited[i] = true;
        }
    }

    // this buffereing is for errors - so no output is produced
    std::ofstream of(file);
    if (!of) throw "Cannot open file for output";
    of << LogoF << '\n';
    of << os.str();
}

void e3::cr::loadTT(std::istream & in, TableIterator::vvb & v, int sz, bool ari)
{
    // consume header line for arith
    if (ari) { string line; std::getline(in, line); }

    for (string line; std::getline(in, line); )
    {
        string w, w2;
        if ( sz % 2 ) istr(line) >> w;
        else istr(line) >> w >> w2;

        if ( ari )
        {
            if ( sz % 2 ) w = ari2bit(w, sz);
            else
            {
                w = ari2bit(w, sz / 2);
                w2 = ari2bit(w2, sz / 2);
            }
        }

        w += w2; // now w holds all input bits
        if ((int)w.size() != sz) throw "Expecting " + tos(sz) + " bits in table file, got " + tos(w.size());
        vector<bool> r(sz);
        for (int i = 0; i < sz; i++)
        {
            r[i] = (w[i] == '1');
            if (w[i] != '1' && w[i] != '0') throw "Expecting 0 or 1 bit values in table file";
        }
        v.push_back(r);
    }
}

bool e3::cr::checkFmt(string file, std::istream & in)
{
    bool ari = false;
    char c;
    in.get(c); in.putback(c);

    if (c == '#') ari = true;
    else if (c == '0') {}
    else if (c == '1') {}
    else throw "Unexpected format at [" + file + "]";
    return ari;
}

void e3::cr::writeTT(string ofile, const Module & prog, bool arith)
{
    int sz = prog.input_size();
    if (sz < 1) throw "Empty circle";

    TableIterator it(sz);
    using vvb = TableIterator::vvb;
    vvb v;

    {
        std::ifstream in(ofile);
        if ( !in )
        {
            in.close();
            std::ofstream of(ofile);
            ::writeTT4(of, prog, it, arith);
            return;
        }

        bool cur_ari = checkFmt(ofile, in);
        cout << "reading [" << ofile << "] for inputs\n";
        loadTT(in, v, sz, cur_ari);
    }

    it.setvvb(v);
    std::ofstream of(ofile);
    ::writeTT4(of, prog, it, arith);
}

bool validate(Module & p1, Module & p2, vector<Val> & input, string fil1, string fil2)
{
    BitVisitorTtbl bitVisitor;
    vector<Val> out1 = p1.eval(bitVisitor, input);
    vector<Val> out2 = p2.eval(bitVisitor, input);

    auto szo = out1.size();
    if (szo != out2.size()) nevers("validate");

    for (int i = 0; i < (int)szo; i++)
    {
        if (out1[i].bit == out2[i].bit) continue;
        cout << "Difference found for [" << fil1 << "] [" << fil2 << "]";
        cout << "\ninput : "; for (auto v : input) cout << int(v.bit);
        cout << "\noutput 1 : "; for (auto v : out1) cout << int(v.bit);
        cout << "\noutput 2 : "; for (auto v : out2) cout << int(v.bit);
        cout << "\n";
        return false;
    }
    return true;
}

static void verify1(
    Module & p1, Module & p2,
    int sz, int szo, string seedsize,
    string fil1, string fil2, bool nonly)
{
    string seed = "0";
    ol::ull size = sz;
    if (!seedsize.empty())
    {
        std::ifstream in(seedsize);
        in >> seed >> size;
    }

    std::ofstream of;
    if (nonly) of.open(fil1 + ".out");

    std::shared_ptr<Rnd> rnd(Rnd::newRnd(seed));
    int cntr = 0;
    vector<Val> input(sz);
    for (ol::ull i = 0; i < size; i++)
    {
        if (++cntr > 10000)
        {
            cout << int(10000.0 * i / size) / 100 << "%  \r";
            cntr = 0;
        }

        for (int j = 0; j < sz; j++)
            input[j].bit = bool(rnd->next() % 2);

        if (nonly) of << outputBitOrN(false, input, 3) << '\n';
        else if (!validate(p1, p2, input, fil1, fil2)) return;
    }

    if (nonly) return;

    string ex;
    if (!seedsize.empty()) ex = " with [" + seedsize + "]";
    cout << "No difference found: [" << fil1 << "] [" << fil2 << "]" << ex << "\n";
    cout << "checked " << size << " inputs with seed=" << seed << '\n';
}

void e3::cr::verify(string fil1, string fil2, bool brnd, string extra, bool nonly)
{
    Module prog1(fil1), prog2(fil2);

    int sz = prog1.input_size();
    if (sz < 1) throw "Empty circle";

    if ( sz != prog2.input_size() )
        throw "Circles have different input sizes";

    int szo = prog1.output_size();
    if ( szo != prog2.output_size() )
        throw "Circles have different output sizes";

    if (brnd)
        return ::verify1(prog1, prog2, sz, szo, extra, fil1, fil2, nonly);

    TableIterator it(sz);
    using vvb = TableIterator::vvb;
    vvb ve;

    if ( !extra.empty() )
    {
        std::ifstream in(extra);
        if ( !in ) throw "Bad file [" + extra + "]";
        bool cur_ari = checkFmt(extra, in);
        loadTT(in, ve, sz, cur_ari);
        it.setvvb(ve);
    }

    int cntr = 0;
    vector<Val> input(sz);
    for (; it.ok(); it.next())
    {
        if (++cntr > 10000)
        {
            cout << int(10000.0 * it.idx() / it.size()) / 100 << "%  \r";
            cntr = 0;
        }

        for (int j = 0; j < sz; j++)
            input[j] = Val { it.bit(j) };

        if (!validate(prog1, prog2, input, fil1, fil2)) return;
    }

    string ex;
    if (!extra.empty()) ex = " for [" + extra + "]";
    cout << "Same: [" << fil1 << "] [" << fil2 << "]" << ex << "\n";
}
