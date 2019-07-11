#pragma once

#include "sk_circ.h"
#include "ekx_circ_pil.h"
#include "def_pil.h"
#include "sk_pil.h"

namespace e3
{

class CircuitPrivKey_pilc : public CircuitPrivKey
{
        using Bit = e3::PilQuad;
        virtual void gen();

        Bit encbit(bool b) const;
        bool decbit(const Bit & y) const;

    private:
        CircuitEvalKey_pilc_X ekx;
        PilBasePrivKey sk;

        virtual bool load();
        virtual void save() { sk.save(); }

    public:
        CircuitPrivKey_pilc(std::string name, bool forceGen,
                            bool forceLoad, std::string seed, int lam);

        CircuitPrivKey_pilc(const PilBasePrivKey & pil);

        virtual std::string encbitstr(bool b) const;
        virtual bool decbitstr(const std::string & s, bool * ok) const;

        virtual string filename() const { return sk.filename(); }
};

} // e3
