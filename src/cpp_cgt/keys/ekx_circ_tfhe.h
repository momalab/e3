#pragma once

#include "ek_circ_tfhe.h"

namespace e3
{

class CircuitEvalKey_tfhe_X : public CircuitEvalKey_tfhe
{
    public:
        CircuitEvalKey_tfhe_X(KeyName name) : CircuitEvalKey_tfhe(User::Alice, name) {}

        void save();
        using CircuitEvalKey_tfhe::key;
};

} // e3
