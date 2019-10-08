#pragma once

#include "sk_abstract.h"
#include "ekx_arith_seal.h"
#include "e3util.h"

namespace e3
{

class CircuitPrivKey_seal;
class SealBasePrivKey : public PrivKey
{
        // using Ciphertext = SealCiphertext;
        virtual void gen();

    private:
        SealNativePrivKey key;
        SealBaseEvalKeyExt ek;

        uint64_t polyModulusDegree = 1 << 15;
        uint64_t plainModulus = 2;

    protected:
        virtual bool load();
        virtual void save();

    public:
        SealBasePrivKey(KeyName name, bool forceGen,
                        bool forceLoad, string seed, int lam,
                        string polyModulusDegree, string plainModulus);
        SealBasePrivKey(const SealBasePrivKey &) = default;
        SealBasePrivKey(const SealBasePrivKey & k, string nm)
            : SealBasePrivKey(k) { ek.name.typ = name.typ = nm; }

        virtual string decrypt(const string & s) const;
        virtual string encrypt(const string & s, int msz) const;
        virtual string filename() const;

        friend class CircuitPrivKey_seal;
        friend class SealPrivKey;
};

class SealPrivKey : public SealBasePrivKey
{
    public:
        SealPrivKey(KeyName name, bool forceGen,
                    bool forceLoad, string seed, int lam,
                    string polyModulusDegree, string plainModulus)
            : SealBasePrivKey(name, forceGen, forceLoad, seed, lam, polyModulusDegree, plainModulus) {}

        SealPrivKey(const SealBasePrivKey & privkey, string nm)
            : SealBasePrivKey(privkey, nm) {}
};

} // e3
