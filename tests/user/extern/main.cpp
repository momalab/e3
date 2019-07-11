#include <iostream>
#include <string>
#include <vector>

#include "e3int.h"
#include "timer.h"
#include "gate_benchmark.h"
#include "circuit_benchmark.h"

using namespace std;

int main(int ac, char * av[])
try
{
    Timer t;

    // load eval key
    Cipherbit::init();

    // init zero and unit
    FBit();


    /** Benchmark Gates **/
    cout << "Testing gates:" << '\n';
    FBit a(*FBit::unit), b(*FBit::unit);

    // in microseconds
    unsigned gate_time = 100;
    for ( auto g : gates ){
        cout << gate_names[g] << " " << test<FBit>( g, a, b, gate_time ) << " us" << '\n';
    }

    /*
    auto c = SchemeBit::gate_nand(a, b);
    cout << "a = " << a.str() << '\n';
    cout << "b = " << b.str() << '\n';
    cout << "c = " << c.str() << '\n';
    */

    cout << '\n';

    /** Benchmark Circuits **/
    cout << "Testing aritmetic operations with circuits:" << '\n';
    FUint<8> xa, xb;

    // in microseconds
    unsigned circuit_time = 100;
    for ( auto op : operators ){
        cout << names[op] << " " << test<FUint<8>>( op, circuit_time ) << " us" << '\n';
    }

    /*
    auto t1 = t.get();
    cout << "xa+xb = " << (xa+xb).str() << '\n';
    auto t2 = t.get();
    cout << "Runtime: " << t2 - t1 << " us\n";
    */



}
catch (const char *e)
{
    cout << "Error: " << e << "\n";
}
catch (string e)
{
    cout << "Error: " << e << "\n";
}
catch (...)
{
    cout << "exception\n";
}
