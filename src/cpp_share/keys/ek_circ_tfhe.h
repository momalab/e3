#pragma once

#include "ek_circ.h"
#include "e3util.h"
#include "def_tfhe.h"

namespace e3
{

class CircuitEvalKey_tfhe : public CircuitEvalKey
{
        static const bool NOCOUT = true;

    public:
        using Tnek = TfheNativeEvalKey;

    protected:
        Tnek key;

    public:
        CircuitEvalKey_tfhe(User u, std::string name)
            : CircuitEvalKey(name) { user(u); }

        virtual bool load();

        cTfheNativeEvalKey native() const { return key; }

        virtual std::string filename() const;
};

} // e3
