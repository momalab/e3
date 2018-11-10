#include <functional>
#include <ctime>
#include <cctype>

#include "util.h"

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

bool util::isNegative(const string & hex, size_t bitsize)
{
    ///unsigned maxhexbs = 4 * hex.size();
    auto maxhexbs = 4 * hex.size();
    if ( bitsize > maxhexbs ) return false;

    ///unsigned uppersize = bitsize % 4;
    auto uppersize = bitsize % 4;
    uppersize = uppersize ? uppersize : 4;
    unsigned signThreshold = 1 << (uppersize - 1);
    unsigned upperhex = hex2dec(hex[hex.size() - (bitsize + 3) / 4]);

    return upperhex >= signThreshold;
}

char util::maskHex(char c, size_t bitsize)
{
    auto uppersize = bitsize % 4;
    uppersize = uppersize ? uppersize : 4;
    auto upperlimit = (1 << uppersize) - 1;
    unsigned upperhex = hex2dec(c);
    upperhex &= upperlimit;
    return dec2hex(upperhex);
}

char util::negation(char hex)
{
    switch (hex)
    {
        case '0' : return 'f';
        case '1' : return 'e';
        case '2' : return 'd';
        case '3' : return 'c';
        case '4' : return 'b';
        case '5' : return 'a';
        case '6' : return '9';
        case '7' : return '8';
        case '8' : return '7';
        case '9' : return '6';
        case 'a' : return '5';
        case 'b' : return '4';
        case 'c' : return '3';
        case 'd' : return '2';
        case 'e' : return '1';
        case 'f' : return '0';
    }
    return 0;
}

string util::negation(const string & hexStr, size_t bitsize)
{
    string hex (hexStr);
    while ( bitsize > 4 * hex.size() ) hex = '0' + hex;

    string neg;
    for ( auto c : hex )
    {
        neg = neg + negation(c);
    }

    neg[0] = maskHex(neg[0], bitsize);
    return neg;
}

