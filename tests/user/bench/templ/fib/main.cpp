#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

using namespace std;

#ifndef SZ
#define SZ 32
#endif

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

int main()
{
    const unsigned niter = 10;
    SecureUint<SZ> numI = _7_E;
    Timer t;
    auto f = fib(numI, niter);
    auto r = t.get();
    // std::cout << f << '\n';
    cout << "Runtime: " << r << " us\n";
}
