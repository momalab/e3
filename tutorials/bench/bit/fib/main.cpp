#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#include "e3key.h"
template<class T> inline std::string de(T x) { return e3::decrypt<T>(x); }

#ifndef SZ
#define SZ 8
#endif
#define MAX_ITER 10

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;

template <class T>
T fib(const SecureInt & input, size_t niter, const T & zero, const T & one)
{
    T f1  = zero;
    T f2  = one;
    T fi  = one;
    SecureInt  i   = _1_Ep;
    T res = zero;
    for ( ; niter--; i++ )
    {
        res += (i == input) * fi;
        fi = f1 + f2;
        f1 = f2;
        f2 = fi;
    }
    return res;
}

template <class T>
void tmain(string name, const T & zero, const T & one)
{
    SecureInt input = _7_Ep;
    Timer t;
    auto f = fib<T>(input, MAX_ITER, zero, one);
    auto r = t.get();
    cout << "Fibo: " << de(input) << " -> " << de(f) << '\n';
    cout << name << " Runtime: " << r << " us\n";
}

int main()
{
    tmain<SecureInt> ( "SecureInt", _0_Ep, _1_Ep);
}
