#pragma once

//#include <iostream>
#include <chrono>

using namespace std;

Cipherbit newbit(int zu, double dur)
{
    Cipherbit a;
    auto b = ::gate_nand(a, a); // a!=b
    auto u = ::gate_nand(a, b);
    auto z = ::gate_not(u);

    // mix
    double span = 0;
    while (span < dur)
    {
        using namespace std::chrono;

        steady_clock::time_point t1 = steady_clock::now();

        Cipherbit c;
        auto x = ::gate_nand(u, c); // !c
        u = ::gate_nand(x, c);
        z = ::gate_not(u);

        steady_clock::time_point t2 = steady_clock::now();

        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

        span += time_span.count();
    }

    return zu ? u : z;
}

double g_tpu; // time per unit
string g_seed; // randomness
int g_pos = 0;
Cipherbit newbit(int zu)
{
    if ( ++g_pos >= (int)g_seed.size() ) g_pos = 0;
    auto dur = g_tpu * (int)(unsigned char)(g_seed[g_pos]);
    return newbit(zu, dur);
}

/*
int main(int ac, char * av[])
// secret, seedstr, timeperunit_ms
try
{
    // load eval key
    Cipherbit::init();

    if ( ac < 4 )
    {
        cout << "Usage: encstr secret seedstr TimePerUnit_ms\n";
        return 0;
    }

    string secret = av[1];
    g_seed = av[2];
    g_tpu = std::stod(string(av[3])) / 1000.0;

    for ( char c : secret )
    {
        for ( int i = 0; i < 8; i++ )
            cout << newbit( 1 & (c >> i) ).str() << '\n';
    }

}
catch (string e)
{
    cout << "Error: " << e << "\n";
    return 1;
}
catch (...)
{
    cout << "exception\n";
    return 1;
}
*/
