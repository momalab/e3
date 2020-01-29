#include <fstream>

#include "ek_native.h"

bool e3::NativeEvalKey::load()
{
    std::ifstream in(filename(), std::ios::binary);
    std::string s;
    in >> s;
    if (!in) return false;

    key = std::stoull(s);
    return true;
}
