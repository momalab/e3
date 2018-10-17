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

// FIXME e do we need this code ??
// static void toHex(const char * in, int inlen, char * out)
// {
//     const char * hexDigits = "0123456789abcdef";
//     int index = 0;

//     if (in && inlen > 0 && out)
//     {
//         for (int i = 0; i < inlen; i++)
//         {
//             out[index++] = hexDigits[(in[i] >> 4) & 0x0F];   // equal to "in[i]/16"
//             out[index++] = hexDigits[in[i] & 0x0F];          // equal to "in[i]%16"
//         }
//     }
// }

// static void toBin(const char * in, int inlen, char * out)
// {
//     int index = 0;

//     if (in && inlen > 0 && out)
//     {
//         for (int i = 0; i < inlen; i++)
//         {
//             char a = in[i];
//             if ( a >= '0' && a <= '9' ) a -= '0';
//             else if ( a >= 'a' && a <= 'f' ) a -= 'a' - char(10);

//             if ( i % 2 )
//             {
//                 out[index] <<= 4;
//                 out[index++] |= a;
//             }
//             else
//                 out[index] = a;
//         }
//     }
// }

// void e3util::toBin(const std::string& s, void* p)
// {
//  ::toBin(s.data(),s.size(),(char*)p);
// }

// static std::string toHex(const std::string & s)
// {
//     size_t sz = s.size();
//     char * buf = new char[sz * 2];
//     toHex(s.c_str(), int(sz), buf);
//     std::string r(buf, sz * 2);
//     delete [] buf;
//     return r;
// }

// std::string e3util::toHex(e3util::ull x)
// {
//     std::stringstream ss;
//     ss << std::hex << x;
//     string s ( ss.str() );
//     s = std::string( 2*sizeof(x)-s.size(), '0').append(s);
//     return s;
// }

// std::string e3util::toHex(const void* p, size_t z)
// {
//  return ::toHex( std::string((const char*)p,z) );
// }

// std::string e3util::toString(const char * c)
// {
//     std::string s(c);
//     return s;
// }
