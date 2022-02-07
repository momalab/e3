// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <algorithm>
#include <cctype>
#include <ctime>
#include <iostream>
#include <functional>
#include <string>

#include "cgtutil.h"
#include "e3util.h"

using std::string;

namespace e3
{

namespace util
{

bool isAlphaUnd(char c)
{
    return std::isalpha(c) || (c == '_');
}

bool isAlnumUnd(char c)
{
    return std::isalnum(c) || (c == '_');
}

bool isVarName(const string & name)
{
    if ( !isAlphaUnd(name[0]) ) return false;
    for ( size_t i = 1; i < name.size(); i++ )
    {
        if ( !isAlnumUnd(name[i]) ) return false;
    }
    return true;
}

bool isHexadecimal(const string & s)
{
    if ( s.empty() || s.size() < 3 || s.substr(0, 2) != "0x" ) return false;
    auto str = s.substr(2);
    for ( auto c : str )
        if ( !std::isxdigit(c) ) return false;
    return true;
}

bool isPositiveNonHexadecimalInteger(const string & s)
{
    if ( s.empty() ) return false;
    for ( auto c : s )
        if ( !std::isdigit(c) ) return false;
    return true;
}

bool isPositiveInteger(const string & s)
{
    return isHexadecimal(s) || isPositiveNonHexadecimalInteger(s);
}

bool isNegativeInteger(const string & s)
{
    return !s.empty() && s[0] == '-' && isPositiveInteger( s.substr(1) );
}

bool isInteger(const string & s)
{
    return isPositiveInteger(s) || isNegativeInteger(s);
}

bool isPositiveDecimal(const string & s)
{
    if ( s.empty() ) return false;
    auto countDot = std::count(s.begin(), s.end(), '.');
    if ( countDot > 1 ) return false;
    else if ( countDot == 1 && s.size() == 1 ) return false;
    auto posDot = s.find('.');
    auto isValidInteger = posDot == 0          ? true : isPositiveNonHexadecimalInteger( s.substr(0, posDot) );
    auto isValidDecimal = posDot == s.size() - 1 ? true : isPositiveNonHexadecimalInteger( s.substr(posDot + 1) );
    return isValidInteger && isValidDecimal;
}

bool isNegativeDecimal(const string & s)
{
    return !s.empty() && s[0] == '-' && isPositiveDecimal( s.substr(1) );
}

bool isDecimal(const string & s)
{
    return isPositiveDecimal(s) || isNegativeDecimal(s);
}

bool isPositiveScientificNumber(const string & s)
{
    if ( s.empty() ) return false;
    string str = s;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    auto countE = std::count(str.begin(), str.end(), 'E');
    if ( countE != 1 ) return false;
    auto posE = str.find('E');
    if ( posE == 0 || posE == str.size() - 1 ) return false;
    auto base = str.substr(0, posE);
    auto expo = str[posE + 1] == '+' ? str.substr(posE + 2) : str.substr(posE + 1) ;
    return isPositiveDecimal(base) && isDecimal(expo);
}

bool isNegativeScientificNumber(const string & s)
{
    return !s.empty() && s[0] == '-' && isPositiveScientificNumber( s.substr(1) );
}

bool isScientificNumber(const string & s)
{
    return isPositiveScientificNumber(s) || isNegativeScientificNumber(s);
}

bool isPositiveFloat(const string & s)
{
    return isPositiveDecimal(s) || isPositiveScientificNumber(s) || isHexadecimal(s);
}

bool isNegativeFloat(const string & s)
{
    return isNegativeDecimal(s) || isNegativeScientificNumber(s);
}

bool isFloat(const string & s)
{
    return isPositiveFloat(s) || isNegativeFloat(s);
}

// bool isNumber(const string & s)
// {
//     if ( s.empty() ) return false;
//     if ( !std::isdigit(s[0]) && s[0] != '-' ) return false;
//     for ( size_t i = 1; i < s.size(); i++ )
//         if ( !std::isdigit(s[i]) ) return false;
//     return true;
// }
//
// bool isPositiveNumber(const string & s)
// {
//     if ( s.empty() ) return false;
//     for ( size_t i = 0; i < s.size(); i++ ) if ( !std::isdigit(s[i]) ) return false;
//     return true;
// }

char addDec(char dec1, char dec2, bool * carry)
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

string unsigned2signed(const string & dec, size_t bitsize)
{
    string hex = e3::util::dec2hex(dec, bitsize);
    string ret = e3::util::hex2dec(hex, bitsize, true);
    return ret;
}

e3::util::ull gen_plain(const string & seed)
{
    e3::util::ull h;
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

bool isCpp(string filename)
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

std::string readVal(std::istream & is)
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

} // util

} // e3
