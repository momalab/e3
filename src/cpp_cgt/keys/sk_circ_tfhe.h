// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_CIRC_TFHE_H_
#define _E3_SK_CIRC_TFHE_H_

#include "sk_circ.h"
#include "ekx_circ_tfhe.h"
#include "def_tfhe.h"

namespace e3
{

class CircuitPrivKey_tfhe : public CircuitPrivKey
{
        virtual void gen();

        using EncBit = TfheNativeBt;
        using SecKey = TfheNativePrivKey;

        EncBit encbit(bool b) const;
        bool decbit(const EncBit & y) const;

    private:
        SecKey key;
        CircuitEvalKey_tfhe_X ek;
        virtual bool load();
        virtual void save();

    public:
        CircuitPrivKey_tfhe(KeyName name, bool forceGen,
                            bool forceLoad, std::string seed, int lam);

        virtual std::vector<bool> decbitstr(const std::string & s, bool * ok) const;
        virtual std::string encbitstr(std::vector<bool> b) const;

        virtual string filename() const;
};

} // e3
#endif // _E3_SK_CIRC_TFHE_H_
