#pragma once

#include "sk_circ.h"
#include "ekx_circ_plain.h"

namespace e3
{

class CircuitPrivKey_plain : public CircuitPrivKey
{
        virtual void gen();

        e3util::usi encbitUsi(bool b) const { return ek.enc(b, key); }
        bool decbitUsi(e3util::usi y) const { return ek.dec(y, key); }

    private:
        e3util::usi key;
        CircuitEvalKey_plain_X ek; // used for dec+enc
        virtual bool load();
        virtual void save();

    public:
        CircuitPrivKey_plain(KeyName name, bool forceGen,
                             bool forceLoad, std::string seed);

        virtual std::string encbitstr(bool b) const;
        virtual bool decbitstr(const std::string & s, bool * ok) const;
};

} // e3
