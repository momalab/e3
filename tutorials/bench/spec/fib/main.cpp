#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"
#include "../circuits.inc"

#include "e3key.h"
template<class T> inline std::string de(T x) { return e3::decrypt<T>(x); }

#ifndef SZ
#define SZ 8
#endif
#define MAX_ITER 10

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;
using SecureBit  = TypeBit;

template <class T, class Bit>
T fib(const SecureInt & input, size_t niter, const T & zero, const T & one)
{
    T f1_in  = zero, f1_out;
    T fi_in  = one, fi_out;
    SecureInt  i_in   = _1_Ep, i_out;
    T res_in = zero, res_out;
    while ( niter-- )
    {
        fib_round<T, Bit>(res_out, i_out, fi_out, f1_out, input, res_in, i_in, fi_in, f1_in);
        res_in = res_out;
        i_in = i_out;
        fi_in = fi_out;
        f1_in = f1_out;
    }
    return res_out;
}

template <class T, class Bit>
void tmain(string name, const T & zero, const T & one)
{
    SecureInt input = _7_Ep;
    Timer t;
    auto f = fib<T, Bit>(input, MAX_ITER, zero, one);
    auto r = t.get();
    cout << "Fibo: " << de(input) << " -> " << de(f) << '\n';
    cout << name << " Runtime: " << r << " us\n";
}

int main()
{
    tmain<SecureInt, SecureBit>( "SecureInt", _0_Ep, _1_Ep);
}
