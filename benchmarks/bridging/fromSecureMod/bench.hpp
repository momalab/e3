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

template <class M, class I, class B>
I fromSecureMod_toSecureUint(const M & x, const M & unit, int t)
{
    std::vector<I> v;
    for (int i=0; i<t; i++)
    {
        auto si = I(i);
        auto eq = unit - pow(x-i, t-1, unit);
        v.push_back( si * to_SecureBool(eq) );
    }
    return e3::util::sum(v);
}

template <class M, class I, class U, class B>
I fromSecureMod_toSecureInt(const M & x, const M & unit, int t, int s)
{
    auto u = fromSecureMod_toSecureUint<M,U,B>(x, unit, t);
    I pos(u);
    auto max = 1 << s;
    auto diff = max - t;
    u = fromSecureMod_toSecureUint<M,U,B>(x + diff, unit, t);
    I neg(u);
    // if (depthOptimized)
    // {
    //     u = fromSecureMod_toSecureUint<M,U,B>(x + diff, unit, t);
    //     neg = I(u);
    // }
    // else neg = I(max - t) + pos;
    auto isNeg = B(pos[s-1]);
    return isNeg * neg + !isNeg * pos;
}

template <class M, class I, class U, class B>
I fromSecureMod(const M & x, const M & unit, int t, int size, bool sign)
{
    return sign
        ? fromSecureMod_toSecureInt <M,I,U,B>(x, unit, t, size)
        : fromSecureMod_toSecureUint<M,I,B>(x, unit, t);
}
