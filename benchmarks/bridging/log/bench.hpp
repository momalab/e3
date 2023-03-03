#pragma once

#include <vector>
#include "../lib/conversion.hpp"

template <class T> std::vector<std::vector<T>> appendColumn(std::vector<std::vector<T>> & m, const T & value);
template <class T> std::vector<std::vector<T>> filter(std::vector<std::vector<T>> & m, const T & threshold, const std::vector<int> & pos);
template <class T> std::vector<std::vector<T>> matrixMultiplication(const std::vector<std::vector<T>> & a, const std::vector<std::vector<T>> & b);
template <class T, class U> std::vector<std::vector<U>> logisticRegression(std::vector<std::vector<T>> & inputs, const std::vector<std::vector<U>> & weights, const T & threshold, const std::vector<int> & pos);

template <class T> std::vector<std::vector<T>>
appendColumn(std::vector<std::vector<T>> & m, const T & value)
{
    for (auto & v : m) v.push_back(value);
    return m;
}

template <class T>
std::vector<std::vector<T>> filter(std::vector<std::vector<T>> & m, const T & threshold, const std::vector<int> & pos)
{
    for (auto & idx : pos)
    {
        for (auto & v : m)
        {
            auto cond = v[idx] > threshold;
            v[idx] = cond * threshold + !cond * v[idx];
        }
    }
    return m;
}

template <class T> std::vector<std::vector<T>>
matrixMultiplication(const std::vector<std::vector<T>> & a, const std::vector<std::vector<T>> & b)
{
    auto n = a.size();
    auto m = b.size();
    auto p = b[0].size();
    std::vector<std::vector<T>> c(n);
    for (size_t i=0; i<n; i++)
    {
        for (size_t j=0; j<p; j++)
        {
            std::vector<T> t;
            for (size_t k=0; k<m; k++)
                t.push_back(a[i][k] * b[k][j]);
            c[i].push_back( e3::util::sum_inplace(t) );
        }
    }
    return c;
}

template <class T, class U> std::vector<std::vector<U>>
logisticRegression(std::vector<std::vector<T>> & inputs, const std::vector<std::vector<U>> & weights, const T & threshold, const std::vector<int> & pos)
{
    U one(1);
    filter(inputs, threshold, pos);
    auto inputsU = convert(inputs, one);
    appendColumn(inputsU, one);
    return matrixMultiplication(inputsU, weights);
}
