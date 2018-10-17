#pragma once

#include "ek_circ.h"
#include "e3util.h"
#include "def_tfhe.h"

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
        virtual std::string decor(const std::string &, bool add) const;

        cTfheNativeEvalKey native() const { return key; }

        virtual std::string filename();
};
