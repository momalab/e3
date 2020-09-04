/*
This program finds the factorial of a packed ciphertexts
*/

#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#include "e3key.h"
template<class T> inline std::string de(T x) { return e3::decrypt<T>(x); }

#ifndef SZ
#define SZ 8
#endif
#define MAX_ITER 10 //max number of iterations for data-oblivious algorithm

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;
using SecureMint = TypeMint;

//Function for calculating factorial of packed ciphertext
template <class T, class U>
T fac(const U & input, size_t niter, const T & zero, const T & one)
{
    T fact = one;
    T ia = one;
    U ic = _1_Ep;
    T res = zero;

    for ( ; niter--; ++ia, ++ic)
    {
        fact *= ia;
        res += (ic == input) * fact;
    }

    return res;
}

template <class T>
void tmain(string name, const T & zero, const T & one)
{
    SecureInt input = _5_4_3_2_0_Ep;
    Timer t;
    auto f = fac<T>(input, MAX_ITER, zero, one);
    auto r = t.get();
    cout << "factorial: " << de(input) << " ! = " << de(f) << '\n';
    cout << name << " Runtime: " << r << " us\n";
}

int main()
try
{
    //Compare the runtimes of factorial with bridging
    tmain<SecureMint>("SecureMint", _0_Ea, _1_Ea);
    //... versus factorial with only bit-level arithmetic
    tmain<SecureInt>("SecureInt", _0_Ep, _1_Ep);
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
