// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_OLC_H_
#define _E3_OLC_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <memory>

namespace e3
{
namespace cr
{
namespace ol
{

using istr = std::istringstream;
using ostr = std::ostringstream;
using vstr = std::vector<std::string>;

using ull = unsigned long long;
using sll = signed long long;

void cutline(std::string & line);
bool replaceAll(std::string & s, const std::string & r, const std::string & to);
std::string file2str(const std::string & file, bool silent = false);
void str2file(const std::string & file, const std::string & str);

template<typename T>
inline std::string tos(T x) { std::ostringstream o; o << x; return o.str(); }
template<typename T, typename U>
inline std::string tos(T x, const U & p, size_t sz = 0, char c = '0')
{
    std::ostringstream o; o << p << x;
    std::string r = o.str();
    while ( r.size() < sz ) r = c + r;
    return r;
}

template<typename T>
inline void merge(T & x, const T & y)
{
    std::sort(x.begin(), x.end());
    T t = y;
    std::sort(t.begin(), t.end());
    T z(x.size() + y.size());
    auto it =
        std::set_union(x.begin(), x.end(), t.begin(), t.end(), z.begin());
    z.resize(it - z.begin());
    x = z;
}

template <class T>
inline size_t x2st(T x) { return static_cast<size_t>( x ); }
template <class T> inline int x2i(T x) { return static_cast<int>( x ); }
inline int st2i(size_t x) { return static_cast<int>( x ); }

template <class V, class T>
inline bool isin(const V & v, const T & t)
{
    return (v.end() != std::find(v.begin(), v.end(), t));
}

inline void eatSpaces(std::string * ps)
{
    std::string & s = *ps;
    while ( !s.empty() && std::isspace(s[0]) ) s = s.substr(1);
    while ( !s.empty() && std::isspace(s[s.size() - 1]) )
        s = s.substr(0, s.size() - 1);
}

inline std::string eatSpaces(std::string s)
{
    std::string t = s;
    eatSpaces(&t);
    return t;
}

void toHex(const char * in, int inlen, char * out);
void toBin(const char * in, int inlen, char * out);
std::string toHex(const std::string & s);
std::string toBin(const std::string & s);

vstr str2vstr(const std::string & s, std::string delim);

template<typename T>
inline std::vector<T> vplus(const std::vector<T> & x, const std::vector<T> & y)
{
    std::vector<T> r;
    r.insert(r.end(), x.begin(), x.end());
    r.insert(r.end(), y.begin(), y.end());
    return r;
}

} // ol
} // cr
} // e3

// global stuff
template<typename T>
inline std::vector<T> operator+(const std::vector<T> & x, const std::vector<T> & y)
{
    return e3::cr::ol::vplus(x, y);
}

#define nevers(x) throw "err at "+e3::cr::ol::tos(__FILE__)+":"+e3::cr::ol::tos(__LINE__) + " ["+e3::cr::ol::tos(x)+"]";
#define never throw "err at "+e3::cr::ol::tos(__FILE__)+":"+e3::cr::ol::tos(__LINE__) + " ["+e3::cr::ol::tos(__func__)+"]";

#endif // _E3_OLC_H_
