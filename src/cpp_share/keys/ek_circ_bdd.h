#pragma once

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
        ///virtual std::string decor(const std::string &, bool add) const;
};

class CircuitEvalKey_bddn : public CircuitEvalKey_bdd
{
    public:
        CircuitEvalKey_bddn(User u, KeyName name)
            : CircuitEvalKey_bdd(u, name) {}

        ///virtual std::string decor(const std::string &, bool add) const;
};

class CircuitEvalKey_bdda : public CircuitEvalKey_bdd
{
    public:
        CircuitEvalKey_bdda(User u, KeyName name)
            : CircuitEvalKey_bdd(u, name) {}

        ///virtual std::string decor(const std::string &, bool add) const;
};

class CircuitEvalKey_bddf : public CircuitEvalKey_bdd
{
    public:
        CircuitEvalKey_bddf(User u, KeyName name)
            : CircuitEvalKey_bdd(u, name) {}

        ///virtual std::string decor(const std::string &, bool add) const;
};

} // e3
