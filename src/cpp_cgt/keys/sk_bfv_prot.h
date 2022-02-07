// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_BFVPROT_H_
#define _E3_SK_BFVPROT_H_

#include "sk_abstract.h"
#include "ekx_bfv_prot.h"
#include "e3util.h"

namespace e3
{

class BfvProtPrivKey : public PrivKey
{
        virtual void gen();

    private:
        BfvProtEvalKeyExt ek;

    protected:
        virtual bool load();
        virtual void save();
        std::vector<std::string> rawDecrypt(const std::string & s) const;

    public:
        BfvProtPrivKey(KeyName name, bool forceGen,
                       bool forceLoad, std::string seed, int lam,
                       std::string polyModulusDegree, std::string plainModulus,
                       std::string encoder);
        BfvProtPrivKey(const BfvProtPrivKey &) = default;
        BfvProtPrivKey(const BfvProtPrivKey & k, std::string nm)
            : BfvProtPrivKey(k) { ek.name.typ = name.typ = nm; }

        virtual std::string decrypt(const std::string & s) const // FIXME refactor with seal
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
        virtual std::string encrypt(const std::string & s, int msz) const { return ek.encrypt(s, msz); }
        virtual std::string filename() const;

        size_t slots() { return ek.slots(); }
};

} // e3
#endif // _E3_SK_BFVPROT_H_
