#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
    cout << "Testing gates..." << '\n';
    FBit a(*FBit::unit), b(*FBit::unit);

    // in microseconds
    unsigned gate_time = 100;
    for ( auto g : gates )
    {
        //cout << gate_names[g] << " " << test<FBit>( g, a, b, gate_time ) << " us" << '\n';
        t.addTiming(gate_names[g], test<FBit>( g, a, b, gate_time ));
    }

    /*
    auto c = SchemeBit::gate_nand(a, b);
    cout << "a = " << a.str() << '\n';
    cout << "b = " << b.str() << '\n';
    cout << "c = " << c.str() << '\n';
    */

    /** Benchmark Circuits **/
    cout << "Testing circuits..." << '\n';

    // in microseconds
    unsigned circuit_time = 100;
    for ( auto op : operators )
    {
        //cout << operation_names[op] << " 8bit " << test<FUint<8>>( op, circuit_time ) << " us" << '\n';
        t.addTiming(operation_names[op] + "_8", test<FUint<8>>( op, circuit_time ));
    }

    for ( auto op : operators )
    {
        //cout << operation_names[op] << " 32bit " << test<FUint<32>>( op, circuit_time ) << " us" << '\n';
        t.addTiming(operation_names[op] + "_32", test<FUint<32>>( op, circuit_time ));
    }

    /*
    FUint<8> xa, xb;

    auto t1 = t.get();
    cout << "xa+xb = " << (xa+xb).str() << '\n';
    auto t2 = t.get();
    cout << "Runtime: " << t2 - t1 << " us\n";
    */

    cout << "Writing to file..." << '\n';
    std::ofstream myfile;
    myfile.open("../tests/user/extern/benchmark_result.txt", std::ios::trunc);
    myfile << t.jsonify();
    myfile.close();

}
catch (const char * e)
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
