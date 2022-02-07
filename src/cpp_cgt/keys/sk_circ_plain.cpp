// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <sstream>
#include <vector>

#include "olc.h"
#include "cgtutil.h"

#include "sk_circ_plain.h"

using std::string;
using std::vector;
using std::cout;
using namespace e3::cr;

namespace e3
{

CircuitPrivKey_plain::CircuitPrivKey_plain
(KeyName name, bool forceGen, bool forceLoad, std::string seed)
    : CircuitPrivKey(name, seed, 0), ek(name) // 0 lam
{
    init_final(forceGen, forceLoad);
}

vector<bool> CircuitPrivKey_plain::decbitstr(const std::string & s, bool * ok) const
{
    vector<bool> m(1, false);
    if (ok) *ok = false;
    // if ( e3::util::isNumber(s) ) // deprecated
    if ( e3::util::isInteger(s) )
        // if ( e3::util::isFloat(s) ) // use this if CKKS circuit becomes a thing
    {
        try
        {
            e3::util::usi x = std::stoi(s);
            if (ok) *ok = true;
            m[0] = decbitUsi(x);
        }
        catch (...) { }
    }
    return m;
}

string CircuitPrivKey_plain::encbitstr(vector<bool> b) const
{
    return ol::tos(encbitUsi(b[0]));
}

void CircuitPrivKey_plain::gen()
{
    key = 800;
    ek.key = key;
}

bool CircuitPrivKey_plain::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if (!in) return false;
    std::string s;
    in >> s;
    if (!in) return false;
    try { key = std::stoi(s); }
    catch (...) { throw "(l:64) Bad key in " + filename(); }
    return ek.load();
}

void CircuitPrivKey_plain::save()
{
    std::ofstream ofs(filename(), std::ios::binary);
    ofs << key << '\n';
    ek.save();
}

} // e3
