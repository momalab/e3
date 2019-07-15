///#include <iostream> // debug

#include <fstream>

#include "olc.h"
#include "cgtutil.h"

#include "ek_circ.h"
#include "sk_circ.h"

std::string e3::CircuitPrivKey::encrypt_cir(const string & s, int msz) const
{
    if ( !util::isNumber(s) ) throw "Bad plaintext [" + s + "]";
    vector<bool> bin = e3util::hex2bin( e3util::dec2hex(s, msz), msz );
    vector<string> bits;
    for ( auto b : bin ) bits.push_back(encbitstr(b));
    return CircuitEvalKey::bits2enc(bits);
}

std::string e3::CircuitPrivKey::decrypt_cir(const std::string & ss) const
{
    auto bits = CircuitEvalKey::enc2bits(ss);

    if ( bits.empty() ) return "";

    std::vector<bool> v;
    for ( auto s : bits )
    {
        //if ( !util::isNumber(s) ) return ""; // this may not be true, e.g. base64
        bool ok = true;
        auto dbit = decbitstr(s, &ok);
        if (!ok) return "";
        v.push_back( dbit );
    }

    return e3util::hex2dec( e3util::bin2hex(v) );
}

///std::string e3::CircuitPrivKey::encrypt(const string & s, int msz, string pfx) const
///{
///    return pek->decor(encrypt_cir(s, msz), true, pfx);
///}
std::string e3::CircuitPrivKey::encrypt(const string & s, int msz) const
{
    ///return pek->decor(encrypt_cir(s, msz), true);
    return decor(encrypt_cir(s, msz), true);
}

///std::string e3::CircuitPrivKey::decrypt(const std::string & s, string pfx) const
std::string e3::CircuitPrivKey::decrypt(const std::string & s) const
{
    ///string a = pek->decor(s, false, pfx);
    string a = decor(s, false);
    if ( a.empty() ) return "";
    return decrypt_cir(a);
}



