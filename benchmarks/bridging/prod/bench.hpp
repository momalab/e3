#pragma once

#include <vector>
#include "../lib/conversion.hpp"

template <class T>
T product(const std::vector<T> & v)
{
    return e3::util::product(v);
}
