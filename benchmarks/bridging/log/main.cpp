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

template <class T, class U> void run(const string & title, vector<vector<T>> & inputs, const vector<vector<U>> & weights, const T & threshold, const vector<int> & tpos);

int main()
{
    high_resolution_clock::time_point timer;
    microseconds elapsed;

    // Plaintext
    {
        timer = high_resolution_clock::now();
        vector<vector<int>> inputs = {
            { 43, 58, 48, 10, 54, 40, 42, 41 },
            { 98, 46, 53, 59, 33, 24, 40, 51 },
            { 75, 25, 13, 51, 14, 48,  7, 55 },
            { 24, 18, 56, 24, 45, 11, 16, 42 }
        };
        vector<vector<int>> weights = {
            { 36, 26, 13, 22, 23 },
            { 51, 61, 59, 21, 22 },
            {  1, 38, 54, 40, 48 },
            { 51, 24, 10, 36, 37 },
            { 26, 40, 59, 43, 10 },
            { 26, 61, 34, 24, 55 },
            { 52,  8, 41, 30, 58 },
            { 36, 40, 26, 55, 30 },
            { 19, 28, 40, 44,  0 }
        };
        run<int,int>("Plaintext", inputs, weights, 63, vector<int>{0});
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // SecureUint
    {
        timer = high_resolution_clock::now();
        vector<vector<SecureUint<SIZE>>> inputs = {
            { _43_E, _58_E, _48_E, _10_E, _54_E, _40_E, _42_E, _41_E },
            { _98_E, _46_E, _53_E, _59_E, _33_E, _24_E, _40_E, _51_E },
            { _75_E, _25_E, _13_E, _51_E, _14_E, _48_E,  _7_E, _55_E },
            { _24_E, _18_E, _56_E, _24_E, _45_E, _11_E, _16_E, _42_E }
        };
        vector<vector<SecureUint<SIZE>>> weights = {
            { _36_E, _26_E, _13_E, _22_E, _23_E },
            { _51_E, _61_E, _59_E, _21_E, _22_E },
            {  _1_E, _38_E, _54_E, _40_E, _48_E },
            { _51_E, _24_E, _10_E, _36_E, _37_E },
            { _26_E, _40_E, _59_E, _43_E, _10_E },
            { _26_E, _61_E, _34_E, _24_E, _55_E },
            { _52_E,  _8_E, _41_E, _30_E, _58_E },
            { _36_E, _40_E, _26_E, _55_E, _30_E },
            { _19_E, _28_E, _40_E, _44_E,  _0_E }
        };
        run<SecureUint<SIZE>,SecureUint<SIZE>>("SecureUint", inputs, weights, _63_E, vector<int>{0});
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // Bridging-U
    {
        timer = high_resolution_clock::now();
        vector<vector<SecureUint<SIZE>>> inputs = {
            { _43_E, _58_E, _48_E, _10_E, _54_E, _40_E, _42_E, _41_E },
            { _98_E, _46_E, _53_E, _59_E, _33_E, _24_E, _40_E, _51_E },
            { _75_E, _25_E, _13_E, _51_E, _14_E, _48_E,  _7_E, _55_E },
            { _24_E, _18_E, _56_E, _24_E, _45_E, _11_E, _16_E, _42_E }
        };
        vector<vector<SecureMod>> weights = {
            { _36_M, _26_M, _13_M, _22_M, _23_M },
            { _51_M, _61_M, _59_M, _21_M, _22_M },
            {  _1_M, _38_M, _54_M, _40_M, _48_M },
            { _51_M, _24_M, _10_M, _36_M, _37_M },
            { _26_M, _40_M, _59_M, _43_M, _10_M },
            { _26_M, _61_M, _34_M, _24_M, _55_M },
            { _52_M,  _8_M, _41_M, _30_M, _58_M },
            { _36_M, _40_M, _26_M, _55_M, _30_M },
            { _19_M, _28_M, _40_M, _44_M,  _0_M }
        };
        run<SecureUint<SIZE>,SecureMod>("Bridging-U", inputs, weights, _63_E, vector<int>{0});
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // SecureInt
    {
        timer = high_resolution_clock::now();
        vector<vector<SecureInt<SIZE>>> inputs = {
            { _43_E, _58_E, _48_E, _10_E, _54_E, _40_E, _42_E, _41_E },
            { _98_E, _46_E, _53_E, _59_E, _33_E, _24_E, _40_E, _51_E },
            { _75_E, _25_E, _13_E, _51_E, _14_E, _48_E,  _7_E, _55_E },
            { _24_E, _18_E, _56_E, _24_E, _45_E, _11_E, _16_E, _42_E }
        };
        vector<vector<SecureInt<SIZE>>> weights = {
            { _36_E, _26_E, _13_E, _22_E, _23_E },
            { _51_E, _61_E, _59_E, _21_E, _22_E },
            {  _1_E, _38_E, _54_E, _40_E, _48_E },
            { _51_E, _24_E, _10_E, _36_E, _37_E },
            { _26_E, _40_E, _59_E, _43_E, _10_E },
            { _26_E, _61_E, _34_E, _24_E, _55_E },
            { _52_E,  _8_E, _41_E, _30_E, _58_E },
            { _36_E, _40_E, _26_E, _55_E, _30_E },
            { _19_E, _28_E, _40_E, _44_E,  _0_E }
        };
        run<SecureInt<SIZE>,SecureInt<SIZE>>("SecureInt", inputs, weights, _63_E, vector<int>{0});
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // Bridging-S
    {
        timer = high_resolution_clock::now();
        vector<vector<SecureInt<SIZE>>> inputs = {
            { _43_E, _58_E, _48_E, _10_E, _54_E, _40_E, _42_E, _41_E },
            { _98_E, _46_E, _53_E, _59_E, _33_E, _24_E, _40_E, _51_E },
            { _75_E, _25_E, _13_E, _51_E, _14_E, _48_E,  _7_E, _55_E },
            { _24_E, _18_E, _56_E, _24_E, _45_E, _11_E, _16_E, _42_E }
        };
        vector<vector<SecureMod>> weights = {
            { _36_M, _26_M, _13_M, _22_M, _23_M },
            { _51_M, _61_M, _59_M, _21_M, _22_M },
            {  _1_M, _38_M, _54_M, _40_M, _48_M },
            { _51_M, _24_M, _10_M, _36_M, _37_M },
            { _26_M, _40_M, _59_M, _43_M, _10_M },
            { _26_M, _61_M, _34_M, _24_M, _55_M },
            { _52_M,  _8_M, _41_M, _30_M, _58_M },
            { _36_M, _40_M, _26_M, _55_M, _30_M },
            { _19_M, _28_M, _40_M, _44_M,  _0_M }
        };
        run<SecureInt<SIZE>,SecureMod>("Bridging-S", inputs, weights, _63_E, vector<int>{0});
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }
}

template <class T, class U>
void run(const string & title, vector<vector<T>> & inputs, const vector<vector<U>> & weights, const T & threshold, const vector<int> & tpos)
{
    cout << '\n' << title << '\n';
    high_resolution_clock::time_point timer;
    microseconds elapsed;
    // print(inputs);
    timer = high_resolution_clock::now();
    auto r = logisticRegression<T, U>(inputs, weights, threshold, tpos);
    elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
    // print(r);
    write(r);
    cout << "Time: " << scientificNotation(elapsed.count()) << " us\n";
}
