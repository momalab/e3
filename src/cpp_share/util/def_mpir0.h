// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_DEF_MPIR0_H_
#define _E3_DEF_MPIR0_H_

// this header def_mpir0.h should not be included in any code except *mpir0.cpp

#include "def_mpir.h"

namespace e3
{

struct BigunNative
{
    using ull_t = e3::util::ull;
    ull_t n;
    BigunNative(unsigned long long x = 0): n(x) {}

    string str() const;
    BigunNative powmod(BigunNative x, BigunNative m) const;
    BigunNative mulmod(BigunNative x, BigunNative m) const;
    BigunNative invmod(BigunNative m) const;

    bool isZero() const;

    BigunNative & operator+=(const BigunNative & a) { n += a.n; return *this; }
    BigunNative & operator-=(const BigunNative & a) { n -= a.n; return *this; }
    BigunNative & operator*=(const BigunNative & a) { n *= a.n; return *this; }
    BigunNative & operator/=(const BigunNative & a) { n /= a.n; return *this; }
    BigunNative & operator%=(const BigunNative & a) { n %= a.n; return *this; }
    BigunNative & operator&=(const BigunNative & a) { n &= a.n; return *this; }
    BigunNative & operator|=(const BigunNative & a) { n |= a.n; return *this; }
    BigunNative & operator^=(const BigunNative & a) { n ^= a.n; return *this; }
    BigunNative & operator<<=(const BigunNative & a) { n <<= a.n; return *this; }
    BigunNative & operator>>=(const BigunNative & a) { n >>= a.n; return *this; }

    BigunNative & operator++() { ++n; return *this; }
    BigunNative & operator--() { --n; return *this; }
    BigunNative operator~() const { return ~n; }
    BigunNative operator-() const { return 0ull - n; }

    bool operator==(const BigunNative & a) const { return n == a.n; }
    bool operator<(const BigunNative & a) const { return n < a.n; }

    ull_t ull() const { return n; }

    // CoPHEE
    std::vector<uint32_t> data(size_t nitems = 64) const;
    void data(const std::vector<uint32_t> &);
};

} // e3

#endif // _E3_DEF_MPIR0_H_
