#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "e3int.h"
#include "timer.h"
#include "../alice.h"

using namespace std;


using SecureInt = PilcUint<8>;
using SecureMod = Pilm;

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

int main(int ac, char * av[])
try
{
#ifdef FIBO
    SecureInt inp = _7_Eu;
    std::cout << "fibo_m( " << dec(inp,"Pilc") << " ) = " << dec(fibo_m(inp),"Pilm") << '\n' ;
    std::cout << "fibo_c( " << dec(inp,"Pilc") << " ) = " << dec(fibo_c(inp),"Pilc") << '\n' ;

    tim(inp, 12, fibo_m);
    tim(inp, 4, fibo_c);
#endif

    SecureMod x = _3_Em;
    SecureInt y = _13_Eu;
    std::cout << "Pilm      = " << dec(x,"Pilm") << '\n' ;
    std::cout << "PilcUint8 = " << dec(y,"Pilc") << '\n' ;

    Pilm b = to_Pilm(y);
    cout << "to_Pilm(13) = " << dec(to_Pilm(y),"Pilm") << '\n';

    Pilmd x2 = _3_Emd;
    PilcdUint<8> y2 = _13_Eud;
    std::cout << "Pilmd      = " << dec(x2) << '\n' ;
    std::cout << "PilcdUint8 = " << dec(y2) << '\n' ;

}
catch (string e)
{
    cout << "Error: " << e << "\n";
}
catch (...)
{
    cout << "exception\n";
}
