#pragma once

#include "sk_circ.h"
#include "ekx_circ_fhew.h"
#include "def_fhew.h"

namespace e3
{

class CircuitPrivKey_fhew : public CircuitPrivKey
{
        virtual void gen();

        using EncBit = FhewNativeBt;
        using SecKey = FhewNativePrivKey;

        EncBit encbit(bool b) const;
        bool decbit(const EncBit & y) const;

    private:
        SecKey key;
        CircuitEvalKey_fhew_X ek;
        virtual bool load();
        virtual void save();

    public:
        CircuitPrivKey_fhew(KeyName name, bool forceGen,
                            bool forceLoad, std::string seed, int lam);

        virtual std::string encbitstr(bool b) const;
        virtual bool decbitstr(const std::string & s, bool * ok) const;

        virtual string filename() const;
};

} // e3
