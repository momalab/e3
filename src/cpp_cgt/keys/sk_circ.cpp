// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "olc.h"
#include "cgtutil.h"

#include "ek_circ.h"
#include "sk_circ.h"

using std::string;
using std::vector;

namespace e3
{

std::string CircuitPrivKey::decrypt(const std::string & s) const
{
    string a = decor(s, false);
    if ( a.empty() ) return "";
    return decrypt_cir(a);
}

std::string CircuitPrivKey::decrypt_cir(const std::string & ss) const
{
    auto bits = CircuitEvalKey::enc2bits(ss);

    if ( bits.empty() ) return "";

    vector<vector<bool>> m;
    bool ok = true;
    auto dbit = decbitstr(bits[0], &ok);
    /// if (!ok) return "";
    string error_msg = "Decryption failed. Ciphertext is corrupted";
    if (!ok)
    {
        std::cerr << error_msg << '\n';
        throw error_msg;
    }
    for ( auto db : dbit ) m.push_back( vector<bool>(1, db) );
    for ( size_t i = 1; i < bits.size(); i++ )
    {
        auto s = bits[i];
        ok = true;
        dbit = decbitstr(s, &ok);
        for ( size_t j = 0; j < dbit.size(); j++ ) m[j].push_back( dbit[j] );
        /// if (!ok) return "";
        if (!ok)
        {
            std::cerr << error_msg << '\n';
            throw error_msg;
        }
    }

    string r = "";
    bool isTrailingZeros = true;
    for ( size_t i = m.size() - 1; i > 0; i-- )
    {
        auto tmp = e3::util::hex2dec( e3::util::bin2hex(m[i]) );
        if ( !isTrailingZeros || tmp != "0" )
        {
            r = "_" + tmp + r;
            isTrailingZeros = false;
        }
    }
    r = e3::util::hex2dec( e3::util::bin2hex(m[0]) ) + r;

    return r;
}

std::string CircuitPrivKey::encrypt(const string & s, int msz) const
{
    return decor(encrypt_cir(s, msz), true);
}

std::string CircuitPrivKey::encrypt_cir(const string & s, int msz) const
{
    // vector<string> numbers;
    // string tmp = "";
    // for ( auto c : s )
    // {
    //     if ( c == '_' )
    //     {
    //         numbers.push_back(tmp);
    //         tmp = "";
    //     }
    //     else tmp += c;
    // }
    // numbers.push_back(tmp);
    vector<string> numbers = e3::util::split(s, '_');

    vector<vector<bool>> bin(msz);
    for ( size_t i = 0; i < numbers.size(); i++ )
    {
        auto sbit = e3::util::hex2bin( e3::util::dec2hex(numbers[i], msz), msz );
        for ( size_t j = 0; j < sbit.size(); j++ ) bin[j].push_back( sbit[j] );
    }

    vector<string> bits;
    for ( auto b : bin ) bits.push_back( encbitstr(b) );
    return CircuitEvalKey::bits2enc(bits);
}

} // e3
