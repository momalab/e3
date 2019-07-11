#include <iostream>
#include <functional>
#include <ctime>
#include <cctype>

#include "cgtutil.h"
#include "e3util.h"

using std::string;

bool util::isAlphaUnd(char c)
{
    return std::isalpha(c) || (c == '_');
}

bool util::isAlnumUnd(char c)
{
    return std::isalnum(c) || (c == '_');
}

bool util::isHex(char c)
{
    return ( c >= '0' && c <= '9' ) || ( c >= 'a' && c <= 'f' );
}

bool util::isVarName(const string & name)
{
    if ( !isAlphaUnd(name[0]) ) return false;
    for ( size_t i = 1; i < name.size(); i++ )
    {
        if ( !isAlnumUnd(name[i]) ) return false;
    }
    return true;
}

bool util::isNumber(const string & s)
{
    if ( s.empty() ) return false;
    if ( !std::isdigit(s[0]) && s[0] != '-' ) return false;
    for ( size_t i = 1; i < s.size(); i++ ) if ( !std::isdigit(s[i]) ) return false;
    return true;
}

bool util::isPositiveNumber(const string & s)
{
    if ( s.empty() ) return false;
    for ( size_t i = 0; i < s.size(); i++ ) if ( !std::isdigit(s[i]) ) return false;
    return true;
}

bool util::isHex(const string & s)
{
    for ( auto c : s ) if (!isHex(c)) return false;
    return true;
}

char util::addDec(char dec1, char dec2, bool * carry)
{
    bool c = false;
    char sum = dec1 + dec2 - '0';
    if ( sum > '9' )
    {
        c = true;
        sum -= 10;
    }

    if ( carry ) *carry = c;
    return sum;
}

string util::unsigned2signed(const string & dec, size_t bitsize)
{
    string hex = e3util::dec2hex(dec, bitsize);
    string ret = e3util::hex2dec(hex, bitsize, true);
    return ret;
}

string util::trim(const string & s)
{
    auto posI = s.find_first_not_of(" \t\n\v\r");
    if ( posI == string::npos ) return "";
    auto posF = s.find_last_not_of(" \t\n\v\r");
    return s.substr(posI, posF + 1);
}

e3util::ull util::gen_plain(const string & seed)
{
    e3util::ull h;
    if ( seed.empty() )
    {
        srand( (unsigned)time(nullptr) );
        h = rand();
    }
    else
    {
        std::hash<string> hashStr;
        h = hashStr(seed);
    }
    return 1ull << (h % 22 + 10);
}

bool util::isCpp(string filename)
{
    std::vector<string> exts { ".cpp" , ".h", ".inc" };

    for ( auto e : exts )
    {
        auto fsz = filename.size();
        auto esz = e.size();
        if ( fsz <= esz ) continue;
        if ( filename.find(e) == (fsz - esz) )
            return true;
    }

    return false;
}

std::string util::readVal(std::istream & is)
{
    string s;
    is >> s;
    if ( s != "[" ) return s;

    string r;
    while (1)
    {
        is >> s;
        if ( s == "]" ) break;
        if ( !is ) throw "Closing ']' not found";
        if ( !r.empty() ) r += ' ';
        r += s;
    }
    return r;
}

