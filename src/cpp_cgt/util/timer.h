// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_TIMER_H_
#define _E3_TIMER_H_

#include <iostream>
#include <string>
#include <time.h>
#include <cstring>
#include <vector>
#include <sstream>
#include <cstdlib>

using std::string;

namespace e3
{

class Timer
{
    public:
        typedef signed long long intint;

    private:
        intint tv_sec, tv_usec;
        intint adj;

    public:
        void init();
        Timer(): tv_sec(0), tv_usec(0), adj(0) { init(); }
        Timer(int): tv_sec(0), tv_usec(0), adj(0) {} // no init
        intint get(); // get time passed in millisecs
        void set(intint);

        // date +%g%m%d
        static string getGmd();
        static void setGmd(string gmd);
        static string getHms();
        static void setHms(string hms);
};


} // e3

#endif // _E3_TIMER_H_
