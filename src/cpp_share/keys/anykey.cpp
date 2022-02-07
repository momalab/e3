// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include "anykey.h"
#include "e3util.h"

using std::string;

namespace deco
{
char begin = '[';
char end = ']';
}

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
        fs = util::loadConst(pfx, a);
        ps = &fs;
    }

    const string & s = *ps;

    if ( s.size() <= sz || s.substr(0, sz) != pfx ) return "";

    if ( s.size() < 2 ) return "";
    if ( s[sz] != deco::begin || s[s.size() - 1] != deco::end ) return "";

    return s.substr(sz + 1, s.size() - 2 - sz);
}

} // e3
