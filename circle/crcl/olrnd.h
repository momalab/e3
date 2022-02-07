// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_OLRND_H_
#define _E3_OLRND_H_

#include <functional>
#include <random>
#include <string>

#include "olc.h"

namespace e3
{
namespace cr
{

using std::string;

class Rnd
{
    public:
        enum Typ { Kiss, Cpp };
        static Typ use;
        static Rnd * newRnd(const std::string & seed);

        virtual int next() = 0;
        virtual ol::ull nextull() = 0;
        int operator()() { return next(); }
        virtual ~Rnd() {}
};

// cross platform generator - not reliiable
class RndKiss : public Rnd
{
        union U
        {
            ol::ull z[2];
            struct Kiss
            {
                uint32_t a, b, c, d;
                uint32_t cycle()
                {
                    a = (a & 0xFFFF) * 36969 + (a >> 16);
                    b = (b & 0xFFFF) * 18000 + (b >> 16);
                    c = c * 69069 + 1234567;
                    d ^= d << 13;  d ^= d >> 17;  d ^= d << 5;
                    return (((a << 16) | (b & 0xFFFF)) ^ c) + d;
                }
            } k;
        } u;

        ol::ull hash(const std::string & s);

    public:
        void seed(ol::ull x) { u.z[0] = u.z[1] = x; }
//        Rnd(ull x) { seed(x); }
        RndKiss(ol::ull x) { seed(x); for (int i = 0; i < int(1023 + x % 1023); i++) u.k.cycle(); }
        RndKiss(const std::string & sd);
        ol::ull nextull() { u.k.cycle(); return u.z[0]; }
        int next() { u.k.cycle(); int r = int(u.z[0]); return r < 0 ? -r : r; }
};

// non-cross-platform generator - C++ reliable
class RndCpp : public Rnd
{
        std::string sseed;
        std::seed_seq sq;

        std::default_random_engine reng;
        std::uniform_real_distribution<double> rdist;
        std::uniform_int_distribution<int> idist;
        std::function<double()> rrnd;
        std::function<int()> irnd;

        // process empty to time random
        std::string fseed(const std::string & ss);

    public:
        RndCpp(const std::string & seed);

        //double operator()() { return rrnd(); }
        int next() { return irnd(); }
        ol::ull nextull();
};


}
} // e3::cr

#endif // _E3_OLRND_H_
