// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <chrono>

#include "crutil.h"
#include "using.h"

string Pstream::getstr()
{
    string s;
    if ( vs.empty() )
    {
        if (!is) return "";
        is >> s;
        if (!is) return "";
        return s;
    }

    s = vs[vs.size() - 1];
    vs.pop_back();
    return s;
}


