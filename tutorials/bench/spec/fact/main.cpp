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

template <class T>
T fac(const T & input, size_t niter, const T & zero, const T & one)
{
    T fact_in = one, fact_out;
    T i_in = one, i_out;
    T res_in = zero, res_out;

    while (niter--)
    {
        fact_round<SecureInt, SecureBit>(res_out, i_out, fact_out, input, res_in, i_in, fact_in);
        res_in = res_out;
        i_in = i_out;
        fact_in = fact_out;
    }

    return res_out;
}

template <class T>
void tmain(string name, const T & zero, const T & one)
{
    SecureInt input = _5_Ep;
    Timer t;
    auto f = fac<T>(input, MAX_ITER, zero, one);
    auto r = t.get();
    cout << "factorial: " << de(input) << " ! = " << de(f) << '\n';
    cout << name << " Runtime: " << r << " us\n";
}

int main()
try
{
    tmain<SecureInt> ( "SecureInt", _0_Ep, _1_Ep);
}
catch (string e)
{
    cout << "Oops: " << e << "\n";
    return 1;
}
catch (...)
{
    cout << "Oops ...\n";
    return 1;
}
