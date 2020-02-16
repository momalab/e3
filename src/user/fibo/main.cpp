#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "e3int.h"

#define USETIMER 1

#ifdef USETIMER
#include "timer.h"
#endif

#include "e3key.h"
template<class T> inline std::string de(T x) { return e3::decrypt<T>(x); }

using namespace std;


using SecureInt = PilcUint<8>;
using SecureMod = Pilm;


#ifndef USETIMER
struct Timer{ int get(){ return 0; } };
#endif


#define FIBO
#ifdef FIBO

SecureMod fibo_m(SecureInt input)
{
    int max_iter = 30;
    SecureInt i = _1_Eu;
    SecureMod result = _0_Em;
    SecureMod a = _1_Em, b = _1_Em;

    while ( ++i, max_iter-- )
    {
        result += (i == input) * a;
        std::swap(a, b);
        a += b;
    }

    return result;
}

SecureInt fibo_c(SecureInt input)
{
    int max_iter = 30;
    SecureInt i = _1_Eu;
    SecureInt result = _0_Eu;
    SecureInt a = _1_Eu, b = _1_Eu;

    while ( ++i, max_iter-- )
    {
        result += (i == input) * a;
        std::swap(a, b);
        a += b;
    }

    return result;
}


template<typename F>
void tim(SecureInt inp, int sz, F f)
{
    Timer t;
    for ( int i = 0; i < sz; i++ ) (*f)(inp);
    auto z = t.get() / 1000.0;
    std::cout << "Timer (" << z << '/' << sz << "): " << z / sz << " ms\n" ;
}

#endif

void testMul()
{
    PilcInt<8> a(2), b(3);
    std::cout << "2*3= " << de(a*b) << '\n';
}

int main(int ac, char * av[])
try
{
    testMul();

#ifdef FIBO
    SecureInt inp = _7_Eu;
    std::cout << "fibo_m( " << de(inp) << " ) = " << de(fibo_m(inp)) << '\n' ;
    std::cout << "fibo_c( " << de(inp) << " ) = " << de(fibo_c(inp)) << '\n' ;

    tim(inp, 3, fibo_m);
    tim(inp, 1, fibo_c);
#endif

    SecureMod x = _3_Em;
    SecureInt y = _13_Eu;
    std::cout << "Pilm      = " << de(x) << '\n' ;
    std::cout << "PilcUint8 = " << de(y) << '\n' ;

    Pilm b = to_Pilm(y);
    cout << "to_Pilm(13) = " << de(to_Pilm(y)) << '\n';

    Pilmd x2 = _3_Emd;
    PilcdUint<8> y2 = _13_Eud;
    std::cout << "Pilmd      = " << de(x2) << '\n' ;
    std::cout << "PilcdUint8 = " << de(y2) << '\n' ;
    std::cout << "Pilmd (x3) = " << de(3 * x2) << '\n' ;

    std::cout << "Invert (3in5) = " << (e3::Bigun(3).invmod(5)) << '\n' ;
    std::cout << "Invert (17in100) = " << (e3::Bigun(17).invmod(100)) << ", 17*53=" << (17 * 53) << '\n' ;

    std::cout << "Uint8 y = " << de(y2) << " (y<<2)=" << de(y2 << 2) << '\n' ;
    std::cout << "Uint8 y = " << de(y2) << " (y>>2)=" << de(y2 >> 2) << '\n' ;

    std::cout << "Encryptions:";
    for ( int i = 0; i < 10; i++ ) std::cout << ' ' << de(PilcdUint<8>(i));
    std::cout << '\n' ;
}
catch (string e)
{
    cout << "Error: " << e << "\n";
}
catch (...)
{
    cout << "exception\n";
}
