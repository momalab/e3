#pragma once

#include "ek_circ_tfhe.h"

class CircuitEvalKey_tfhe_X : public CircuitEvalKey_tfhe
{
    public:
        CircuitEvalKey_tfhe_X(std::string name) : CircuitEvalKey_tfhe(User::Alice, name) {}

        void save();
        using CircuitEvalKey_tfhe::key;
};
