// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_CIRC_PLAIN_H_
#define _E3_SK_CIRC_PLAIN_H_

#include "sk_circ.h"
#include "ekx_circ_plain.h"

namespace e3
{

class CircuitPrivKey_plain : public CircuitPrivKey
{
        virtual void gen();

        bool decbitUsi(e3::util::usi y) const { return ek.dec(y, key); }
        e3::util::usi encbitUsi(bool b) const { return ek.enc(b, key); }

    private:
        e3::util::usi key;
        CircuitEvalKey_plain_X ek; // used for dec+enc
        virtual bool load();
        virtual void save();

    public:
        CircuitPrivKey_plain(KeyName name, bool forceGen,
                             bool forceLoad, std::string seed);

        virtual std::vector<bool> decbitstr(const std::string & s, bool * ok) const;
        virtual std::string encbitstr(std::vector<bool> b) const;
};

} // e3
#endif // _E3_SK_CIRC_PLAIN_H_
