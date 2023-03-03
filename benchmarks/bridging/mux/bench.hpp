#pragma once

#include <vector>
#include "../lib/conversion.hpp"

template <class T, class U>
U mux(const std::vector<T> & v)
{
    auto cond = v[0] == v[1];
    return cond * convert(v[2], U()) + !cond * convert(v[3], U());
}
