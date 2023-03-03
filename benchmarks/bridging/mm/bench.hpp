#pragma once

#include <vector>
#include "../lib/conversion.hpp"

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
