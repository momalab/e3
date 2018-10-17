#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <ctime>

#include "ol.h"
#include "util.h"

#include "sk_circ_plain.h"

using std::string;

void CircuitPrivKey_plain::gen()
{
    key = 800;
    ///ek.setKey(key);
    ek.key = key;
}

CircuitPrivKey_plain::CircuitPrivKey_plain
(std::string name, bool forceGen, bool forceLoad, std::string seed)
    : CircuitPrivKey(name, seed, 0, &ek), ek(name) // 0 lam
{
    init_final(forceGen, forceLoad);
}

void CircuitPrivKey_plain::save()
{
    std::ofstream ofs(filename(), std::ios::binary);
    ofs << key << '\n';
    ek.save();
}

bool CircuitPrivKey_plain::load()
{
    std::ifstream in(filename(), std::ios::binary);
    if (!in) return false;
    std::string s;
    in >> s;
    if (!in) return false;
    try { key = std::stoi(s); }
    catch (...) { throw "Bad key in " + filename(); }
    return ek.load();
}

std::string CircuitPrivKey_plain::encbitstr(bool b) const
{
    return ol::tos(encbitUsi(b));
}

bool CircuitPrivKey_plain::decbitstr(const std::string & s, bool * ok) const
{
    if (ok) *ok = false;
    if ( !util::isNumber(s) ) return false;
    e3util::usi x = 0;
    try { x = std::stoi(s); }
    catch (...) { return false; }

    if (ok) *ok = true;
    return decbitUsi(x);
}

