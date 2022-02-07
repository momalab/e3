// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include <sstream>

#include "def_pil.h"

e3::PilQuad::PilQuad(string s)
{
    std::istringstream is(s);
    string sa, sb, sr, sv;
    std::getline(is, sa, ':');
    std::getline(is, sb, ':');
    std::getline(is, sr, ':');
    std::getline(is, sv);

    x.a.n = Bigun(sa);
    x.b.n = Bigun(sb);
    y.a.n = Bigun(sr);
    y.b.n = Bigun(sv);
}

string e3::PilQuad::str() const
{
    std::ostringstream os;
    os << x.a.n << ':' << x.b.n << ':' << y.a.n << ':' << y.b.n;
    return os.str();
}



