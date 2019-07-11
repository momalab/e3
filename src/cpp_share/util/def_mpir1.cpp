#include <sstream>

#include "e3util.h"
#include "def_mpir1.h"
#include "def_mpir.inc"

int mpir_impl() { return 1; }

int Bigun::maxbitsz() { return 10000000; } // enough

Bigun::Bigun(string s) : Bigun(0)
{
    p->n = s;
}

std::istream & operator>>(std::istream & is, Bigun & x)
{
    string s;
    is >> s;
    x.p->n = s;
    return is;
}

BigunNative & BigunNative::operator<<=(const BigunNative & a)
{
    unsigned long c = a.n.get_ui();
    while (c--) n = n * 2;
    return *this;
}

BigunNative & BigunNative::operator>>=(const BigunNative & a)
{
    unsigned long c = a.n.get_ui();
    while (c--) n = n / 2;
    return *this;
}


inline mpz_class mulmod(mpz_class a, mpz_class b, mpz_class m)
{
    return a * b % m;
}

mpz_class powmod(const mpz_class & x, const mpz_class & p, const mpz_class & m)
{
    if ( p == 0 ) return 1;
    if ( p == 1 ) return mulmod(x, 1, m);
    if ( p == 2 ) return mulmod(x, x, m);

    auto y = powmod(x, p / 2, m);
    auto z = mulmod(y, y, m);

    if ( (p % 2) == 0 ) return z;

    return mulmod(x, z, m);
}

string BigunNative::str() const { return n.get_str(); }

BigunNative BigunNative::powmod(BigunNative x, BigunNative m) const
{
    auto z = ::powmod(n, x.n, m.n);
    return BigunNative(z);
}

BigunNative BigunNative::mulmod(BigunNative x, BigunNative m) const
{
    return BigunNative(::mulmod(n, x.n, m.n));
}
