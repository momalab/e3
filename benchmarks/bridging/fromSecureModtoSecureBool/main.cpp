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
void run(const string & title, const T & x, const T & unit, int t);

int main()
{
    SecureMod one = _1_M;
    // int t = SecureMod::getPlaintextModulus();
    for (int e=1; e<=16; e++)
    {
        int t = 1<<e;
        run<SecureMod>("SecureBool", _7_M, one, t);
    }
}

template <class T>
void run(const string & title, const T & x, const T & unit, int t)
{
    cout << '\n' << title << " :: " << t << '\n';
    high_resolution_clock::time_point timer;
    microseconds elapsed;
    // print(x);
    timer = high_resolution_clock::now();
    auto r = pow(x, t, unit);
    elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
    // print(r);
    write(r);
    cout << "Time: " << scientificNotation(elapsed.count()) << " us\n";
}
