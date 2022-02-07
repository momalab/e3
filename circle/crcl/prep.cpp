// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include "prep.h"
#include "vars.h"
#include "crcl.h"

#include "using.h"

string Preprocessor::tokenize(const string & line)
{
    string r;

    bool inbr = false;
    for ( size_t i = 0; i < line.size(); i++ )
    {
        if ( line[i] == ']' ) inbr = false;
        if ( line[i] == '[' ) inbr = true;

        static const char spsyms[] = ",()=+-*!'{}~^&|";
        bool spsym = ( string(spsyms).find(line[i]) != string::npos );

        if ( inbr || !spsym )
            r += line[i];
        else
            r += string(" ") + line[i] + ' ';
    }

    return r;
}



vstr Preprocessor::expand(const string & line)
{
    // expand lines
    // for each line expand names

    vstr lns {apply(tokenize(line))};
    vstr v;
    while (true)
    {
        v.clear();
        bool mdf = false;
        for (auto ln : lns)
        {
            vstr a = expand1line(ln, &mdf);
            v.insert(v.end(), a.begin(), a.end());
        }
        if (!mdf) break;
        v.swap(lns);
    }

    for ( auto & ln : v )
        ln = expandNames(ln);

    return v;
}

vstr Preprocessor::expand1line(string line, bool * mdf)
{
    vstr r;
    istr is(line);

    string s; is >> s;

    if (mdf) *mdf = false;
    if ( s != "{") return vstr {line};
    if (mdf) *mdf = true;

    if ( procConDef(line) ) return r;

    string name; is >> name >> s;
    struct Oper { string op; int x; };
    struct ExtraIdx { string s; vector<Oper> v; };
    std::vector<ExtraIdx> idv; // extra indices

    // include
    if ( name == "=" )
    {
        name = s; is >> s;
        if ( !is || s != "}" )
            throw "expecting '}' after name in include, got [" + s + "]";
        return include(name);
    }


    if (!is || s != ",")
        throw "expecting ',' after name in expand expression, got [" + s + "]";

    int i1 = -1; is >> i1 >> s;

    if (!is || s != ",")
        throw "expecting ',' between range values, got [" + s + "]";

    int i2 = -1; is >> i2 >> s;

    if (!is)
        throw "while reading range values after [" + s + "]";

    // now read idv's
    while (1)
    {
        if (s == "}") break;
        else if (!is || s != ",")
            throw "expecting '}' to close expand expression, got [" + s + "]";

        string nm; s = ""; is >> nm >> s;
        if (!is || s != ",")
            throw "expecting ',' afetr extra index, got [" + s + "]";

        vector<Oper> v;
        while (1)
        {
            is >> s;
            if ( s == "}" ) break;
            if ( s == "," ) break;

            Oper k; k.op = s;
            is >> k.x;

            if (!is)
                throw "expecting operation at [" + k.op + "]";

            v.push_back(k);
        }

        idv.push_back({ nm, v });
    }

    if (i1 < 0 || i2 < 0 || i1 > i2)
        throw string() + "bad arguments in expand expression";

    // form the rest of the line
    string n;
    for (; is >> s;) n += " " + s;

    for (int i = i1; i <= i2; i++)
    {
        string x = n;
        Varman::replaceNum(x, name, i);

        for (auto d : idv)
        {
            // apply extra index operations
            int val = i;
            for ( auto op : d.v )
            {
                if (0) {}
                else if (op.op == "+") val += op.x;
                else if (op.op == "-") val -= op.x;
                else if (op.op == "*") val *= op.x;
                else if (op.op == "/") val /= op.x;
                else if (op.op == "%") val %= op.x;
                else throw "bad operation [" + op.op + "]";
            }

            if (val < 0)
                throw "Index goes negative [" + tos(val) + "] in [" + line + "]";

            Varman::replaceNum(x, d.s, val);
        }

        r.push_back(x);
    }

    return r;
}

string Preprocessor::expandNames(const string & ln)
{
    istr is(ln);
    string n, s;
    for (; is >> s;) n += " " + expand1name(s);
    return n;
}

string Preprocessor::expand1name(const string & w)
{
    auto i = w.find('[');
    if (i == string::npos) return w;
    auto j = w.find(']');
    if (j != w.size() - 1) throw "bad formed " + w;

    string name = w.substr(0, i);
    if ( i + 1 >= j - 1 ) throw "bad args in " + w;
    string brks = tokenize(w.substr(i + 1, j - 1));
    int i1 = -1, i2 = -1;
    string op;
    istr(brks) >> i1 >> op >> i2;

    if (i1 < 0 || i2 < 0 || i1 > i2)
        throw "bad arguments in vector expression " + w;

    if ( op.size() != 1 ) throw "bad operator in " + w;

    string r;
    for (int k = i1; k <= i2; k++)
    {
        if (k != i1) r += " " + op;
        string cntr = tos(k);
        if ( Prim::isConst(name) ) cntr = "";
        r += " " + name + cntr;
    }

    return r;
}

string Preprocessor::apply(const string & ln)
{
    string r = ln;
    for ( auto x : order )
        Varman::replaceNum(r, x, pcons[x]);

    return r;
}

bool Preprocessor::procConDef(const string & ln)
{
    istr is(ln);

    string s; is >> s;
    if ( s != "{") nevers("procConDef");

    auto i = ln.find('=');
    auto j = ln.find('}');

    if ( i == string::npos || j == string::npos
            || i > j ) return false;

    string name; is >> name >> s;
    if ( s != "=" ) return false;

    int v = 0, a = 0;
    is >> v;
    if (!is) throw string("After '=' expecting number or defined value");

    while (1)
    {
        is >> s;
        if ( s == "}" ) break;
        else if ( s == "+" ) { is >> a; v += a; }
        else if ( s == "-" ) { is >> a; v -= a; }
        else if ( s == "*" ) { is >> a; v *= a; }
        else if ( s == "/" ) { is >> a; v /= a; }
        else if ( s == "%" ) { is >> a; v %= a; }
        else throw "Unexpected [" + s + "]";
    }

    pcons[name] = v;
    order.push_back(name);

    return true;
}

vstr Preprocessor::include(string fname)
{
    string file = Context::cookfile(context.file, fname);

    std::ifstream in(file);
    if ( !in ) throw "Cannot open include file [" + file + "]";

    vstr r;

    int ln_cntr = 1;
    try
    {
        for (string line; std::getline(in, line); ++ln_cntr )
        {
            ol::cutline(line);
            if (line.empty() || line[0] == '#') continue;

            if (line.find('=') == string::npos)
            {
                if (Module::PRN) cout << "ignore line [ " << line << "]\n";
                continue;
            }

            vstr lines = expand(line);
            r.insert(r.end(), lines.begin(), lines.end());
        }
    }
    catch (string e)
    {
        throw "[" + file + "] line " + tos(ln_cntr) + ": " + e;
    }
    catch (...)
    {
        throw "unexpected c++ error [" + file + "] line " + tos(ln_cntr);
    }

    return r;
}

