// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#pragma once

#ifndef _E3_E3KEY_H_
#define _E3_E3KEY_H_

#include <string>


#ifndef E3KEY

namespace e3
{

inline bool decrypt() { return false; }

template<typename T> inline std::string decrypt(T x) { return x.str(); }

template <class SecureType, class ReturnType>
ReturnType decrypt(const SecureType & ct)
{
    throw "Decryption can only be used by Alice.";
}

} // e3


#else


#include <iostream>
#include <map>
#include <string>
#include "cgtkey.h"

namespace e3
{

enum class SchemeType
{
    BDDN, GATCOU, NATIVE, PAIL, PAILG, PALISADE_BFV,
    PALISADE_CKKS, PILA, PILC, PLAIN, SEAL_BFV, SEAL_CKKS, TFHE
};

const std::map<std::string, SchemeType> schemeTable
{
    { "bddn"         , SchemeType::BDDN          },
    { "gatcou"       , SchemeType::GATCOU        },
    { "native"       , SchemeType::NATIVE        },
    { "pail"         , SchemeType::PAIL          },
    { "pailg"        , SchemeType::PAILG         },
    { "palisade_bfv" , SchemeType::PALISADE_BFV  },
    { "palisade_ckks", SchemeType::PALISADE_CKKS },
    { "pila"         , SchemeType::PILA          },
    { "pilc"         , SchemeType::PILC          },
    { "plain"        , SchemeType::PLAIN         },
    { "seal_bfv"     , SchemeType::SEAL_BFV      },
    { "seal_ckks"    , SchemeType::SEAL_CKKS     },
    { "tfhe"         , SchemeType::TFHE          }
};

inline bool decrypt() { return true; }

template<typename T, typename SK>
inline std::string decryptSk(const T & x, const SK sk) { return sk->decrypt(x.str()); }

template <typename T>
void getSecretKey(T x, PrivKey *& sk)
{
    std::string sc = x.clsname();
    e3::KeyName kn {x.typname(), x.filname()};
    try
    {
        switch ( schemeTable.at(sc) )
        {
            case SchemeType::BDDN         :
            {
                sk = new CircuitPrivKey_bddn(kn, false, true, "", 0, "FLF", "", "default", false);
                break;
            }
            case SchemeType::GATCOU       : sk = new CircuitPrivKey_gatcou(kn, false, true, "", 0); break;
            case SchemeType::NATIVE       : sk = new NativePrivKey(kn, false, true, ""); break;
            case SchemeType::PAIL         : sk = new PailPrivKey(kn, false, true, "", 0); break;
            case SchemeType::PAILG        : sk = new PailgPrivKey(kn, false, true, "", 0, 0); break;
            case SchemeType::PALISADE_BFV : sk = new PaliBfvPrivKey(kn, false, true, "", 0, "", "", 0, "", ""); break;
            case SchemeType::PALISADE_CKKS: sk = new PalisadeCkksPrivKey(kn); break;
            case SchemeType::PILA         : sk = new PilaPrivKey(kn, false, true, "", 0); break;
            case SchemeType::PILC         : sk = new CircuitPrivKey_pilc(kn, false, true, "", 0); break;
            case SchemeType::PLAIN        : sk = new CircuitPrivKey_plain(kn, false, true, ""); break;
            case SchemeType::SEAL_BFV     :
            {
                if ( x.is_circuit ) sk = new CircuitPrivKey_seal_bfv(kn, false, true, "", 0, "", "", "");
                else sk = new SealPrivKey(kn, false, true, "", 0, "", "", "");
                break;
            }
            case SchemeType::SEAL_CKKS    : sk = new SealCkksPrivKey(kn); break;
            case SchemeType::TFHE         : sk = new CircuitPrivKey_tfhe(kn, false, true, "", 0); break;
            default: throw;
        }
    }
    catch (...)
    {
        string e = "Alice did not understand scheme [" + string(sc) + "]";
        std::cout << e << '\n';
        throw e;
    }
}

template<typename T>
inline std::string decrypt(T x)
{
    static PrivKey * sk = nullptr;
    getSecretKey(x, sk);
    string de = decryptSk(x, sk);
    if ( T::is_signed ) de = util::unsigned2signed(de, T::size);
    return de;
}

template <class SecureType, class ReturnType>
ReturnType decrypt(const SecureType & ct)
{
    static PrivKey * sk = nullptr;
    getSecretKey(ct, sk);
    try
    {
        ReturnType r;
        sk->decrypt( ct.str(), r );
        return r;
    }
    catch (...)
    {
        throw "Cannot decrypt " + std::string( ct.clsname() ) + " ("
        + std::string( typeid(ct).name() ) + ") into "
        + std::string( typeid(ReturnType).name() ) + ".";
    }
}

} // e3

#endif // E3KEY

#endif // _E3_E3KEY_H_