string util::zeroExtension(const string & hex, size_t bitsize)
{
    auto size = (bitsize / 4) - hex.size();
    string out = "";
    while (size--) out += "0";
    out += hex;
    return out;
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

char util::addHex(char hex1, char hex2, bool * carry)
{
    bool c = false;
    char h1 = hex1 <= '9' ? hex1 - '0' : hex1 - 'a' + 10;
    char h2 = hex2 <= '9' ? hex2 - '0' : hex2 - 'a' + 10;
    char sum = h1 + h2;
    if ( sum <= 9 ) sum += '0';
    else sum += 'a' - 10;

    if ( sum > 'f' )
    {
        c = true;
        sum -= 0x10;
        if ( sum < 'a' ) sum += '0' - 'a' + 10;
    }

    if ( carry ) *carry = c;
    return sum;
}

string util::add(const string & dec, unsigned value)
{
    string r;
    unsigned carry = value;
    for ( int i = (int)dec.size() - 1; i >= 0; i-- )
    {
        unsigned d = dec[i] - '0' + carry;
        carry = d / 10;
        d %= 10;
        r = std::to_string(d) + r;
    }
    if ( carry ) r = std::to_string(carry) + r;
    return r;
}

string util::multiply(const string & dec, unsigned value)
{
    string r;
    unsigned carry = 0;
    for ( int i = (int)dec.size() - 1; i >= 0; i-- )
    {
        unsigned d = (dec[i] - '0') * value + carry;
        carry = d / 10;
        d %= 10;
        r = std::to_string(d) + r;
    }
    if ( carry ) r = std::to_string(carry) + r;
    return r;
}

string util::divide(const string & dec, unsigned div)
{
    string r;
    unsigned i = 0;
    unsigned t = dec[i] - '0';
    while ( t < div ) t = 10 * t + ( ++i < dec.size() ? dec[i] - '0' : 0);
    while ( dec.size() > i )
    {
        r += t / div + '0';
        t = 10 * (t % div) + dec[++i] - '0';
    }
    if ( r.empty() ) r = "0";
    return r;
}

unsigned util::mod(const string & dec, unsigned div)
{
    unsigned r = 0;
    for ( unsigned i = 0; i < dec.size(); i++ )
        r = ( 10 * r + dec[i] - '0' ) % div;
    return r;
}

string util::increment(const string & hex, size_t bitsize)
{
    string sum;
    bool c = false;
    int i = (int)hex.size() - 1;
    char s = addHex(hex[i--], '1', &c);
    sum = sum + s;

    for ( ; i >= 0; i-- )
    {
        if ( c ) s = addHex(hex[i], '1', &c);
        else
        {
            s = hex[i];
            c = false;
        }
        sum = s + sum;
    }

    int maxsumbs = 4 * (int)sum.size();
    auto minsumbs = maxsumbs - 3;

    int ibs = (int)bitsize;
    if ( minsumbs > ibs )
        sum = sum.substr(1);
    else if ( minsumbs <= ibs && maxsumbs >= ibs )
        sum[0] = maskHex(sum[0], bitsize);

    return sum;
}

string util::twosComplement(const string & hex, size_t bitsize)
{
    return increment(negation(hex, bitsize), bitsize);
}

string util::removeLeadingZeros(const string & s)
{
    string r;
    bool start = false;
    for ( auto c : s )
    {
        if ( start || c != '0' )
        {
            start = true;
            r = r + c;
        }
    }
    if ( r.empty() ) r = "0";
    return r;
}

string util::bin2hex(const std::vector<bool> & bin)
{
    std::vector<bool> bits(bin);
    while ( bits.size() % 4 ) bits.push_back(false);
    string hex;
    for ( size_t i = 0; i < bits.size(); i += 4 )
    {
        unsigned dec = 0;
        for (int j = 3; j >= 0; j--)
            dec = (dec << 1) + (unsigned)bits[i + j];
        char c = dec2hex(dec);
        hex = c + hex;
    }
    return hex;
}

std::vector<bool> util::hex2bin(const string & hex, size_t bitsize)
{
    std::vector<bool> bin;
    for ( int i = (int)hex.size() - 1; i >= 0; i-- )
    {
        unsigned d = hex2dec(hex[i]);
        for (unsigned j = 0; j < 4; j++)
        {
            bin.push_back(d & 1);
            d >>= 1;
        }

    }
    if ( bitsize ) while ( bin.size() > bitsize ) bin.pop_back();
    return bin;
}

unsigned util::hex2dec(char hex)
{
    if ( hex <= '9' ) return hex - '0';
    return hex - 'a' + 10;
}

char util::hex2dec(char hex, bool * carry)
{
    bool c = false;
    char dec;
    if ( hex >= 'a' )
    {
        c = true;
        dec = hex - 'a' + '0';
    }
    else dec = hex;

    if ( carry ) *carry = c;
    return dec;
}

string util::hex2dec(const string & hexStr, size_t bitsize, bool sign)
{
    string hex (hexStr);
    bool neg = false;
    if ( sign )
    {
        neg = isNegative(hex, bitsize);
        if ( neg ) hex = twosComplement(hex, bitsize);
    }

    string dec = "0";
    for ( auto h : hex )
    {

        dec = multiply(dec, 16);
        unsigned d = hex2dec(h);
        dec = add(dec, d);
    }
    dec = removeLeadingZeros(dec);
    if ( neg ) dec = '-' + dec;
    return dec;
}

char util::dec2hex(unsigned dec)
{
    if ( dec <= 9 ) return (char)(dec + '0');
    return (char)(dec - 10 + 'a');
}

#include <iostream>
string util::dec2hex(const string & decStr, size_t bitsize)
{
    if ( decStr == "0" ) return "0";

    string dec (decStr);
    bool isNegative = false;
    if ( dec[0] == '-' )
    {
        isNegative = true;
        dec = dec.substr(1);
    }

    string hex;
    while ( dec != "0" )
    {
        unsigned m = mod(dec, 16);
        dec = divide(dec, 16);
        hex = dec2hex(m) + hex;
    }

    if ( isNegative ) hex = twosComplement(hex, bitsize);
    else hex = zeroExtension(hex, bitsize);

    return hex;
}

string util::unsigned2signed(const string & dec, size_t bitsize)
{
    string hex = dec2hex(dec, bitsize);
    string ret = hex2dec(hex, bitsize, true);
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
