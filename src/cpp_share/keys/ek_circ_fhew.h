// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_CIRC_FHEW_H_
#define _E3_EK_CIRC_FHEW_H_

#include "ek_circ.h"
#include "e3util.h"
#include "def_fhew.h"

namespace e3
{

class CircuitEvalKey_fhew : public CircuitEvalKey
{
        static const bool NOCOUT = false;

    public:
        using Fnek = FhewNativeEvalKey;

    protected:
        Fnek key;

    public:
        CircuitEvalKey_fhew(User u, KeyName name)
            : CircuitEvalKey(name), key() { user(u); }

        bool load_oleg();
        bool load_fhew();
        virtual bool load();

        cFhewNativeEvalKey native() const { return key; }

        virtual std::string filename() const;
};

} // e3
#endif // _E3_EK_CIRC_FHEW_H_
