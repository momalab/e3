#include <fstream>

#include "ek_circ_plain.h"

bool CircuitEvalKey_plain::load()
{
    std::ifstream in(filename(), std::ios::binary);
    std::string s;
    in >> s;
    if (!in) return false;
    try { key = std::stoi(s); }
    catch (...) { throw "Bad key in " + filename(); }
    return true;
}

///std::string CircuitEvalKey_plain::decor(const std::string & s, bool add) const{    return prefix(s, add, "CP");}

