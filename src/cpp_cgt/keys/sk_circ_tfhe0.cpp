#include <fstream>

#include "sk_circ_tfhe.h"

e3::CircuitPrivKey_tfhe::CircuitPrivKey_tfhe
(std::string name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam, &ek), ek(name)
{
    init_final(forceGen, forceLoad);
}

void e3::CircuitPrivKey_tfhe::gen()
{
}

string e3::CircuitPrivKey_tfhe::filename() const
{
    return PrivKey::filenamex("_0");
}

void e3::CircuitPrivKey_tfhe::save()
{
    std::ofstream in(filename(), std::ios::binary);
    in << "CircuitPrivKey_tfhe impl:0\n";
    ek.save();
}

bool e3::CircuitPrivKey_tfhe::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    return ek.load();
}

std::string e3::CircuitPrivKey_tfhe::encbitstr(bool b) const
{
    return b ? "1" : "0";
}

bool e3::CircuitPrivKey_tfhe::decbitstr(const std::string & s, bool * ok) const
{
    if (ok) *ok = false;
    if ( s.size() != 1 ) return false;
    if (ok) *ok = true;
    if ( s == "0" ) return false;
    if ( s == "1" ) return true;
    if (ok) *ok = false;
    return false;
}
