// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_CIRC_HELI_H_
#define _E3_SK_CIRC_HELI_H_

#include "sk_circ.h"
#include "ekx_circ_heli.h"
#include "def_heli.h"

namespace e3
{

class CircuitPrivKey_heli : public CircuitPrivKey
{
        virtual void gen();

        using EncBit = HeliNativeBt;
        using SecKey = HeliNativePrivKey;

        EncBit encbit(bool b) const;
        bool decbit(const EncBit & y) const;

    private:
        NativeProperties * properties;
        SecKey key;

        CircuitEvalKey_heli_X ek;
        virtual bool load();
        virtual void save();

    public:
        CircuitPrivKey_heli(KeyName name, bool forceGen,
                            bool forceLoad, std::string seed, int lam);

        virtual std::vector<bool> decbitstr(const std::string & s, bool * ok) const;
        virtual std::string encbitstr(std::vector<bool> b) const;

        virtual string filename() const;
};

} // e3
#endif // _E3_SK_CIRC_HELI_H_
