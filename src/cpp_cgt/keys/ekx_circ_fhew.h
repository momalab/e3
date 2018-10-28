#pragma once

#include "ek_circ_fhew.h"

class CircuitEvalKey_fhew_X : public CircuitEvalKey_fhew
{
    public:
        CircuitEvalKey_fhew_X(std::string name) : CircuitEvalKey_fhew(User::Alice, name) {}

        void save();
        void save_oleg();
        void save_fhew();
        using CircuitEvalKey_fhew::key;
};
