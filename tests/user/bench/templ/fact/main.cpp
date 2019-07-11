#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

using namespace std;

#ifndef SZ
#define SZ 32
#endif

template <class T>
T fac(const T & num, unsigned niter)
{
    T zero = num ^ num;
    T one = T(!zero);

    T fact = one;
    T i = one;
    T res = zero;

    for ( unsigned ctrl = 0 ; ctrl < niter ; ctrl++ )
    {
        fact *= i;
        res += (i == num) * fact;
        i++;
    }

    return res;
}

int main()
{
    const unsigned niter = 10;
    SecureUint<SZ> numI = _5_E;
    Timer t;
    auto f = fac(numI, niter);
    auto r = t.get();
    // std::cout << f << '\n';
    cout << "Runtime: " << r << " us\n";

}
