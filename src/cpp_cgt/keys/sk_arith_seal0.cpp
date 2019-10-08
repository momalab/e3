#include <fstream>
#include <string>

#include "sk_arith_seal.h"

using std::string;

e3::SealBasePrivKey::SealBasePrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam, string polyModulusDegree, string plaintextModulus)
    : PrivKey(name, seed, lam), ek(name)
{
    init_final(forceGen, forceLoad);
}

string e3::SealBasePrivKey::filename() const
{
    return PrivKey::filename();
}

void e3::SealBasePrivKey::gen() { }

void e3::SealBasePrivKey::save()
{
    std::ofstream in(filename(), std::ios::binary);
    in << "SealPrivKey impl:0\n";
    ek.save();
}

bool e3::SealBasePrivKey::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;
    return ek.load();
}

string e3::SealBasePrivKey::decrypt(const string & c) const
{
    return ek.decor(c, false);
}

string e3::SealBasePrivKey::encrypt(const string & s, int msz) const
{
    return ek.decor(s, true);
}
