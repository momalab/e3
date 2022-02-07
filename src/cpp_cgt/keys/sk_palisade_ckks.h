// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_PALISADE_CKKS_H_
#define _E3_SK_PALISADE_CKKS_H_

#include <cmath>
#include <complex>
#include <map>
#include <string>
#include <vector>

#include "sk_abstract.h"
#include "ekx_palisade_ckks.h"
#include "e3util.h"

namespace e3
{

class CircuitPrivKey_PalisadeCkks;
class PalisadeCkksPrivKey : public PrivKey
{
        virtual void gen();

    private:
        PalisadeCkksEvalKeyExt ek;
        PalisadeCkksNativePrivKey sk;

    protected:
        virtual bool load();
        virtual void save();
        std::vector<std::string> rawDecrypt(const std::string & s) const;

    public:
        PalisadeCkksPrivKey(KeyName name) // forceLoad constructor
            : PalisadeCkksPrivKey(name, false, true, std::map<std::string, std::string> { {"seed", ""}, {"lambda", "0"} }) {}
        PalisadeCkksPrivKey(KeyName name, bool forceGen, bool forceLoad, std::map<std::string, std::string> params);
        PalisadeCkksPrivKey(const PalisadeCkksPrivKey &) = default;
        PalisadeCkksPrivKey(const PalisadeCkksPrivKey & key, std::string name)
            : PalisadeCkksPrivKey(key) { ek.name.typ = this->name.typ = name; }

        virtual std::string decrypt(const std::string & strCiphertext) const;
        virtual void decrypt(const std::string & s, std::vector<std::complex<double>> & r);
        virtual void decrypt(const std::string & s, std::vector<double> & r);
        virtual void decrypt(const std::string & s, std::vector<int> & r);
        virtual std::string encrypt(const std::string & strPlaintext, int msz) const
        { return ek.encrypt(strPlaintext, msz); }
        virtual std::string filename() const;

        friend class CircuitPrivKey_PalisadeCkks;
        size_t slots() { return ek.slots(); }
};

inline std::string PalisadeCkksPrivKey::decrypt(const std::string & s) const
{
    auto v = rawDecrypt( ek.decor(s, false) );
    std::string r = "";
    bool isTrailing = false;
    if ( v.size() > 1 )
    {
        if ( v.size() == 2 ) r += v[0] + "_" + v[1];
        else
        {
            auto lastValue = v.back();
            auto penultimate = v[ v.size() - 2 ];
            isTrailing = lastValue == penultimate;
            r += "_" + penultimate + "_" + lastValue;
            if ( isTrailing ) r += "...";
            for ( size_t i = v.size() - 3; i > 0; i-- )
            {
                if ( !isTrailing || v[i] != v.back() )
                {
                    r = "_" + v[i] + r;
                    isTrailing = false;
                }
            }
            isTrailing &= v[0] == lastValue;
        }
    }
    if ( isTrailing ) r = r.substr(1);
    else r = v[0] + r;
    return r;
}

inline void PalisadeCkksPrivKey::decrypt(const std::string & s, std::vector<std::complex<double>> & v)
{
    v.clear();
    auto vs = rawDecrypt( ek.decor(s, false) );
    for ( auto & s : vs )
    {
        auto vsc = e3::util::split(s, '+');
        double real = vsc.size() > 0 ? std::stod( vsc[0] ) : 0;
        double imag = vsc.size() > 1 ? std::stod( vsc[1].substr(0, vsc[1].size() - 1) ) : 0;
        v.push_back( std::complex<double>(real, imag) );
    }
}

inline void PalisadeCkksPrivKey::decrypt(const std::string & s, std::vector<double> & v)
{
    v.clear();
    std::vector<std::complex<double>> vc;
    decrypt(s, vc);
    for ( auto & c : vc ) v.push_back( c.real() );
}

inline void PalisadeCkksPrivKey::decrypt(const std::string & s, std::vector<int> & v)
{
    v.clear();
    std::vector<std::complex<double>> vc;
    decrypt(s, vc);
    for ( auto & c : vc ) v.push_back( int( std::round( c.real() ) ) );
}

// vector<double> decrypt(const std::string & s) const
// {
//     auto vs = rawDecrypt( ek.decor(s, false) );
//     vector<double> v;
//     for ( auto & s : vs )
//     {
//         double real = std::stod( e3::util::split(s, '+') );
//         v.push_back(real);
//     }
//     return v;
// }

} // e3

#endif // _E3_SK_PALISADE_CKKS_H_
