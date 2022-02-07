// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <string>

#include "func.h"
#include "fib.h"

#include "e3key.h"
template<class T> inline std::string dec(T x) { return e3::decrypt<T>(x); }
template<typename T> inline std::string decs(T x)
{
    return dec(x);
}

using std::cout;
using std::string;

void testCarry()
{
    cout << "Test carry on\n";

    e3::CarryAdd dummy;

    CplainInt<8> x = _129_Ecp, y = _100_Ecp;
    auto z = x + y;
    cout << "Cplain: " << dec(x) << " + " << dec(y) << " = " << dec(z) << '\n';
    cout << "Cplain: bitsum( " << decs(z) << " ) = " << decs(z.bitsum()) << '\n';

    cout << "Test carry off\n";
}

int main()
try
{
    testCarry();

    if (1)
    {
        cout << "Pil [ enc(1) ] = " << dec(Pil(Pil(_1_EP).str())) << '\n';
        cout << "Pil [ enc(-1) ] = " << decs(Pil(Pil(_1_EPn).str())) << '\n';
    }

    if (1)
    {
        Pil x = _101_EP, y = _100_EP, z = _12_EPn;
        cout << "Pil: " << dec(x) << " + " << dec(y) << " = " << dec(x + y) << '\n';
        cout << "Pil: " << decs(x) << " + " << decs(z) << " = " << decs(x + z) << '\n';
    }

    if (1)
    {
        cout << "Bug [ enc(1) ] = " << dec(Secure(Secure(_1_EN).str())) << '\n';
        cout << "Bug [ enc(-1) ] = " << decs(Secure(Secure(_1_ENn).str())) << '\n';
    }

    if (1)
    {
        NativeBool a(_1_EN), b(_1_EN);
        cout << "Test NativeBool op && = " << dec(a && b) << '\n';
        Secure x(_3_EN), y(_4_EN);
        cout << "Test Int*Enc = " << dec(2 * x) << '\n';
        cout << "Test mux = " << dec(a.mux(x, y)) << '\n';
    }

    if (1)
    {
        cout << "This must be [ enc(13) ] = " << dec(Secure(Secure(_13_EN).str())) << '\n';

        Secure x = _7_EN, y = _3_ENn;
        cout << "NativeInt<64>\t" << dec(x) << " + " << decs(y) << " = " << dec(x + y) << "\n";

        Secure2 a = _10_E2, b = _5_E2;
        cout << "Native2Int<16>\t" << dec(a) << " + " << dec(b) << " = " << dec(a + b) << "\n";
    }

    if (1)
    {
        CplainInt<8> x = _101_Ecp, y = _100_Ecp, z = _12_Ecpn;
        cout << "Cplain: " << dec(x) << " + " << dec(y) << " = " << dec(x + y) << '\n';
        cout << "Cplain: " << decs(x) << " + " << decs(z) << " = " << decs(x + z) << '\n';

        // CplainUint<8> xu = _101_Ecp, yu = _100_Ecp, zu = _12_Ecpn;
        // cout << "CplainU: " << dec(xu) << " + " << dec(yu) << " = " << dec(xu + yu) << '\n';
        // cout << "CplainU: " << dec(xu) << " + " << dec(zu) << " = " << dec(xu + zu) << '\n';
    }


    if (1)
    {
        using Sectfhe = CtfheInt<8>;
        cout << "This must be [ enc(14) ] = " << dec(Sectfhe(Sectfhe(_14_EtN).str())) << '\n';
        cout << "This must be [ enc(-4) ] = " << decs(Sectfhe(Sectfhe(_4_EtNn).str())) << '\n';

        Sectfhe x = _7_EtN, y = _3_EtNn;
        cout << "TFHE: " << dec(x) << " + " << decs(y) << " = " << decs(x + y) << "\n";
        Sectfhe tfib = fib(x, 10);
        cout << "TFHE<8> fib( " << dec(x) << " ) = " << dec(tfib) << "\n";
    }


    if (1)
    {
        unsigned niter = 50; // number of iterations
        NativeUint<32> nativeNum = _7_EN;
        NativeUint<32> nativeRes = fib(nativeNum, niter);
        cout << "NativeUint<32>\tfib( " <<  dec(nativeNum) << " ) = " << dec(nativeRes) << " \n";

        NativeInt<64> natiNum = _7_EN;
        NativeInt<64> natiRes = fib(natiNum, niter);
        cout << "NativeInt<64>\tfib( " <<  decs(natiNum) << " ) = " << decs(natiRes) << "\n";

        // Secure2 native2Num = _7_E2;

    }
}
//catch(...){ cout<<"ERR"; }
catch (int e)
{
    cout << " error (int): " << e << "\n";
    return 1;
}
catch (string e)
{
    cout << " error (str): " << e << "\n";
    return 1;
}
catch (const char * e)
{
    cout << " error (cc): " << e << "\n";
    return 1;
}
catch (...)
{
    cout << "Unknown exception\n";
    return 1;
}
