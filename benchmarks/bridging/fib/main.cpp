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

template <class T, class U> void run(const string & title, const T & input, int max_iter, const T & t0, const U & u0, const U & u1);

int main()
{
    high_resolution_clock::time_point timer;
    microseconds elapsed;
    const int MAX = 32;

    // Plaintext
    {
        timer = high_resolution_clock::now();
        run<int,int>                          ("Plaintext ",  7  , MAX,  0 ,   0 ,   1  );
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // SecureUint
    {
        timer = high_resolution_clock::now();
        run<SecureUint<SIZE>,SecureUint<SIZE>>("SecureUint", _7_E, MAX, _0_E, _0_E, _1_E);
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // Bridging-U
    {
        timer = high_resolution_clock::now();
        run<SecureUint<SIZE>,SecureMod>       ("Bridging-U", _7_E, MAX, _0_E, _0_M, _1_M);
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // SecureInt
    {
        timer = high_resolution_clock::now();
        run<SecureInt<SIZE>,SecureInt<SIZE>>  ("SecureInt ", _7_E, MAX, _0_E, _0_E, _1_E);
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // Bridging-S
    {
        timer = high_resolution_clock::now();
        run<SecureInt<SIZE>,SecureMod>        ("Bridging-S", _7_E, MAX, _0_E, _0_M, _1_M);
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }
}

template <class T, class U>
void run(const string & title, const T & input, int max_iter, const T & t0, const U & u0, const U & u1)
{
    cout << '\n' << title << '\n';
    high_resolution_clock::time_point timer;
    microseconds elapsed;
    // print(input);
    timer = high_resolution_clock::now();
    auto r = fibonacci<T,U>(input, max_iter, t0, u0, u1);
    elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
    // print(r);
    write(r);
    cout << "Time: " << scientificNotation(elapsed.count()) << " us\n";
}
