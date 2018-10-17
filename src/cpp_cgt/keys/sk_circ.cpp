///#include <iostream> // debug

#include "ol.h"
#include "util.h"

#include "ek_circ.h"
#include "sk_circ.h"

std::string CircuitPrivKey::encrypt_cir(const string & s, int msz) const
{
    if ( !util::isNumber(s) ) throw "Bad plaintext [" + s + "]";
    vector<bool> bin = util::hex2bin( util::dec2hex(s, msz), msz );
    vector<string> bits;
    for ( auto b : bin ) bits.push_back(encbitstr(b));
    return CircuitEvalKey::bits2enc(bits);
}

std::string CircuitPrivKey::decrypt_cir(const std::string & ss) const
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

    return util::hex2dec( util::bin2hex(v) );
}

std::string CircuitPrivKey::encrypt(const string & s, int msz) const
{
    return pek->decor(encrypt_cir(s, msz), true);
}

std::string CircuitPrivKey::decrypt(const std::string & s) const
{
    string a = pek->decor(s, false);
    if ( a.empty() ) return "";
    return decrypt_cir(a);
}

