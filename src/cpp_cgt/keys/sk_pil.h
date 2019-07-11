#pragma once

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


        PilBaseEvalKeyExt ekb;

    public:
        PilBasePrivKey(std::string name, bool forceGen,
                       bool forceLoad, std::string seed, int lam);

        virtual std::string decrypt(const std::string & s, string pfx) const;
        virtual std::string encrypt(const std::string & s, int msz, string pfx) const;
        PilBaseEvalKey & getEk() { return ekb; }
        virtual bool load();
        virtual void save();

        virtual string filename() const;

        friend class CircuitPrivKey_pilc;
};

class PilaPrivKey : public PilBasePrivKey
{
    public:
        PilaPrivKey(std::string name, bool forceGen,
                    bool forceLoad, std::string seed, int lam)
            : PilBasePrivKey(name, forceGen, forceLoad, seed, lam) {}
};

} // e3