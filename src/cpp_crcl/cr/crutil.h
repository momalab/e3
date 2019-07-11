#pragma once

#include <string>

#include "olc.h"

using namespace ol;

// this class is a wrapper around istringstream to allow
// put back operations
class Pstream
{
        istr is;
        vstr vs;
        string getstr();
    public:
        Pstream(string s): is(s) {}

        friend Pstream & operator>>
        (Pstream & is, string & s) { s = is.getstr(); return is; }

        friend Pstream & operator<<
        (Pstream & os, string & s) { os.vs.push_back(s); return os; }
};

