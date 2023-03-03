#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include "e3int.h"
#include "../lib/io.hpp"
#include "bench.hpp"

#ifndef SIZE
#define SIZE 4
#endif

using namespace std;
using namespace std::chrono;

template <class T, class U, class V, class X>
void run(const string & title, const T & x, const T & unit, int t, int size, bool sign);

int main()
{
    SecureMod one = _1_M;
    int t = SecureMod::getPlaintextModulus();
    run<SecureMod,SecureUint<SIZE>,SecureUint<SIZE>,SecureBool>("SecureUint", _7_M, one, t, SIZE, false);
    run<SecureMod,SecureInt <SIZE>,SecureUint<SIZE>,SecureBool>("SecureInt ", _7_M, one, t, SIZE, true );
}

template <class T, class U, class V, class X>
void run(const string & title, const T & x, const T & unit, int t, int size, bool sign)
{
    cout << '\n' << title << '\n';
    high_resolution_clock::time_point timer;
    microseconds elapsed;
    // print(x);
    timer = high_resolution_clock::now();
    auto r = fromSecureMod<T,U,V,X>(x, unit, t, size, sign);
    elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
    // print(r);
    write(r);
    cout << "Time: " << scientificNotation(elapsed.count()) << " us\n";
}
