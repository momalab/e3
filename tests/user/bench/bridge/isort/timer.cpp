#include <iostream>
#include <string>
#include <time.h>
#include <cstring>
#include <vector>
#include <sstream>
#include <cstdlib>

#include "timer.h"

// --- timer impl

#ifdef _MSC_VER
#include <windows.h>
#define EPOCHFILETIME (116444736000000000LL)

///#include "timer.h"

int gettimeofday(struct timeval * tv, struct timezone *)
{
    FILETIME        ft;
    LARGE_INTEGER   li;
    __int64           t;

    if (tv)
    {
        GetSystemTimeAsFileTime(&ft);
        li.LowPart  = ft.dwLowDateTime;
        li.HighPart = ft.dwHighDateTime;
        t  = li.QuadPart;       /* In 100-nanosecond intervals */
        t -= EPOCHFILETIME;     /* Offset to the Epoch time */
        t /= 10;                /* In microseconds */
        tv->tv_sec  = (long)(t / 1000000);
        tv->tv_usec = (long)(t % 1000000);
    }

    return 0;

}

#else
#include <sys/time.h>
#endif

void Timer::init()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    tv_sec = t.tv_sec;
    tv_usec = t.tv_usec;
    adj = 0;
}

intint Timer::get()
{
    struct timeval this_call;
    gettimeofday(&this_call, NULL);
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

static char current_gmd[10];
static char current_hms[10];

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
