#pragma once

#include <string>

namespace e3util
{
using ull = unsigned long long;
using sll = signed long long;
using usi = unsigned short int;

ull hex2ull(std::string);
std::string ull2hex(ull);

// used inline version because VS2015 v19.00 does not allow if inside constexpr
// later update compiler and change to constexpr version
//constexpr ull mask(ull n) { if ( n >= 8 * sizeof(1ull) ) return -1; return (1ull << n) - 1; }
inline bool bitAt(ull m, ull n)
{
    return 0 != (m & (1ull << n));
}

inline ull mask(ull n)
{
    if ( n >= 8 * sizeof(1ull) ) return -1;
    return (1ull << n) - 1;
}

inline sll signExtend(sll m, ull n)
{
    if (!bitAt(m, n - 1)) return m;
    return m | ~mask(n);
}

} // e3util

// using this macro during active development phase
#define FIX throw std::string("\nFIX ")+(__FILE__)+":"+std::to_string(__LINE__);

// === testing compiler versions
// test MS VERSION
#ifdef _MSC_VER
#if _MSC_VER < 1900
#error MS compiler version must be not less than 19.00
#endif
#endif
// test GCC version
#ifdef __GNUC__
#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#if GCC_VERSION < 50400
#error GCC compiler version must be not less than 5.4.0
#endif
#endif
// === END testing compiler versions
