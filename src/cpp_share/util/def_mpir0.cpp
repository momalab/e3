// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include <sstream>

#include "e3util.h"
#include "def_mpir0.h"
#include "def_mpir.inc"

#include "e3math.h"
#include "e3math.inc"


int e3::mpir_impl() { return 0; }

int e3::Bigun::maxbitsz() { return 8 * sizeof(ull_t) - 1; }

e3::Bigun::Bigun(string s) : Bigun(0)
{
    std::istringstream is(s);
    is >> (*this);
}

std::istream & e3::operator>>(std::istream & is, Bigun & x)
{
    e3::util::ull z;
    is >> z;
    *x.p = z;
    return is;
}

static e3::util::ull mulmod(e3::util::ull a, e3::util::ull b, e3::util::ull m)
{
    if ( b == 0 ) return 0;
    if ( b == 1 ) return a % m;

    auto y = b / 2;
    auto c = a * 2 % m;
    auto z = mulmod(c, y, m);

    if ( !(b % 2) ) return z;

    return (z + a) % m;
}

static e3::util::ull powmod(e3::util::ull x, e3::util::ull p, e3::util::ull m)
{
    if ( p == 0 ) return 1;
    if ( p == 1 ) return mulmod(x, 1, m);
    if ( p == 2 ) return mulmod(x, x, m);

    auto y = powmod(x, p / 2, m);
    auto z = mulmod(y, y, m);

    if ( !(p % 2) ) return z;

    return mulmod(x, z, m);
}

static e3::util::ull invmod(e3::util::ull x, e3::util::ull m)
{
    e3::util::ull r;
    if ( e3::math::invert<e3::util::ull>(x % m, m, &r) ) return r;
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

bool e3::BigunNative::isZero() const { return n == 0; }

std::vector<uint32_t> e3::BigunNative::data(size_t nitems) const
{
    throw "Wrong MPIR implementation";
}

void e3::BigunNative::data(const std::vector<uint32_t> & a)
{
    throw "Wrong MPIR implementation";
}


