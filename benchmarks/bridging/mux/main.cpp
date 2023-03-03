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

template <class T, class U> void run(const string & title, const vector<T> & v);

int main()
{
    high_resolution_clock::time_point timer;
    microseconds elapsed;

    // Plaintext
    {
        timer = high_resolution_clock::now();
        run<int,int>                          ("Plaintext ", vector<int>{ 3, 3, 2, 1 });
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // SecureUint
    {
        timer = high_resolution_clock::now();
        run<SecureUint<SIZE>,SecureUint<SIZE>>("SecureUint", vector<SecureUint<SIZE>>{ _3_E, _3_E, _2_E, _1_E });
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // Bridging-U
    {
        timer = high_resolution_clock::now();
        run<SecureUint<SIZE>,SecureMod>       ("Bridging-U", vector<SecureUint<SIZE>>{ _3_E, _3_E, _2_E, _1_E });
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // SecureInt
    {
        timer = high_resolution_clock::now();
        run<SecureInt<SIZE>,SecureInt<SIZE>>  ("SecureInt ", vector<SecureInt<SIZE>> { _3_E, _3_E, _2_E, _1_E });
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }

    // Bridging-S
    {
        timer = high_resolution_clock::now();
        run<SecureInt<SIZE>,SecureMod>        ("Bridging-S", vector<SecureInt<SIZE>> { _3_E, _3_E, _2_E, _1_E });
        elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
        cout << "Total time: " << scientificNotation(elapsed.count()) << " us\n";
    }
}

template <class T, class U>
void run(const string & title, const vector<T> & v)
{
    cout << '\n' << title << '\n';
    high_resolution_clock::time_point timer;
    microseconds elapsed;
    // print(v);
    timer = high_resolution_clock::now();
    auto r = mux<T,U>(v);
    elapsed = duration_cast<microseconds>(high_resolution_clock::now() - timer);
    // print(r);
    write(r);
    cout << "Time: " << scientificNotation(elapsed.count()) << " us\n";
}
