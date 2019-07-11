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

SecureInt fib(const SecureInt & input, size_t niter)
{
    SecureInt f1  = _0_Ep;
    SecureInt f2  = _1_Ep;
    SecureInt fi  = _0_Ep;
    SecureInt  i  = _1_Ep;
    SecureInt res = _0_Ep;
    for ( ; niter--; i++ )
    {
        res += (i == input) * fi;
        fi = f1 + f2;
        f1 = f2;
        f2 = fi;
    }
    return res;
}

int main()
{
    SecureInt input = _7_Ep;
    Timer t;
    auto f = fib(input, MAX_ITER);
    auto r = t.get();
    // std::cout << f << '\n';
    cout << "Runtime: " << r << " us\n";
}
