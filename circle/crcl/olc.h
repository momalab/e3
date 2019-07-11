#pragma once

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

using std::vector;
using std::string;
using std::cout;
using std::shared_ptr;

namespace ol
{

using istr = std::istringstream;
using ostr = std::ostringstream;
using vstr = vector<string>;

using ull = unsigned long long;
using sll = signed long long;

void cutline(string & line);
bool replaceAll(string & s, const string & r, const string & to);
string file2str(const string & file, bool silent = false);
void str2file(const string & file, const string & str);

template<typename T>
inline string tos(T x) { std::ostringstream o; o << x; return o.str(); }
template<typename T, typename U>
inline string tos(T x, const U & p, size_t sz = 0, char c = '0')
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

inline void eatSpaces(string * ps)
{
    string & s = *ps;
    while ( !s.empty() && std::isspace(s[0]) ) s = s.substr(1);
    while ( !s.empty() && std::isspace(s[s.size() - 1]) )
        s = s.substr(0, s.size() - 1);
}

inline string eatSpaces(string s)
{
    string t = s;
    eatSpaces(&t);
    return t;
}

void toHex(const char * in, int inlen, char * out);
void toBin(const char * in, int inlen, char * out);
string toHex(const string & s);
string toBin(const string & s);

vstr str2vstr(const string & s, string delim);

} // ol

template<typename T>
inline vector<T> operator+(const vector<T> & x, const vector<T> & y)
{
    vector<T> r;
    r.insert(r.end(), x.begin(), x.end());
    r.insert(r.end(), y.begin(), y.end());
    return r;
}

#define never(x) throw "bug at "+ol::tos(__FILE__)+":"+ol::tos(__LINE__) + " ["+ol::tos(x)+"]";

namespace bug // as of today gcc 4.9.2 cygwin does not have to_string
{
template <class T> inline string to_string(T x)
{ std::ostringstream os; os << x; return os.str(); }
inline int stoi(string s) { return std::atoi(s.c_str()); }
} // bug

#ifdef __CYGWIN__
using bug::to_string;
namespace std { inline int stoi(string s) { return bug::stoi(s); } }
#endif


// test MS VERSION
#ifdef _MSC_VER
#if _MSC_VER < 1910
#error MS compiler version must be not less than 1910
#endif
#endif

