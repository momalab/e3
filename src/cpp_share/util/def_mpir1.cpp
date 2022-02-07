// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <sstream>

#include "e3util.h"
#include "def_mpir1.h"
#include "def_mpir.inc"

int e3::mpir_impl() { return 1; }

int e3::Bigun::maxbitsz() { return 10000000; } // enough

e3::Bigun::Bigun(string s) : Bigun(0)
{
    p->n = s;
}

std::istream & e3::operator>>(std::istream & is, Bigun & x)
{
    string s;
    is >> s;
    x.p->n = s;
    return is;
}

e3::BigunNative & e3::BigunNative::operator<<=(const BigunNative & a)
{
    unsigned long c = a.n.get_ui();
    while (c--) n = n * 2;
    return *this;
}

e3::BigunNative & e3::BigunNative::operator>>=(const BigunNative & a)
{
    unsigned long c = a.n.get_ui();
    while (c--) n = n / 2;
    return *this;
}


static inline mpz_class mulmod(mpz_class a, mpz_class b, mpz_class m)
{
    return a * b % m;
}

static mpz_class powmod(const mpz_class & x, const mpz_class & p, const mpz_class & m)
{
    if ( p == 0 ) return 1;
    if ( p == 1 ) return mulmod(x, 1, m);
    if ( p == 2 ) return mulmod(x, x, m);

    auto y = powmod(x, p / 2, m);
    auto z = mulmod(y, y, m);

    if ( (p % 2) == 0 ) return z;

    return mulmod(x, z, m);
}

static inline mpz_class invmod(mpz_class a, mpz_class m)
{
    mpz_class rop;
    if ( mpz_invert (rop.get_mpz_t(), a.get_mpz_t(), m.get_mpz_t())  ) return rop;
    return mpz_class(0);
}

string e3::BigunNative::str() const { return n.get_str(); }

e3::BigunNative e3::BigunNative::powmod(BigunNative x, BigunNative m) const
{
    auto z = ::powmod(n, x.n, m.n);
    return BigunNative(z);
}

e3::BigunNative e3::BigunNative::mulmod(BigunNative x, BigunNative m) const
{
    return BigunNative(::mulmod(n, x.n, m.n));
}

e3::BigunNative e3::BigunNative::invmod(BigunNative m) const
{
    return BigunNative(::invmod(n, m.n));
}

bool e3::BigunNative::isZero() const
{
    return 0 == mpz_cmp_ui(n.get_mpz_t(), 0);
}

std::vector<uint32_t> e3::BigunNative::data(size_t nitems) const
{
    throw "Wrong MPIR implementation";
}

void e3::BigunNative::data(const std::vector<uint32_t> & a)
{
    throw "Wrong MPIR implementation";
}
