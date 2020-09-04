#include <iostream>
#include <string>
#include <time.h>
#include <cstring>
#include <vector>
#include <sstream>
#include <cstdlib>

using std::string;

typedef signed long long intint;

class Timer
{
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

template<typename T> inline string tos(T x) { std::ostringstream o; o << x; return o.str(); }

