#include <iostream>
#include <string>
#include <time.h>
#include <cstring>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <chrono>

#include "timer.h"

struct Tval
{
    intint tv_sec, tv_usec;
};

void gettimeofd(Tval * tv)
{
    auto mics = std::chrono::time_point_cast<std::chrono::microseconds>
                (std::chrono::steady_clock::now()).time_since_epoch().count();

    tv->tv_sec  = (intint)(mics / 1000000);
    tv->tv_usec = (intint)(mics % 1000000) ;
}

void Timer::init()
{
    Tval t;
    gettimeofd(&t);
    tv_sec = t.tv_sec;
    tv_usec = t.tv_usec;
    adj = 0;
}

intint Timer::get()
{
    Tval this_call;
    gettimeofd(&this_call);
    intint r =
        (this_call.tv_sec - tv_sec) * 1000000L
        + (this_call.tv_usec - tv_usec);
    return r + adj; // us
}

void Timer::set(intint x)
{
    adj = 0;
    adj = x - get();
}

static string atleast2(int s)
{
    string m = tos(s);
    while ( m.size() < 2 ) m = string("0") + m;
    return m;
}

static char current_gmd[11];
static char current_hms[11];

string Timer::getGmd()
{
    if ( current_gmd[0] )
        return current_gmd;

    time_t t = ::time(0);
    struct tm * x = ::localtime(&t);
    string s;
    s += atleast2(x->tm_year + 1900);
    s += atleast2(x->tm_mon + 1);
    s += atleast2(x->tm_mday);
    return s;
}

void Timer::setGmd(string gmd)
{
    if ( !gmd.empty() && gmd.size() != 8 )
        return;
    std::strncpy(current_gmd, gmd.c_str(), 10);
}

void Timer::setHms(string hms)
{
    if ( !hms.empty() && hms.size() != 6 )
        return;
    std::strncpy(current_hms, hms.c_str(), 10);
}

string Timer::getHms()
{
    if ( current_hms[0] )
        return current_hms;

    time_t t = ::time(0);
    struct tm * x = ::localtime(&t);
    string s;
    s += atleast2(x->tm_hour);
    s += atleast2(x->tm_min);
    s += atleast2(x->tm_sec);
    return s;
}
