#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#ifndef SZ
#define SZ 32
#endif
#define MAX_ITER 10

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;
using SecureMint = TypeMint;

SecureMint fac(const SecureInt & input, size_t niter)
{
    SecureMint  one = _1_Ea;
    SecureMint fact = _1_Ea;
    SecureMint   ia = _1_Ea;
    SecureInt    ic = _1_Ep;
    SecureMint  res = _0_Ea;

    for ( ; niter--; ic++, ia += one )
    {
        fact *= ia;
        res += (ic == input) * fact;
    }

    return res;
}

int main()
{
    SecureInt input = _5_Ep;
    Timer t;
    auto f = fac(input, MAX_ITER);
    auto r = t.get();
    cout << "factorial: " << f << '\n';
    cout << "Runtime: " << r << " us\n";
}
