#pragma once

#include <vector>
#include "../lib/conversion.hpp"

template <class T>
T sum(const std::vector<T> & v)
{
    return e3::util::sum(v);
}
