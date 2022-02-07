// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_CRUTIL_H_
#define _E3_CRUTIL_H_

#include <string>

#include "olc.h"

namespace e3
{
namespace cr
{

// this class is a wrapper around istringstream to allow
// put back operations
class Pstream
{
        ol::istr is;
        ol::vstr vs;
        std::string getstr();
    public:
        Pstream(std::string s): is(s) {}

        friend Pstream & operator>>
        (Pstream & is, std::string & s) { s = is.getstr(); return is; }

        friend Pstream & operator<<
        (Pstream & os, std::string & s) { os.vs.push_back(s); return os; }
};

}
} // e3::cr

#endif // _E3_CRUTIL_H_
