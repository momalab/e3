#ifndef _E3_E3KEY_H_
#define _E3_E3KEY_H_

#include <string>


#ifndef E3KEY

namespace e3{
inline bool decrypt(){ return false; }
template<typename T> inline std::string decrypt(T x) { return x.str(); }
} // e3


#else


#include <iostream>
#include "cgtkey.h"

namespace e3{

inline bool decrypt(){ return true; }

template<typename T, typename SK>
inline std::string decryptSk(const T & x, const SK sk) { return sk->decrypt(x.str()); }


template<typename T>
inline std::string decrypt(T x)
{
    using std::string;
    static PrivKey * sk = nullptr;

    string sc = x.clsname();
    e3::KeyName kn {x.typname(), x.filname()};

    if (!sk)
    {
        if ( sc == "plain" ) sk = new CircuitPrivKey_plain(kn, false, true, "");
        if ( sc == "native" ) sk = new NativePrivKey(kn, false, true, "");
        if ( sc == "tfhe" ) sk = new CircuitPrivKey_tfhe(kn, false, true, "", 0);
        if ( sc == "pilc" ) sk = new CircuitPrivKey_pilc(kn, false, true, "", 0);
        if ( sc == "pila" ) sk = new PilaPrivKey(kn, false, true, "", 0);
        if ( sc == "pail" ) sk = new PailPrivKey(kn, false, true, "", 0);
        if ( sc == "pailg" ) sk = new PailgPrivKey(kn, false, true, "", 0,0);
        if ( sc == "seal" )
        {
            if ( x.is_circuit ) sk = new CircuitPrivKey_seal(kn, false, true, "", 0, "", "", "");
            else sk = new SealPrivKey(kn, false, true, "", 0, "", "", "");
         }
        if ( sc == "bddn" ) sk = new CircuitPrivKey_bddn(kn, false, true, "",
                    0, "FLF", "", "default", false);
    }

    if ( !sk )
    {
        string e = "Alice did not understand scheme [" + string(sc) + "]";
        std::cout << e << '\n';
        throw e;
    }

    string de = decryptSk(x, sk);
    if( T::is_signed ) de = util::unsigned2signed(de, T::size);
    return de;
}

} // e3

#endif // E3KEY

#endif // _E3_E3KEY_H_
