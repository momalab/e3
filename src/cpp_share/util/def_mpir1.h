#ifndef _E3_DEF_MPIR1_H_
#define _E3_DEF_MPIR1_H_

// this header def_mpir1.h should not be included in any code except *mpir1.cpp

// MPIR headers
#include "mpir.h"
#include "mpirxx.h"
#include "gmp-impl.h"

// local headers
#include "def_mpir.h"

namespace e3
{

struct BigunNative
{
    mpz_class n;
    BigunNative( unsigned long long x = 0): n((unsigned long)x) {}
    BigunNative( mpz_class a ): n(a) {}

    string str() const;
    BigunNative powmod(BigunNative x, BigunNative m) const;
    BigunNative mulmod(BigunNative x, BigunNative m) const;
    BigunNative invmod(BigunNative m) const;

    BigunNative & operator+=(const BigunNative & a) { n += a.n; return *this; }
    BigunNative & operator-=(const BigunNative & a) { n -= a.n; return *this; }
    BigunNative & operator*=(const BigunNative & a) { n *= a.n; return *this; }
    BigunNative & operator/=(const BigunNative & a) { n /= a.n; return *this; }
    BigunNative & operator%=(const BigunNative & a) { n %= a.n; return *this; }
    BigunNative & operator&=(const BigunNative & a);
    BigunNative & operator|=(const BigunNative & a) { n |= a.n; return *this; }
    BigunNative & operator^=(const BigunNative & a);
    BigunNative & operator<<=(const BigunNative & a);
    BigunNative & operator>>=(const BigunNative & a);
    BigunNative operator++();
    BigunNative operator++(int);
    BigunNative operator--();
    BigunNative operator--(int);

    bool operator==(const BigunNative & a) const { return n == a.n; }
    bool operator<(const BigunNative & a) const { return n < a.n; }
};

} // e3

#endif // _E3_DEF_MPIR1_H_
