#pragma once

#include "ek_circ_fhew.h"

namespace e3
{

class CircuitEvalKey_fhew_X : public CircuitEvalKey_fhew
{
    public:
        CircuitEvalKey_fhew_X(KeyName name) : CircuitEvalKey_fhew(User::Alice, name) {}

        void save();
        void save_oleg();
        void save_fhew();
        using CircuitEvalKey_fhew::key;
};

} // e3
