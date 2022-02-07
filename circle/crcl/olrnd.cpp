// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <iostream>
#include <chrono>

#include "olrnd.h"

#include "using.h"

Rnd::Typ Rnd::use = Rnd::Cpp;

Rnd * Rnd::newRnd(const string & seed)
{
    if ( use == Cpp ) return new RndCpp(seed);
    if ( use == Kiss ) return new RndKiss(seed);
    nevers("Bad Rnd type");
}


ol::ull RndKiss::hash(const std::string & s)
{
    ol::ull r = 0;
    auto sz = s.size();
    if ( sz < 1 ) return r;
    if ( sz < 2 ) return s[0];
    for ( size_t i = 1; i < sz; i++ ) r += s[i - 1] * 1023 + s[i] * s[i - 1] * 17;
    return r;
}

RndKiss::RndKiss(const std::string & sd) : RndKiss(hash(sd))
{
    if (0) // Warn about Kiss
    {
        static bool msg = false;
        if ( !msg ) std::cout << "Random number generator is RndKiss\n";
        msg = true;
    }
}


RndCpp::RndCpp(const string & ss) :
    sseed(fseed(ss)), sq(sseed.begin(), sseed.end()),
    reng(sq), rdist(0, 1), idist(),
    rrnd( std::bind(rdist, reng) ), irnd( std::bind(idist, reng) )
{}

string RndCpp::fseed(const string & ssd)
{
    if ( !ssd.empty() ) return ssd;
    auto now = std::chrono::system_clock::now();
    return std::to_string(std::chrono::system_clock::to_time_t(now));
}

ol::ull RndCpp::nextull()
{
    ol::ull r = 0;
    for ( int i = 0; i < 12; i++ )
    {
        r <<= 8;
        r ^= ol::ull(next());
    }
    return r;
}

