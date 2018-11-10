#include <sstream>
#include <string>

#include "e3util.h"

using std::string;

e3util::ull e3util::hex2ull(std::string s)
{
    std::stringstream ss (s);
    e3util::ull x;
    ss >> std::hex >> x;
    return x;
}

std::string e3util::ull2hex(e3util::ull x)
{
    std::stringstream ss;
    ss << std::hex << x;
    string s ( ss.str() );
    s = std::string( 2 * sizeof(x) - s.size(), '0').append(s);
    return s;
}
