// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_SEAL_H_
#define _E3_SK_SEAL_H_

#include "sk_abstract.h"
#include "ekx_seal.h"
#include "e3util.h"

namespace e3
{

class CircuitPrivKey_seal_bfv;
class SealBasePrivKey : public PrivKey
{
        virtual void gen();

    private:
        SealNativePrivKey key;
        SealBaseEvalKeyExt ek;

        uint64_t polyModulusDegree = 1 << 15; // FIXME global - replace name to polyDegree
        uint64_t plainModulus = 2;
        bool isBatch = false;

    protected:
        virtual bool load();
        virtual void save();
        std::vector<std::string> rawDecrypt(const std::string & s) const;

    public:
        SealBasePrivKey(KeyName name, bool forceGen,
                        bool forceLoad, std::string seed, int lam,
                        std::string polyModulusDegree, std::string plainModulus,
                        std::string encoder);
        SealBasePrivKey(const SealBasePrivKey &) = default;
        SealBasePrivKey(const SealBasePrivKey & k, std::string nm)
            : SealBasePrivKey(k) { ek.name.typ = name.typ = nm; }

        virtual std::string decrypt(const std::string & s) const
        {
            // std::cout << __func__ << " INPUT: [" << s << "]\n";
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
            // std::cout << __func__ << " OUTPUT: [" << s << "]\n";
            return r;
        }
        virtual void decrypt(const std::string & s, std::vector<int> & r);

        virtual std::string encrypt(const std::string & s, int msz) const { return ek.encrypt(s, msz); }
        virtual std::string filename() const;

        friend class CircuitPrivKey_seal_bfv;
        friend class SealPrivKey;
        size_t slots() { return ek.slots(); }
};

inline void SealBasePrivKey::decrypt(const std::string & s, std::vector<int> & v)
{
    v.clear();
    auto vs = rawDecrypt( ek.decor(s, false) );
    for ( auto & s : vs ) v.push_back( std::stoi(s) );
}

} // e3
#endif // _E3_SK_SEAL_H_
