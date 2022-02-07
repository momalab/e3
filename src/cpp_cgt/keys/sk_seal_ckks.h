// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_SEAL_CKKS_H_
#define _E3_SK_SEAL_CKKS_H_

#include "sk_abstract.h"
#include "ekx_seal_ckks.h"
#include "e3util.h"

namespace e3
{

// class CircuitPrivKey_seal_ckks;
class SealCkksBasePrivKey : public PrivKey
{
        virtual void gen();

    private:
        SealCkksNativePrivKey key;
        SealCkksBaseEvalKeyExt ek;

        uint64_t polyModulusDegree = 1 << 15;
        std::vector<int> primes = { 60, 40, 40, 60 };
        uint64_t scale = 40;

    protected:
        virtual bool load();
        virtual void save();
        std::vector<std::string> rawDecrypt(const std::string & s) const;

    public:
        SealCkksBasePrivKey(KeyName name, bool forceGen,
                            bool forceLoad, std::string seed, int lam,
                            std::string polyModulusDegree, std::string primes,
                            std::string scale);
        SealCkksBasePrivKey(const SealCkksBasePrivKey &) = default;
        SealCkksBasePrivKey(const SealCkksBasePrivKey & k, std::string nm)
            : SealCkksBasePrivKey(k) { ek.name.typ = name.typ = nm; }

        virtual std::string decrypt(const std::string & s) const
        {
            auto v = rawDecrypt( ek.decor(s, false) );
            std::string r = "";
            bool isTrailingZeros = true;
            for ( size_t i = v.size() - 1; i > 0; i-- )
                if ( !isTrailingZeros || v[i] != "0" )
                {
                    r = "_" + v[i] + r;
                    isTrailingZeros = false;
                }
            r = v[0] + r;
            return r;
        }
        virtual std::string encrypt(const std::string & s, int msz) const { return ek.encrypt(s, msz); }
        virtual std::string filename() const;

        // friend class CircuitPrivKey_seal_ckks;
        friend class SealCkksPrivKey;
        size_t slots() { return ek.slots(); }
};

} // e3
#endif // _E3_SK_SEAL_CKKS_H_
