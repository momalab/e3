// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include "ek_abstract.h"

using std::string;

void e3::EvalKey::loadOrDie()
{
    if (!load()) throw "Cannot load the key [" + filename() + "]";
}

string e3::EvalKey::encrypt(const string & s, int msz) const
{
    // return empty string for N/A
    return "";
}
