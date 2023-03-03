#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include "e3int.h"
#include "../lib/io.hpp"
#include "bench.hpp"

using namespace std;
using namespace std::chrono;

template <class T>
void run(const string & title, const T & x, int ntries);

int main()
{
    int ntries = 128;
    run<SecureUint< 1>>("SecureUint <1>", _1_E, ntries);
    run<SecureInt < 1>>("SecureInt  <1>", _1_E, ntries);
    run<SecureUint< 2>>("SecureUint <2>", _3_E, ntries);
    run<SecureInt < 2>>("SecureInt  <2>", _3_E, ntries);
    run<SecureUint< 4>>("SecureUint <4>", _7_E, ntries);
    run<SecureInt < 4>>("SecureInt  <4>", _7_E, ntries);
    run<SecureUint< 8>>("SecureUint <8>", _7_E, ntries);
    run<SecureInt < 8>>("SecureInt  <8>", _7_E, ntries);
    run<SecureUint<16>>("SecureUint<16>", _7_E, ntries);
    run<SecureInt <16>>("SecureInt <16>", _7_E, ntries);
    run<SecureUint<32>>("SecureUint<32>", _7_E, ntries);
    run<SecureInt <32>>("SecureInt <32>", _7_E, ntries);
}

template <class T>
void run(const string & title, const T & x, int ntries)
{
    cout << '\n' << title << '\n';
    high_resolution_clock::time_point timer;
    microseconds elapsed;
    // print(x);
    SecureMod r;
    timer = high_resolution_clock::now();
    for (int i=0; i<ntries; i++) r = to_SecureMod(x);
    elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
    // print(r);
    write(r);
    cout << "Time: " << scientificNotation(double(elapsed.count()) / ntries) << " us\n";
}
