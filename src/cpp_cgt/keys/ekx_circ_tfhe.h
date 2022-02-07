// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EKX_CIRC_TFHE_H_
#define _E3_EKX_CIRC_TFHE_H_

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
#endif // _E3_EKX_CIRC_TFHE_H_
