// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_E3UTIL_H_
#define _E3_E3UTIL_H_

#include <complex>
#include <cstdio>
#include <string>
#include <vector>

namespace e3
{
namespace util
{

using ull = unsigned long long;
using sll = signed long long;
using usi = unsigned short int;

ull hex2ull(std::string);
std::string ull2hex(ull);

constexpr inline bool bitAt(ull m, ull n) { return 0 != (m & (1ull << n)); }

constexpr inline ull mask(ull n)
{
    if ( n >= 8 * sizeof(1ull) ) return -1;
    return (1ull << n) - 1;
}

constexpr inline sll signExtend(sll m, ull n)
{
    if (!bitAt(m, n - 1)) return m;
    return m | ~mask(n);
}

inline bool isHex(char c) { return ( c >= '0' && c <= '9' ) || ( c >= 'a' && c <= 'f' ); }
bool isHex(const std::string & hex);

std::string bin2hex(const std::vector<bool> & bin);
std::vector<bool> hex2bin(const std::string & hex, size_t bitsize = 0);

std::string bin2sbn(const std::vector<bool> & bin);
std::vector<bool> sbn2bin(const std::string & sbn, size_t bitsize = 0);

unsigned hex2dec(char hex);
char hex2dec(char hex, bool * carry);
char dec2hex(unsigned dec);
std::string hex2dec(const std::string & hex, size_t bitsize = 0, bool sign = false);
std::string dec2hex(const std::string & dec, size_t bitsize);

bool isNegative(const std::string & hex, size_t bitsize);
std::string twosComplement(const std::string & hex, size_t bitsize);
std::string increment(const std::string & hex, size_t bitsize);
char negation(char hex);
std::string negation(const std::string & hex, size_t bitsize);
std::string add(const std::string & dec, unsigned value);
std::string multiply(const std::string & dec, unsigned value);
std::string removeLeadingZeros(const std::string & s);
char addHex(char hex1, char hex2, bool * carry = nullptr);
std::string divide(const std::string & dec, unsigned div);
unsigned mod(const std::string & dec, unsigned div);
char maskHex(char c, size_t bitsize);
std::string zeroExtension(const std::string & hex, size_t bitsize);

std::vector<std::string> split(const std::string & s, char c);

inline std::string to_string(const std::string & s) { return s; }
template <class T> inline std::string to_string(const std::complex<T> & s) { return std::to_string(s.real()) + "+" + std::to_string(s.imag()) + "i"; }
template <class T> inline std::string to_string(const T & s) { return std::to_string(s); }

template <class T>
inline std::string merge(const std::vector<T> & v, std::string bind)
{
    std::string s = "";
    if ( !v.empty() )
    {
        s += to_string(v[0]);
        for ( size_t i = 1; i < v.size(); i++ )
            s += bind + to_string(v[i]);
    }
    return s;
}

template <class T>
inline std::vector<T> extend(const std::vector<T> & v, size_t size, const T & value)
{
    std::vector<T> r;
    r.assign(v.begin(), v.end());
    r.resize(size, value);
    return r;
}

std::string trim(const std::string & s);
std::string loadConst(std::string typ, std::string id);

inline size_t msb(size_t n)
{
    size_t msb = 0;
    for (; n; n >>= 1 ) msb++;
    return msb;
}

template <class T>
inline T sum_inplace(std::vector<T> & v)
{
    auto size = v.size();
    for ( auto n = 1 << msb(size); n > 1; )
    {
        n >>= 1;
        for ( size_t i = n; i < size; i++ ) v[i - n] += v[i];
        size = n;
    }
    v.resize(1);
    return v[0];
}

template <class T>
inline T sum(const std::vector<T> & v)
{
    std::vector<T> vtmp;
    auto half = v.size() >> 1;
    for ( size_t i = 0; i < half; i++ ) vtmp.push_back( v[i] + v[i + half] );
    if ( v.size() & 1 ) vtmp.push_back( v.back() ); // if v.size is odd
    return sum_inplace(vtmp);
}

template <class T>
inline T product_inplace(std::vector<T> & v)
{
    auto size = v.size();
    for ( auto n = 1 << msb(size); n > 1; )
    {
        n >>= 1;
        for ( size_t i = n; i < size; i++ ) v[i - n] *= v[i];
        size = n;
    }
    v.resize(1);
    return v[0];
}

template <class T>
inline T product(const std::vector<T> & v)
{
    std::vector<T> vtmp;
    auto half = v.size() >> 1;
    for ( size_t i = 0; i < half; i++ ) vtmp.push_back( v[i] * v[i + half] );
    if ( v.size() & 1 ) vtmp.push_back( v.back() ); // if v.size is odd
    return product_inplace(vtmp);
}

} // util
} // e3


// using these macro during active development phase
#ifdef DEVMACROS
#define HALT throw std::string("\nFIX: ")+(__FILE__)+":"+std::to_string(__LINE__);
#define WARN std::printf("FIX: %s:%d\n", __FILE__, __LINE__);
#define MSGE(x) std::printf("FIX: %s\n", x);
#endif

#ifndef NOVERCHK
// === testing compiler versions
// test MS VERSION
#ifdef _MSC_VER
#if _MSC_VER < 1910
#error MS compiler version must be not less than 19.16
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
#endif // NOVERCHK

#endif // _E3_E3UTIL_H_
