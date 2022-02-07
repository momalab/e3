// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <fstream>

#include "ek_pail.h"

using std::cout;

bool e3::PailEvalKey::load(string fname)
{
    std::ifstream in(fname, std::ios::binary);
    if (!in) return false;
    std::string s;

    in >> s;

    setN(Bigun(s));

    int b = 0;
    in >> b;
    if ( b ) setBeta(b);

    if (!in) return false;
    return true;
}

void e3::PailEvalKey::Processor::init(e3::Bigun n)
{
    N = n;
    if (N == Bigun(1))
        throw "N cannot be 1";

    beta = high_bit_posN = high_bit_posN2 = 0;
    N2 = A2 = B2 = Bigun(0);

    Bigun x = N - 1; // if N==0 - Ok;
    // -1 does not matter for N!=2^n
    // but splits in half when N==2^n

    while (x != Bigun(0)) { x >>= 1; high_bit_posN++; }
    high_bit_posN--;

    Xp1 = Bigun(2);
    Xp2 = Bigun(0) - 1;
    Xp2 >>= 1;

    if (N.isZero())
        return; // leave the rest undefined - 0's

    N = n;
    N2 = N * N;

    high_bit_posN2 = 0;
    x = N2;
    while ( x != Bigun(0) ) { x >>= 1; high_bit_posN2++; }
    high_bit_posN2--;

    unsigned nbit = 0;
    while ( (N >> Bigun(++nbit) ) != Bigun(1) );
    A2 = (Bigun(1) << Bigun(nbit));

    Bigun M = N - A2;

    if (M.isZero())
    {
        if (high_bit_posN > 1)
            setB2Beta(high_bit_posN - 1);
        else
        {
            // leave beta and B2 undefined - 0's
        }
    }
    else
    {
        nbit = 0;
        while ((M >> ++nbit ) > Bigun(1) );

        setB2Beta(nbit);

        if (B2 * 2 <= A2) {}
        else
            setB2Beta(nbit - 1);
    }

    Bigun tpmax = (Bigun(1) << high_bit_posN) - 1;
    Xp1 = N + 1;
    Xp2 = N * (tpmax + 1);
}

void e3::PailEvalKey::Processor::setB2Beta(int b)
{
    if (beta && b > beta)
    {
        std::cout << "Current beta " << beta << "; new value " << b << '\n';
        throw "Setting beta above predefined is forbidden; increase N";
    }

    if (N.isZero() && b > high_bit_posN / 2 )
    {
        std::cout << "Try setting beta " << b << ", but allowed value is " << (high_bit_posN / 2) << '\n';
        throw "Setting beta too high";
    }

    beta = b;
    B2 = (Bigun(1) << b);
}

string e3::PailEvalKey::Processor::show() const
{
    std::ostringstream os;
    os << "N=" << N << " N2=" << N2;
    os << " M=" << (N - A2) << " A2=" << A2;
    os << " B2=" << B2 << " beta=" << beta;
    os << " high_bit_posN=" << high_bit_posN;
    return os.str();
}

