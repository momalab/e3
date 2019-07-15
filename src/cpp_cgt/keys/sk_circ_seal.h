#pragma once

#include "sk_circ.h"
#include "ekx_circ_seal.h"
#include "def_seal.h"

namespace e3
{

class CircuitPrivKey_seal : public CircuitPrivKey
{
        virtual void gen();

        using EncBit = SealNativeBt;
        using SecKey = SealNativePrivKey;

        EncBit encbit(bool b) const;
        bool decbit(const EncBit & y) const;

    private:
        SecKey key;
        CircuitEvalKey_seal_X ek;
        virtual bool load();
        virtual void save();

    public:
        CircuitPrivKey_seal(KeyName name, bool forceGen,
                            bool forceLoad, std::string seed, int lam);

        virtual std::string encbitstr(bool b) const;
        virtual bool decbitstr(const std::string & s, bool * ok) const;

        virtual string filename() const;
};

} // e3
