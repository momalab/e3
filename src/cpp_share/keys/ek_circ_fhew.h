#pragma once

#include "ek_circ.h"
#include "e3util.h"
#include "def_fhew.h"

class CircuitEvalKey_fhew : public CircuitEvalKey
{
        static const bool NOCOUT = false;

    public:
        using Fnek = FhewNativeEvalKey;

    protected:
        Fnek key;

    public:
        CircuitEvalKey_fhew(User u, std::string name)
            : CircuitEvalKey(name) { user(u); }

        bool load_oleg();
        bool load_fhew();
        virtual bool load();

        cFhewNativeEvalKey native() const { return key; }

        virtual std::string filename() const;
};
