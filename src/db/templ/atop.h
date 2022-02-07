// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN atop.h

#include <complex>
#include <cstdio>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
#include <map>

#include "cgtshared.h"

namespace e3
{

template <class T, class N = T>
void initEvalKey(e3::KeyName name, T *& pek, T *& gpek);

// zero is necessary if FHE cannot do x-x
template <class T>
T multiply_by_ull(const T & x, unsigned long long u, const T * zero = nullptr);

template <class T>
T shiftL_by_ull(const T & x, unsigned long long u);

template <class T, class U, class K>
void init_by_ull(T & r, U & x, unsigned long long y,
                 const T & z, const T & u, const K * pek);

// CarryAdd is a switch which changes operation add.
// Normal operation add add all the bits of the arguments.
// When CarryAdd is on, add operation adds all bits except msb
// placing carryon in msb of the result.
// eg: a[5:0] and b[5:0] are two 6-bit numbers, c[5:0] is result
// CarryAdd operation adds a[4:0]+b[4:0]=c[4:0]
// and sets c[5] to carry of 5-bit addition.
// In CarryAdd case 33+17=18 because b100001+b010001=b010010
// but normally add 33+17=50 because b100001+b010001=b110010
struct CarryAdd
{
    CarryAdd();
    ~CarryAdd();
    static bool use;
    bool old;
};

} // e3

// === END atop.h
