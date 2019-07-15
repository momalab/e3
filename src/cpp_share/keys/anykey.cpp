#include "anykey.h"

namespace deco
{
char begin = '[';
char end = ']';
}

std::string e3::AnyKey::prefix(const std::string & s, bool add, std::string pfx)
{
    auto sz = pfx.size();

    if ( add ) return pfx + deco::begin + s + deco::end;

    if ( s.size() <= sz || s.substr(0, sz) != pfx ) return "";

    if ( s.size() < 2 ) return "";
    if ( s[sz] != deco::begin || s[s.size() - 1] != deco::end ) return "";

    return s.substr(sz + 1, s.size() - 2 - sz);
}

std::string e3::AnyKey::decor(const std::string & s, bool add) const
{
    ///auto nm = name.decor;
    ///if ( nm.empty() ) nm = name.enc;
    ///return prefix(s, add, nm);
    return prefix(s, add, name.typ);
    ///return prefix(s, add, name.decor);
}
