
#include <sstream>

#include "e3util.h"
#include "def_mpir0.h"
#include "def_mpir.inc"


int mpir_impl() { return 0; }

int Bigun::maxbitsz() { return 8 * sizeof(ull) - 1; }

Bigun::Bigun(string s) : Bigun(0)
{
    std::istringstream is(s);
    is >> (*this);
}

std::istream & operator>>(std::istream & is, Bigun & x)
{
    ull z;
    is >> z;
    *x.p = z;
    return is;
}

ull mulmod(ull a, ull b, ull m)
{
    if ( b == 0 ) return 0;
    if ( b == 1 ) return a % m;

    auto y = b / 2;
    auto c = a * 2 % m;
    auto z = mulmod(c, y, m);

    if ( !(b % 2) ) return z;

    return (z + a) % m;
}

ull powmod(ull x, ull p, ull m)
{
    if ( p == 0 ) return 1;
    if ( p == 1 ) return mulmod(x, 1, m);
    if ( p == 2 ) return mulmod(x, x, m);

    auto y = powmod(x, p / 2, m);
    auto z = mulmod(y, y, m);

    if ( !(p % 2) ) return z;

    return mulmod(x, z, m);
}

string BigunNative::str() const { return std::to_string(n); }

BigunNative BigunNative::powmod(BigunNative x, BigunNative m) const
{
    return BigunNative(::powmod(n, x.n, m.n));
}

BigunNative BigunNative::mulmod(BigunNative x, BigunNative m) const
{
    return BigunNative(::mulmod(n, x.n, m.n));
}
