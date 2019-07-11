#include <iostream>
#include <string>

#include "e3int.h"
#include "fib.h"

using std::cout;
using std::string;
using Secure = NativeInt<64>;
//using Secure = NativeUint<32>;
using Secure2 = Native2Int<16>;

int main()
{
    // Simple operations
    {
        // NativeInt<64>
        // This must be [ enc(13) ] : ENCRYPTION_OF_13
        cout << "This must be [ enc(13) ] : " << Secure(Secure(_13_EN).str()) << '\n';

        // x + y = (x+y)
        Secure x = _7_EN, y = _3_ENn;
        cout << x << " + " << y << " = " << (x + y) << "\n";

        // Native2Int<16>
        // x + y = (a+b)
        Secure2 a = _10_E2, b = _5_E2;
        cout << a << " + " << b << " = " << (a + b) << "\n";
    }

    // Fibonacci
    {
        // NativeUint<32>
        // fib ( 7 ) = 13
        unsigned niter = 50; // number of iterations
        NativeUint<32> nativeNum = _7_EN;
        NativeUint<32> nativeRes = fib(nativeNum, niter);
        cout << "fib( " <<  nativeNum << " ) = " << nativeRes << " \n";

        // NativeInt<64>
        // fib ( 7 ) = 13
        NativeInt<64> natiNum = _7_EN;
        NativeInt<64> natiRes = fib(natiNum, niter);
        cout << "fib( " <<  natiNum << " ) = " << natiRes << "\n";
    }
}
