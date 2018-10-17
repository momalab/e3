#pragma once

#include "sk_circ.h"
#include "ekx_circ_tfhe.h"
#include "def_tfhe.h"

class CircuitPrivKey_tfhe : public CircuitPrivKey
{
        virtual void gen();

        using EncBit = TfheNativeBit;
        using SecKey = TfheNativePrivKey;

        EncBit encbit(bool b) const;
        bool decbit(const EncBit & y) const;

    private:
        SecKey key;
        CircuitEvalKey_tfhe_X ek;
        virtual bool load();
        virtual void save();

    public:
        CircuitPrivKey_tfhe(std::string name, bool forceGen,
                            bool forceLoad, std::string seed, int lam);

        virtual std::string encbitstr(bool b) const;
        virtual bool decbitstr(const std::string & s, bool * ok) const;

        virtual string filename();
};
