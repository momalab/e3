// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_CIRC_FHEW_H_
#define _E3_EKX_CIRC_FHEW_H_

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
#endif // _E3_EKX_CIRC_FHEW_H_
