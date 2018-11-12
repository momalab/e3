#pragma once

#include "sk_circ.h"
#include "ekx_circ_bddn.h"
///#include "def_bddn.h"

class CircuitPrivKey_bddn : public CircuitPrivKey
{
        virtual void gen();

        using EncBit = int; // FIXME o
        using SecKey = int; // FIXME o

        EncBit encbit(bool b) const;
        bool decbit(const EncBit & y) const;

    private:
        SecKey key;
        CircuitEvalKey_bddn_X ek;
        virtual bool load();
        virtual void save();

    public:
        CircuitPrivKey_bddn(std::string name, bool forceGen,
                            bool forceLoad, std::string seed, int lam);

        virtual std::string encbitstr(bool b) const;
        virtual bool decbitstr(const std::string & s, bool * ok) const;

        virtual string filename();
};
