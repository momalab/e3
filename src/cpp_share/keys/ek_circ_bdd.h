// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_EK_CIRC_BDD_H_
#define _E3_EK_CIRC_BDD_H_

#include "ek_circ.h"
#include "e3util.h"

namespace e3
{

class CircuitEvalKey_bdd : public CircuitEvalKey
{
        static const bool NOCOUT = true;

    public:
        using Bnek = std::string;

    protected:
        Bnek key;

    public:
        CircuitEvalKey_bdd(User u, KeyName name)
            : CircuitEvalKey(name) { user(u); }

        virtual bool load();

        virtual std::string filename() const;
};

class CircuitEvalKey_bddn : public CircuitEvalKey_bdd
{
    public:
        CircuitEvalKey_bddn(User u, KeyName name)
            : CircuitEvalKey_bdd(u, name) {}
};

class CircuitEvalKey_bdda : public CircuitEvalKey_bdd
{
    public:
        CircuitEvalKey_bdda(User u, KeyName name)
            : CircuitEvalKey_bdd(u, name) {}
};

class CircuitEvalKey_bddf : public CircuitEvalKey_bdd
{
    public:
        CircuitEvalKey_bddf(User u, KeyName name)
            : CircuitEvalKey_bdd(u, name) {}
};

} // e3
#endif // _E3_EK_CIRC_BDD_H_
