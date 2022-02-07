// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_CIRC_GATCOU_H_
#define _E3_EK_CIRC_GATCOU_H_

#include "ek_circ.h"
#include "e3util.h"

namespace e3
{

class CircuitEvalKey_gatcou : public CircuitEvalKey
{
        static const bool NOCOUT = false;

    public: // let nameBit directly access

    public:
        CircuitEvalKey_gatcou(User u, KeyName name)
            : CircuitEvalKey(name) { user(u); }

        virtual bool load() { return true; }
        virtual std::string filename() const { return EvalKey::filename(); }

    private:
        void dummy() const;
};

using CircuitEvalKey_gatcow = CircuitEvalKey_gatcou;

} // e3
#endif // _E3_EK_CIRC_GATCOU_H_
