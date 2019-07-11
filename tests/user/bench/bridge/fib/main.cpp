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

SecureMint fib(const SecureInt & input, size_t niter)
{
    SecureMint f1  = _0_Ea;
    SecureMint f2  = _1_Ea;
    SecureMint fi  = _0_Ea;
    SecureInt  i   = _1_Ep;
    SecureMint res = _0_Ea;
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
