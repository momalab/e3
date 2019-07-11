#pragma once

// this header def_mpir0.h should not be included in any code except *mpir0.cpp

#include "def_mpir.h"

using ull = unsigned long long;

struct BigunNative
{
    ull n;
    BigunNative(unsigned long long x = 0): n(x) {}

    string str() const;
    BigunNative powmod(BigunNative x, BigunNative m) const;
    BigunNative mulmod(BigunNative x, BigunNative m) const;

    BigunNative & operator+=(const BigunNative & a) { n += a.n; return *this; }
    BigunNative & operator-=(const BigunNative & a) { n -= a.n; return *this; }
    BigunNative & operator*=(const BigunNative & a) { n *= a.n; return *this; }
    BigunNative & operator/=(const BigunNative & a) { n /= a.n; return *this; }
    BigunNative & operator%=(const BigunNative & a) { n %= a.n; return *this; }
    BigunNative & operator&=(const BigunNative & a);
    BigunNative & operator|=(const BigunNative & a) { n |= a.n; return *this; }
    BigunNative & operator^=(const BigunNative & a);
    BigunNative & operator<<=(const BigunNative & a) { n <<= a.n; return *this; }
    BigunNative & operator>>=(const BigunNative & a) { n >>= a.n; return *this; }
    BigunNative operator++();
    BigunNative operator++(int);
    BigunNative operator--();
    BigunNative operator--(int);

    bool operator==(const BigunNative & a) const { return n == a.n; }
    bool operator<(const BigunNative & a) const { return n < a.n; }
};

