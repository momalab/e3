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

template <class T, class U> void run(const string & title, const vector<T> & v, const T & idx);

int main()
{
    high_resolution_clock::time_point timer;
    microseconds elapsed;

    // Plaintext
    {
        timer = high_resolution_clock::now();
        vector<int> v{
              0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
             16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
        };
        run<int,int>                          ("Plaintext ", v,  7  );
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // SecureUint
    {
        timer = high_resolution_clock::now();
        vector<SecureUint<SIZE>> v{
              _0_E,  _1_E,  _2_E,  _3_E,  _4_E,  _5_E,  _6_E,  _7_E,
              _8_E,  _9_E, _10_E, _11_E, _12_E, _13_E, _14_E, _15_E,
             _16_E, _17_E, _18_E, _19_E, _20_E, _21_E, _22_E, _23_E,
             _24_E, _25_E, _26_E, _27_E, _28_E, _29_E, _30_E, _31_E
        };
        run<SecureUint<SIZE>,SecureUint<SIZE>>("SecureUint", v, _7_E);
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // Bridging-U
    {
        timer = high_resolution_clock::now();
        vector<SecureUint<SIZE>> v{
              _0_E,  _1_E,  _2_E,  _3_E,  _4_E,  _5_E,  _6_E,  _7_E,
              _8_E,  _9_E, _10_E, _11_E, _12_E, _13_E, _14_E, _15_E,
             _16_E, _17_E, _18_E, _19_E, _20_E, _21_E, _22_E, _23_E,
             _24_E, _25_E, _26_E, _27_E, _28_E, _29_E, _30_E, _31_E
        };
        run<SecureUint<SIZE>,SecureMod>       ("Bridging-U", v, _7_E);
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // SecureInt
    {
        timer = high_resolution_clock::now();
        vector<SecureInt<SIZE>> v{
              _0_E,  _1_E,  _2_E,  _3_E,  _4_E,  _5_E,  _6_E,  _7_E,
              _8_E,  _9_E, _10_E, _11_E, _12_E, _13_E, _14_E, _15_E,
             _16_E, _17_E, _18_E, _19_E, _20_E, _21_E, _22_E, _23_E,
             _24_E, _25_E, _26_E, _27_E, _28_E, _29_E, _30_E, _31_E
        };
        run<SecureInt<SIZE>,SecureInt<SIZE>>  ("SecureInt ", v, _7_E);
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // Bridging-S
    {
        timer = high_resolution_clock::now();
        vector<SecureInt<SIZE>> v{
              _0_E,  _1_E,  _2_E,  _3_E,  _4_E,  _5_E,  _6_E,  _7_E,
              _8_E,  _9_E, _10_E, _11_E, _12_E, _13_E, _14_E, _15_E,
             _16_E, _17_E, _18_E, _19_E, _20_E, _21_E, _22_E, _23_E,
             _24_E, _25_E, _26_E, _27_E, _28_E, _29_E, _30_E, _31_E
        };
        run<SecureInt<SIZE>,SecureMod>        ("Bridging-S", v, _7_E);
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }
}

template <class T, class U>
void run(const string & title, const vector<T> & v, const T & idx)
{
    cout << '\n' << title << '\n';
    high_resolution_clock::time_point timer;
    microseconds elapsed;
    // print(v);
    timer = high_resolution_clock::now();
    auto r = search<T,U>(v, idx);
    elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
    // print(r);
    write(r);
    cout << "Time: " << scientificNotation(elapsed.count()) << " us\n";
}
