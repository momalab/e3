// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <ctime>

#include "cgtutil.h"
#include "sk_native.h"

using std::string;

e3::NativePrivKey::NativePrivKey
(KeyName nm, bool forceGen, bool forceLoad, std::string seed)
    : PrivKey(nm, seed, 0), ek(nm) // 0 for lambda
{
    init_final(forceGen, forceLoad);
}

string e3::NativePrivKey::decrypt(const string & c) const
{
    string s = decor(c, false);

    if ( s.size() != sizeof(e3::util::ull) * 2 ) return "";
    if ( !e3::util::isHex(s) ) return "";

    e3::util::ull x = e3::util::hex2ull(s);
    x = ek.dec(x, key);
    return std::to_string(x);
}

string e3::NativePrivKey::encrypt(const string & s, int msz) const
{
    e3::util::ull x = std::stoull(s);
    x &= e3::util::mask(msz);
    x = ek.enc(x, key);
    return ek.decor(e3::util::ull2hex(x), true);
}

void e3::NativePrivKey::gen()
{
    key = (1ull << (rnd->next() % 22 + 2) );
    key = 0x800;
    ek.key = key; // if the SK is generated, EK must be generated
}

bool e3::NativePrivKey::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if (!in) return false;

    std::string s;
    in >> s;
    if (!in) return false;

    key = std::stoull(s);

    return ek.load(); // if SK is loaded, EK must also be loaded
}

void e3::NativePrivKey::save()
{
    std::ofstream ofs(filename(), std::ios::binary);
    ofs << key << '\n';
    ek.save(); // if SK is saved, EK must be saved as well
}
