#pragma once

#include <vector>
#include "../lib/conversion.hpp"

template <class T> std::vector<T> indices(const std::vector<T> & v);
template <class T, class U> std::vector<U> select(const std::vector<T> & idx, const std::vector<U> & v);
template <class T, class U> std::vector<U> sort(const std::vector<T> & v);

// create comparison matrix and add rows
template <class T>
std::vector<T> indices(const std::vector<T> & v)
{
    int size = v.size();
    std::vector<T> idx;
    std::vector<std::vector<T>> m(size);
    for (int i=0; i < size; i++)
    {
        for (int j=i+1; j < size; j++)
        {
            auto cond = v[i] > v[j]; // (size-1)^2 / 2 comparions
            m[i].push_back( T(cond) );
            m[j].push_back( T(!cond) );
        }
        idx.push_back( e3::util::sum_inplace(m[i]) );
    }
    return idx;
}

template <class T, class U>
std::vector<U> select(const std::vector<T> & idx, const std::vector<U> & v)
{
    // select items by index
    int size = v.size();
    std::vector<U> r;
    for (int i=0; i < size; i++) // for each index
    {
        std::vector<U> t;
        for (int j=0; j < size; j++ ) // for each element in v
            t.push_back( (T(i) == idx[j]) * v[j] );
        r.push_back( e3::util::sum_inplace(t) );
    }
    return r;
}

template <class T, class U>
std::vector<U> sort(const std::vector<T> & v)
{
    return select( indices(v), convert(v, U()) );
}
