/*
#include <iostream>
#include <string>
#include <vector>

#include "e3int.h"
#include "timer.h"
*/

using namespace std;

const int MAX_IT = 10;

enum Operator { ADD = 0, DIV, MUL };
Operator operators[] = { ADD, DIV, MUL };
//string operation_names[] = { "ADD...", "DIV...", "MUL..." };
string operation_names[] = { "add", "div", "mul" };

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

template<class SI>
double test(Operator op, unsigned time)
{
    SI a = SI(_1_En);
    SI b = SI(_2_Ef);

    unsigned long long elapsed;
    unsigned cycleSize = MAX_IT, counter = 0;
    Timer t;
    while ( (elapsed = t.get()) < time )
    {
        switch (op)
        {
            case ADD : cycle_add (a, b); break;
            case DIV : cycle_div (a, b); break;
            case MUL : cycle_mul (a, b);
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
