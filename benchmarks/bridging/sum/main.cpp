#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include "e3int.h"
#include "../lib/io.hpp"
#include "../lib/size.hpp"
#include "bench.hpp"

using namespace std;
using namespace std::chrono;

template <class T> void run(const string & title, const vector<T> & v);

int main()
{
    run<int>             ("Plaintext ", vector<int>             {  3,    1,    2,    2   });
    run<SecureUint<SIZE>>("SecureUint", vector<SecureUint<SIZE>>{ _3_E, _1_E, _2_E, _2_E });
    run<SecureMod>       ("Bridging-U", vector<SecureMod>       { _3_M, _1_M, _2_M, _2_M });
    run<SecureInt<SIZE>> ("SecureInt ", vector<SecureInt<SIZE>> { _3_E, _1_E, _2_E, _2_E });
    run<SecureMod>       ("Bridging-S", vector<SecureMod>       { _3_M, _1_M, _2_M, _2_M });
}

template <class T>
void run(const string & title, const vector<T> & v)
{
    cout << '\n' << title << '\n';
    high_resolution_clock::time_point timer;
    microseconds elapsed;
    // print(v);
    timer = high_resolution_clock::now();
    auto r = sum<T>(v);
    elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
    // print(r);
    write(r);
    cout << "Time: " << scientificNotation(elapsed.count()) << " us\n";
}
