#pragma once

/*
#include <iostream>
#include <string>
#include <vector>

#include "e3int.h"
#include "timer.h"
*/

using namespace std;

const int MAX_IT = 10;

enum Operator { ADD = 0, DIV, MUL, MUXLESS, MUXEQ };
Operator operators[] = { ADD, DIV, MUL, MUXLESS, MUXEQ };
//string operation_names[] = { "ADD...", "DIV...", "MUL..." };
string operation_names[] = { "add", "div", "mul", "mux_less", "mux_eq" };

template<class SI> inline void cycle_add (SI & a, SI & b)
{
    for (int i = 0; i < MAX_IT; i++) a += b;
}

template<class SI> inline void cycle_div (SI & a, SI & b)
{
    for (int i = 0; i < MAX_IT; i++) a /= b;
}

template<class SI> inline void cycle_mul (SI & a, SI & b)
{
    for (int i = 0; i < MAX_IT; i++) a *= b;
}

template<class SI> inline void cycle_mux_less (SI & a, SI & b, SI & c, SI & d)
{
    for (int i = 0; i < MAX_IT; i++) (a<b)*c+(!(a<b))*d;
}

template<class SI> inline void cycle_mux_eq (SI & a, SI & b, SI & c, SI & d)
{
    for (int i = 0; i < MAX_IT; i++) (a==b)*c+(!(a==b))*d;
}

template<class SI, class SI_1>
double test(Operator op, unsigned time)
{
    SI_1 x; x[0] = *FBit::zero;
    SI_1 y; y[0] = *FBit::unit;

    SI a(x);
    SI b(x);

    unsigned long long elapsed;
    unsigned cycleSize = MAX_IT, counter = 0;
    Timer t;
    while ( (elapsed = t.get()) < time )
    {
        switch (op)
        {
            case ADD : cycle_add (a, b); break;
            case DIV : cycle_div (a, b); break;
            case MUL : cycle_mul (a, b); break;
            case MUXLESS : cycle_mux_less (a, b, a, b); break;
            case MUXEQ : cycle_mux_eq (a, b, a, b);
        }
        counter++;
    }
    return double(elapsed) / counter / cycleSize;
}

/*
int main(int ac, char * av[])
try
{
    unsigned tim = 0; // us
    if ( ac > 1 ) tim = std::stoi(av[1]);

    if (tim)
    {
        cout << "\nbddN-8\n";
        {
            for ( auto op : operators )
                cout << names[op] << " " << test<BNUint<8>>( op, tim ) << '\n';
        }
        cout << "\nbddN-32\n";
        {
            for ( auto op : operators )
                cout << names[op] << " " << test<BNUint<32>>( op, tim ) << '\n';
        }
    }
}
catch (string e)
{
    cout << "Error: " << e << "\n";
}
catch (...)
{
    cout << "exception\n";
}
*/
