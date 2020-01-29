
#include <iostream> // debug
#include <fstream>
#include <vector>
#include <map>

#include "anykey.h"

using std::string;

namespace deco
{
char begin = '[';
char end = ']';
}

namespace
{

string loadConst(string file, int idx)
{
    // add mutex for multithreaded
    static std::map< string, std::vector<string> > mres;

    auto & res = mres[file];

    if ( !res.empty() )
    {
        if ( idx >= (int) res.size() ) throw "Mismatch in file [" + file + "]";
        return res[idx];
    }

    std::ifstream in(file);
    if ( !in ) throw "Cannot open [" + file + "]";
    for (string line; std::getline(in, line); ) res.push_back(line);

    return loadConst(file, idx);
}

string loadConst(string typ, string id)
{
    return ::loadConst( typ + ".const", std::stoi(id.substr(1)) );
}

} // local

namespace e3
{

string AnyKey::decor(const string & s, bool add) const
{
    return prefix(s, add, name.typ);
}

string AnyKey::prefix(const string & a, bool add, string pfx)
{
    auto sz = pfx.size();

    if ( add ) return pfx + deco::begin + a + deco::end;

    const string * ps = &a;
    string fs;

    if ( a.size() > 0 &&  a[0] == '@' )
    {
        fs = loadConst(pfx, a);
        ps = &fs;
    }

    const string & s = *ps;

    if ( s.size() <= sz || s.substr(0, sz) != pfx ) return "";

    if ( s.size() < 2 ) return "";
    if ( s[sz] != deco::begin || s[s.size() - 1] != deco::end ) return "";

    return s.substr(sz + 1, s.size() - 2 - sz);
}

} // e3
