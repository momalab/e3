// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <vector>
#include <string>
#include <sstream>

#include "e3util.h"

#include "ek_circ.h"


using std::string;
using std::vector;

namespace cir_deco
{
char separator = ',';
}

vector<string> e3::CircuitEvalKey::enc2bits(const string & e)
{
    using rt = vector<string>;
    rt r;
    string c = e;

    if (c.size() < 1 ) return rt();

    std::istringstream is(c);
    int i = 0;
    for ( string s; std::getline(is, s, cir_deco::separator); i++ )
        r.push_back( s );

    if ( !i ) return rt();
    return r;
}

string e3::CircuitEvalKey::bits2enc(const vector<string> & v)
{
    string x;
    for ( auto b : v ) x += b + cir_deco::separator;
    return x.substr(0, x.size() - 1);
}

