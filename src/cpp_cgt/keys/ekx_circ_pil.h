// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_CIRC_PIL_H_
#define _E3_EKX_CIRC_PIL_H_

#include "ek_circ_pil.h"

namespace e3
{

class CircuitEvalKey_pilc_X : public CircuitEvalKey_pilc
{
    public:
        CircuitEvalKey_pilc_X(KeyName name) : CircuitEvalKey_pilc(User::Alice, name) {}

        void save();
        using CircuitEvalKey_pilc::bek;
};

} // e3
#endif // _E3_EKX_CIRC_PIL_H_
