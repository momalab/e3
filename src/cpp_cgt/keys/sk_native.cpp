#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <ctime>

#include "cgtutil.h"
#include "sk_native.h"

using std::string;

NativePrivKey::NativePrivKey
(std::string nm, bool forceGen, bool forceLoad, std::string seed)
    : PrivKey(nm, seed, 0), ek(nm) // 0 for lambda
{
    init_final(forceGen, forceLoad);
}

string NativePrivKey::decrypt(const string & c, string pfx) const
{
    string s = ek.decor(c, false, pfx);

    if ( s.size() != sizeof(e3util::ull) * 2 ) return "";
    if ( !util::isHex(s) ) return "";

    e3util::ull x = e3util::hex2ull(s);
    x = ek.dec(x, key);
    return std::to_string(x);
}

string NativePrivKey::encrypt(const string & s, int msz, string pfx) const
{
    e3util::ull x = std::stoull(s);
    x &= e3util::mask(msz);
    x = ek.enc(x, key);
    return ek.decor(e3util::ull2hex(x), true, pfx);
    ///return e3util::ull2hex(x);
}

void NativePrivKey::gen()
{
    key = (1ull << (rnd->next() % 22 + 2) );
    key = 0x800;
    ek.key = key; // if the SK is generated, EK must be generated
}

bool NativePrivKey::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if (!in) return false;

    std::string s;
    in >> s;
    if (!in) return false;

    key = std::stoull(s);

    return ek.load(); // if SK is loaded, EK must also be loaded
}

void NativePrivKey::save()
{
    std::ofstream ofs(filename(), std::ios::binary);
    ofs << key << '\n';
    ek.save(); // if SK is saved, EK must be saved as well
}
