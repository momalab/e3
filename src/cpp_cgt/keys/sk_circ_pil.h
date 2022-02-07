// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_CIRC_PIL_H_
#define _E3_SK_CIRC_PIL_H_

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
        PilBasePrivKey sk;

        virtual bool load();
        virtual void save() { sk.save(); }

    public:
        CircuitPrivKey_pilc(KeyName name, bool forceGen,
                            bool forceLoad, std::string seed, int lam);

        CircuitPrivKey_pilc(const PilBasePrivKey & pil, string nm);

        virtual std::vector<bool> decbitstr(const std::string & s, bool * ok) const;
        virtual std::string encbitstr(std::vector<bool> b) const;

        virtual string filename() const { return sk.filename(); }
};

} // e3
#endif // _E3_SK_CIRC_PIL_H_
