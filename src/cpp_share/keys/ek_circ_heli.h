// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_CIRC_HELI_H_
#define _E3_EK_CIRC_HELI_H_

#include "ek_circ.h"
#include "e3util.h"
#include "def_heli.h"

namespace e3
{

class CircuitEvalKey_heli : public CircuitEvalKey
{
        static const bool NOCOUT = true;

    public:
        using Hnek = HeliNativeEvalKey;
        NativeProperties * properties = nullptr;

    protected:
        Hnek key;

    public:
        CircuitEvalKey_heli(User u, KeyName name)
            : CircuitEvalKey(name), key() { user(u); }

        virtual bool load();

        cHeliNativeEvalKey native() const { return key; }

        virtual std::string filename() const;
};

} // e3
#endif // _E3_EK_CIRC_HELI_H_
