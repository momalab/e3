#pragma once

#include <vector>
#include "../lib/conversion.hpp"

template <class T, class U>
U fibonacci(const T & input, int max_iter, const T & t0, const U & u0, const U & u1)
{
    T i = t0;
    U a = u0, b = u1;
    std::vector<U> r;
    while ( max_iter-- )
    {
        r.push_back( (i++ == input) * a );
        std::swap(a,b);
        a += b;
    }
    return e3::util::sum_inplace(r);
}
