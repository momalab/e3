// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_PAIL_H_
#define _E3_SK_PAIL_H_

#include "sk_abstract.h"
#include "ekx_pail.h"
#include "e3util.h"


namespace e3
{

class PailBasePrivKey : public PrivKey
{
    protected:
        virtual void gen();
        void genBase();

    protected:
        Bigun P, Q;
        Bigun ph, phph1;
        void initphi();

        // need for public values, e.g N
        PailEvalKeyExt ekb;

    public:
        PailBasePrivKey(KeyName name,
                        std::string seed, int lam);

        PailBasePrivKey(const PailBasePrivKey &) = default;

        virtual std::string decrypt(const std::string & s) const;
        virtual std::string encrypt(const std::string & s, int msz) const;
        virtual bool load();
        virtual void save();

        virtual string filename() const;
};


class PailPrivKey : public PailBasePrivKey
{
        virtual void gen();

    public:
        PailPrivKey(KeyName name, bool forceGen,
                    bool forceLoad, std::string seed, int lam);

        PailPrivKey(const PailPrivKey &) = default;
};

class PailgPrivKey : public PailBasePrivKey
{
        virtual void gen();

        int beta;

    public:
        PailgPrivKey(KeyName name, bool forceGen,
                     bool forceLoad, std::string seed, int lam, int b);

        Bigun getFkf() const { return phph1; }
};

} // e3

#endif // _E3_SK_PAIL_H_
