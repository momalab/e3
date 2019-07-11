#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#ifndef SZ
#define SZ 8
#endif
#define MAX_ITER 10

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;

SecureInt fac(const SecureInt & input, size_t niter)
{
    SecureInt fact = _1_Ep;
    SecureInt    i = _1_Ep;
    SecureInt  res = _0_Ep;

    for ( ; niter--; i++ )
    {
        fact *= i;
        res += (i == input) * fact;
    }
    return res;
}

int main()
{
    SecureInt input = _5_Ep;
    Timer t;
    auto f = fac(input, MAX_ITER);
    auto r = t.get();
    // std::cout << f << '\n';
    cout << "Runtime: " << r << " us\n";
}
