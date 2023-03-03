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

template <class T> void run(const string & title, const vector<vector<T>> & m);

int main()
{
    {
        vector<vector<int>> m = {
            {3, 7, 1},
            {5, 9, 8},
            {6, 2, 4}
        };
        run<int>("Plaintext" , m);
    }

    {
        vector<vector<SecureUint<SIZE>>> m {
            {_3_E, _7_E, _1_E},
            {_5_E, _9_E, _8_E},
            {_6_E, _2_E, _4_E}
        };
        run<SecureUint<SIZE>>("SecureUint", m);
    }

    {
        vector<vector<SecureMod>> m {
            {_3_M, _7_M, _1_M},
            {_5_M, _9_M, _8_M},
            {_6_M, _2_M, _4_M}
        };
        run<SecureMod>("Bridging-U", m);
    }

    {
        vector<vector<SecureInt<SIZE>>> m {
            {_3_E, _7_E, _1_E},
            {_5_E, _9_E, _8_E},
            {_6_E, _2_E, _4_E}
        };
        run<SecureInt<SIZE>>("SecureInt", m);
    }

    {
        vector<vector<SecureMod>> m {
            {_3_M, _7_M, _1_M},
            {_5_M, _9_M, _8_M},
            {_6_M, _2_M, _4_M}
        };
        run<SecureMod>("Bridging-S", m);
    }
}

template <class T>
void run(const string & title, const vector<vector<T>> & m)
{
    cout << '\n' << title << '\n';
    high_resolution_clock::time_point timer;
    microseconds elapsed;
    // print(m);
    timer = high_resolution_clock::now();
    auto r = matrixMultiplication<T>(m, m);
    elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
    // print(r);
    write(r);
    cout << "Time: " << scientificNotation(elapsed.count()) << " us\n";
}
