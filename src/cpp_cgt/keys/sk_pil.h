// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_PIL_H_
#define _E3_SK_PIL_H_

#include "sk_abstract.h"
#include "ekx_pil.h"
#include "e3util.h"

// this header defines 2 classes PilBase and Pila
// Pilc is defined in circuit header

namespace e3
{

class CircuitPrivKey_pilc;
class PilBasePrivKey : public PrivKey
{
        using Bit = e3::PilQuad;
        virtual void gen();

    private:
        struct Matrix
        {
            e3::PilNum d11, d12, d21, d22;
            e3::PilNum det() const;
        };
        void initmatrix();
        void invertL();
        void findT();
        void initNS(PilEvalValues & kv);
        void initAF(PilEvalValues & kv);

        Bit rotate_tr(const Bit & bit, const Matrix & mx) const;

        bool mxinited = false;

        Bigun P, Q, phi;
        Matrix L, Li;
        PilNum T;

        // need for public values, e.g N
        PilBaseEvalKeyExt ekb;

    protected:
        virtual bool load();
        virtual void save();

    public:
        PilBasePrivKey(KeyName name, bool forceGen,
                       bool forceLoad, std::string seed, int lam);

        PilBasePrivKey(const PilBasePrivKey &) = default;
        PilBasePrivKey(const PilBasePrivKey & k, string nm)
            : PilBasePrivKey(k) { ekb.name.typ = name.typ = nm; }

        virtual std::string decrypt(const std::string & s) const;
        virtual std::string encrypt(const std::string & s, int msz) const;

        virtual string filename() const;

        friend class CircuitPrivKey_pilc;
        friend class PilaPrivKey;
};

class PilaPrivKey : public PilBasePrivKey
{
    public:
        PilaPrivKey(KeyName name, bool forceGen,
                    bool forceLoad, std::string seed, int lam)
            : PilBasePrivKey(name, forceGen, forceLoad, seed, lam) {}

        PilaPrivKey(const PilBasePrivKey & pil, string nm)
            : PilBasePrivKey(pil, nm) {}
};

} // e3
#endif // _E3_SK_PIL_H_
