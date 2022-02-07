// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_CIRC_TFHE_H_
#define _E3_EK_CIRC_TFHE_H_

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
        CircuitEvalKey_tfhe(User u, KeyName name)
            : CircuitEvalKey(name), key() { user(u); }

        virtual bool load();

        cTfheNativeEvalKey native() const { return key; }

        virtual std::string filename() const;
};

} // e3
#endif // _E3_EK_CIRC_TFHE_H_
