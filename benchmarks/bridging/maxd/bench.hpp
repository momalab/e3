#pragma once

#include <vector>
#include "../lib/conversion.hpp"

template <class T, class U> std::vector<U> indices(const std::vector<T> & v);
template <class T, class U> U max(const std::vector<T> & v);
template <class U> U select(const std::vector<U> & idx, const std::vector<U> & v);

// create comparison matrix and add rows
template <class T, class U>
std::vector<U> indices(const std::vector<T> & v)
{
    int size = v.size();
    U u;
    std::vector<U> idx;
    std::vector<std::vector<U>> m(size);
    for (int i=0; i < size; i++)
    {
        for (int j=i+1; j < size; j++)
        {
            auto cond = v[i] > v[j]; // (size-1)^2 / 2 comparions
            m[i].push_back( convert(cond, u) );
            m[j].push_back( convert(!cond, u) );
        }
        idx.push_back( e3::util::product_inplace(m[i]) );
    }
    return idx;
}

template <class T, class U>
U max(const std::vector<T> & v)
{
    return select( indices<T,U>(v), convert(v, U()) );
}

template <class U>
U select(const std::vector<U> & idx, const std::vector<U> & v)
{
    // select items by index
    int size = v.size();
    std::vector<U> r;
    for (int i=0; i < size; i++) // for each index
        r.push_back(idx[i] * v[i]);
    return e3::util::sum_inplace(r);
}
