#pragma once

#include "sk_circ.h"
#include "ekx_circ_heli.h"
#include "def_heli.h"

class CircuitPrivKey_heli : public CircuitPrivKey
{
        virtual void gen();

        using EncBit = HeliNativeBit;
        using SecKey = HeliNativePrivKey;

        EncBit encbit(bool b) const;
        bool decbit(const EncBit & y) const;

    private:
        NativeProperties * properties;
        SecKey key;

        CircuitEvalKey_heli_X ek;
        virtual bool load();
        virtual void save();

        ///void init_properties();
        ///static void init_properties(NativeProperties ** ppprop, string &name);

    public:
        CircuitPrivKey_heli(std::string name, bool forceGen,
                            bool forceLoad, std::string seed, int lam);

        virtual std::string encbitstr(bool b) const;
        virtual bool decbitstr(const std::string & s, bool * ok) const;

        virtual string filename();
};
