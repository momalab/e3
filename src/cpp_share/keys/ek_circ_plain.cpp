// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>

#include "ek_circ_plain.h"

bool e3::CircuitEvalKey_plain::load()
{
    std::ifstream in(filename(), std::ios::binary);
    std::string s;
    in >> s;
    if (!in) return false;
    try { key = std::stoi(s); }
    catch (...) { throw "(l:12) Bad key in " + filename(); }
    return true;
}


