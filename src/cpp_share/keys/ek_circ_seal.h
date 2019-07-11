#pragma once

#include "ek_circ.h"
#include "e3util.h"
#include "def_seal.h"

namespace e3
{

class CircuitEvalKey_seal : public CircuitEvalKey
{
        static const bool NOCOUT = true;

    public:
        using Snek = SealNativeEvalKey;

    protected:
        Snek key;

    public:
        CircuitEvalKey_seal(User u, std::string name)
            : CircuitEvalKey(name) { user(u); }

        virtual bool load();

        cSealNativeEvalKey native() const { return key; }

        virtual std::string filename() const;
};

} // e3
