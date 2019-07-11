#pragma once

#include "ek_circ.h"
#include "e3util.h"

// FIXME add e3 namespace for all classes

class CircuitEvalKey_bdd : public CircuitEvalKey
{
        static const bool NOCOUT = true;

    public:
        using Bnek = std::string;

    protected:
        Bnek key;

    public:
        CircuitEvalKey_bdd(User u, std::string name)
            : CircuitEvalKey(name) { user(u); }

        virtual bool load();

        virtual std::string filename() const;
        ///virtual std::string decor(const std::string &, bool add) const;
};

class CircuitEvalKey_bddn : public CircuitEvalKey_bdd
{
    public:
        CircuitEvalKey_bddn(User u, std::string name)
            : CircuitEvalKey_bdd(u, name) {}

        ///virtual std::string decor(const std::string &, bool add) const;
};

class CircuitEvalKey_bdda : public CircuitEvalKey_bdd
{
    public:
        CircuitEvalKey_bdda(User u, std::string name)
            : CircuitEvalKey_bdd(u, name) {}

        ///virtual std::string decor(const std::string &, bool add) const;
};

class CircuitEvalKey_bddf : public CircuitEvalKey_bdd
{
    public:
        CircuitEvalKey_bddf(User u, std::string name)
            : CircuitEvalKey_bdd(u, name) {}

        ///virtual std::string decor(const std::string &, bool add) const;
};
