// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EULER_H_
#define _E3_EULER_H_

#include "olrnd.h"
#include "def_mpir.h"

const int TESTNPRIMES = 3;

namespace e3
{

namespace euler
{

Bigun prime(int lam, e3::cr::Rnd * rnd, Bigun skip);
bool isprime(Bigun x);
Bigun random(Bigun mod, e3::cr::Rnd * rnd);

template<class T> inline T gcd(T a, T b)
{
    if ( b == T(0) ) return a;
    return gcd(b, a % b);
}

} //euler
} // e3

#endif // _E3_EULER_H_
