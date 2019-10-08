#pragma once

#include "sk_abstract.h"
#include "ekx_pail.h"
#include "e3util.h"


namespace e3
{

class PailPrivKey : public PrivKey
{
        virtual void gen();

    private:
        Bigun P, Q;
        Bigun ph, phph1;
        void initphi();

        // need for public values, e.g N
        PailEvalKeyExt ekb;

    public:
        PailPrivKey(KeyName name, bool forceGen,
                    bool forceLoad, std::string seed, int lam);

        PailPrivKey(const PailPrivKey &) = default;

        virtual std::string decrypt(const std::string & s) const;
        virtual std::string encrypt(const std::string & s, int msz) const;
        virtual bool load();
        virtual void save();

        virtual string filename() const;

};

class PailgPrivKey : public PailPrivKey
{
    public:
        PailgPrivKey(KeyName name, bool forceGen,
                     bool forceLoad, std::string seed, int lam):
            PailPrivKey(name, forceGen, forceLoad, seed, lam) {}
};

} // e3
