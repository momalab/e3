// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <e3int.h>

template <class T>
T fib(const T & num, unsigned niter)
{
    T zero = num ^ num;
    T one = T(!zero);

    T f1 = zero;
    T f2 = one;
    T fi = zero;
    T i = one;
    T res = zero;

    for ( unsigned ctrl = 0 ; ctrl < niter ; ctrl++ )
    {
        res += (i == num) * fi;
        fi = f1 + f2;
        f1 = f2;
        f2 = fi;
        i++;
    }

    return res;
}
