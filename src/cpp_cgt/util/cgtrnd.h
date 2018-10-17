#pragma once

#include <functional>
#include <random>
#include <string>

using std::string;

namespace util
{
class Rnd
{
        string sseed;
        std::seed_seq sq;

        std::default_random_engine reng;
        std::uniform_real_distribution<double> rdist;
        std::uniform_int_distribution<int> idist;
        std::function<double()> rrnd;
        std::function<int()> irnd;

        // process empty to time random
        string fseed(const string & ss);

    public:
        Rnd(const string & seed);

        //double operator()() { return rrnd(); }
        int operator()() { return irnd(); }
};

} //util
