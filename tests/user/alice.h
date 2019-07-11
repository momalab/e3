#include <string>
using std::string;


#ifndef E3ALICE
template<typename T> inline string dec(T x) { return x.str(); }
template<typename T> inline string decs(T x) { return dec(x); }
template<typename T> inline string dec(T x, string) { return dec(x); }
template<typename T> inline string decs(T x, string) { return dec(x); }
#else


#include <iostream>
#include "privkeys.h"
#include "cgtutil.h"

template<typename T, typename SK>
inline string decT(const T & x, const SK sk, string n) { return sk->decrypt(x.str(),n); }

template<typename T, typename SK>
inline string decT(const T & x, const SK sk) { return decT(x,sk,x.name()); }

template<typename T>
inline string dec(T x, string n)
{
    using namespace e3;
    static PrivKey * sk = nullptr;

    string sc = x.scheme();
    if (!sk)
    {
        if ( sc == "plain" ) sk = new CircuitPrivKey_plain(x.name(), false, true, "");
        if ( sc == "native" ) sk = new NativePrivKey(x.name(), false, true, "");
        if ( sc == "tfhe" ) sk = new CircuitPrivKey_tfhe(x.name(), false, true, "", 0);
        if ( sc == "pilc" ) sk = new CircuitPrivKey_pilc(x.name(), false, true, "", 0);
        if ( sc == "pila" ) sk = new PilaPrivKey(x.name(), false, true, "", 0);

        if ( sc == "bddn" ) sk = new CircuitPrivKey_bddn(x.name(), false, true, "",
                    0, "FLF", "", "default", false);
    }

    if ( !sk )
    {
        string e = "Alice did not understand scheme [" + string(sc) + "]";
        std::cout << e << '\n';
        throw e;
    }

    return decT(x, sk, n);
}

template<typename T>
inline string dec(T x)
{
	return dec(x,x.name());
}

template<typename T>
inline string decs(T x, string n)
{
    auto r = dec(x,n);
    return util::unsigned2signed(r, x.size());
}

template<typename T>
inline string decs(T x)
{
    auto r = dec(x);
    return util::unsigned2signed(r, x.size());
}

#endif
