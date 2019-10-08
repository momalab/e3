
#include <sstream>

#include "e3util.h"
#include "def_mpir0.h"
#include "def_mpir.inc"

#include "e3math.h"
#include "e3math.inc"


int e3::mpir_impl() { return 0; }

int e3::Bigun::maxbitsz() { return 8 * sizeof(ull) - 1; }

e3::Bigun::Bigun(string s) : Bigun(0)
{
    std::istringstream is(s);
    is >> (*this);
}

std::istream & e3::operator>>(std::istream & is, Bigun & x)
{
    e3util::ull z;
    is >> z;
    *x.p = z;
    return is;
}

static e3util::ull mulmod(e3util::ull a, e3util::ull b, e3util::ull m)
{
    if ( b == 0 ) return 0;
    if ( b == 1 ) return a % m;

    auto y = b / 2;
    auto c = a * 2 % m;
    auto z = mulmod(c, y, m);

    if ( !(b % 2) ) return z;

    return (z + a) % m;
}

static e3util::ull powmod(e3util::ull x, e3util::ull p, e3util::ull m)
{
    if ( p == 0 ) return 1;
    if ( p == 1 ) return mulmod(x, 1, m);
    if ( p == 2 ) return mulmod(x, x, m);

    auto y = powmod(x, p / 2, m);
    auto z = mulmod(y, y, m);

    if ( !(p % 2) ) return z;

    return mulmod(x, z, m);
}

static e3util::ull invmod(e3util::ull x, e3util::ull m)
{
    e3util::ull r;
    if ( e3::math::invert<e3util::ull>(x, m, &r) ) return r;
    return 0;
}

string e3::BigunNative::str() const { return std::to_string(n); }

e3::BigunNative e3::BigunNative::powmod(BigunNative x, BigunNative m) const
{
    return BigunNative(::powmod(n, x.n, m.n));
}

e3::BigunNative e3::BigunNative::mulmod(BigunNative x, BigunNative m) const
{
    return BigunNative(::mulmod(n, x.n, m.n));
}

e3::BigunNative e3::BigunNative::invmod(BigunNative m) const
{
    return BigunNative(::invmod(n, m.n));
}
