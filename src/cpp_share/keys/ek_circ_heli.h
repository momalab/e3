#pragma once

#include "ek_circ.h"
#include "e3util.h"
#include "def_heli.h"

class CircuitEvalKey_heli : public CircuitEvalKey
{
        static const bool NOCOUT = true;

    public:
        using Hnek = HeliNativeEvalKey;
        NativeProperties * properties;

    protected:
        Hnek key;

    public:
        CircuitEvalKey_heli(User u, std::string name)
            : CircuitEvalKey(name) { user(u); }

        virtual bool load();

        cHeliNativeEvalKey native() const { return key; }

        virtual std::string filename() const;
};
