#pragma once

#include "ek_circ.h"
#include "e3util.h"
///#include "def_bddn.h"

class CircuitEvalKey_bddn : public CircuitEvalKey
{
        static const bool NOCOUT = true;

    public:
        using Bnek = int; // FIXME o

    protected:
        Bnek key;

    public:
        CircuitEvalKey_bddn(User u, std::string name)
            : CircuitEvalKey(name) { user(u); }

        virtual bool load();
        virtual std::string decor(const std::string &, bool add) const;

        virtual std::string filename();
};
