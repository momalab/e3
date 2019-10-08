#include <iostream>
#include <fstream>

#include "ek_pail.h"

using std::cout;

bool e3::PailEvalKey::load(string fname)
{
    std::ifstream in(fname, std::ios::binary);
    if (!in) return false;
    std::string s;

    in >> s; N = Bigun(s);

    if (!in) return false;

    initN2();

    return true;
}
