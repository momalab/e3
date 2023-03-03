#pragma once

#include <vector>
#include "e3int.h"

template <class T, class U> U convert(const T & v, U) { return U(v); }
template <class T> SecureMod convert(const T & e, SecureMod dummy) { return to_SecureMod(e); }
template <class T, class U> std::vector<T> convert(const std::vector<T> & v, U) { return v; }
template <class T> std::vector<SecureMod> convert(const std::vector<T> & v, SecureMod dummy);
template <class T, class U> std::vector<std::vector<T>> convert(const std::vector<std::vector<T>> & m, U) { return m; }
template <class T> std::vector<std::vector<SecureMod>> convert(const std::vector<std::vector<T>> & m, SecureMod dummy);
template <class T, class U> U sel(const std::vector<T> & v);

template <class T>
std::vector<SecureMod> convert(const std::vector<T> & v, SecureMod dummy)
{
    std::vector<SecureMod> u;
    for (auto & e : v) u.push_back( to_SecureMod(e) );
    return u;
}

template <class T>
std::vector<std::vector<SecureMod>> convert(const std::vector<std::vector<T>> & v, SecureMod dummy)
{
    SecureMod type;
    std::vector<std::vector<SecureMod>> u;
    for (auto & e : v) u.push_back( convert(e, type) );
    return u;
}

bool to_SecureBool(int c)
{
    return bool(c);
}

SecureBool to_SecureBool(SecureMod & c)
{
    return SecureBool( c.native() );
}
