#pragma once

#include <vector>
#include "../lib/conversion.hpp"

template <class T> T pow(const T & b, int e, const T & unit)
{
    if (e == 0) return unit;
    if (e == 1) return b;
    auto r = pow(b * b, e >> 1, unit);
    if (e & 1) r *= b;
    return r;
}
