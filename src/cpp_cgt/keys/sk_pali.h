// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_PALI_H_
#define _E3_SK_PALI_H_

// #include <map> // FIXME move to the declaration place

#include "sk_abstract.h"
#include "ekx_pali.h"
#include "e3util.h"

namespace e3
{

class CircuitPrivKey_palibfv;
class PaliBfvPrivKey : public PrivKey
{
        virtual void gen();

    private:
        PaliBfvEvalKeyExt ek;
        PaliBfvNativePrivKey sk;

    protected:
        virtual bool load();
        virtual void save();
        std::vector<std::string> rawDecrypt(const std::string & s) const;

    public:
        // PaliBfvPrivKey(KeyName name) // forceLoad constructor
        //     : PaliBfvPrivKey(name, false, truestd::map<std::string, std::string> { {"seed", ""}, {"lambda", "0"} }) {}
        // PaliBfvPrivKey(KeyName name, bool forceGen, bool forceLoad, std::map<std::string, std::string> params);
        PaliBfvPrivKey(KeyName name, bool forceGen,
                       bool forceLoad, std::string seed, int lam,
                       std::string polyDegree, std::string depth,
                       int useSlots, string maxdep, string sp_n);
        PaliBfvPrivKey(const PaliBfvPrivKey &) = default;
        PaliBfvPrivKey(const PaliBfvPrivKey & k, std::string nm)
            : PaliBfvPrivKey(k) { ek.name.typ = name.typ = nm; }

        virtual std::string decrypt(const std::string & s) const;
        virtual void decrypt(const std::string & s, std::vector<int> & r);

        virtual std::string encrypt(const std::string & s, int msz) const { return ek.encrypt(s, msz); }
        virtual std::string filename() const;

        friend class CircuitPrivKey_palibfv;
        size_t slots() { return ek.slots(); }
};

inline std::string PaliBfvPrivKey::decrypt(const std::string & s) const
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

inline void PaliBfvPrivKey::decrypt(const std::string & s, std::vector<int> & v)
{
    v.clear();
    auto vs = rawDecrypt( ek.decor(s, false) );
    for ( auto & s : vs ) v.push_back( std::stoi(s) );
}

} // e3
#endif // _E3_SK_PALI_H_
