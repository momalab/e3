#pragma once

#include <vector>
#include "../lib/conversion.hpp"

template <class T, class U>
U search(const std::vector<T> & v, const T & idx)
{
    U u;
    std::vector<U> r;
    for (size_t i=0; i < v.size(); i++)
        r.push_back( (T(i) == idx) * convert(v[i], u) );
    return e3::util::sum_inplace(r);
}
