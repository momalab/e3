#pragma once

#include "ek_circ_bdd.h"

// FIXME o these clases can be removed - we do not save BDD public kays

class CircuitEvalKey_bddn_X : public CircuitEvalKey_bddn
{
    public:
        CircuitEvalKey_bddn_X(std::string name) : CircuitEvalKey_bddn(User::Alice, name) {}

        void save();
        using CircuitEvalKey_bddn::key;
};

class CircuitEvalKey_bdda_X : public CircuitEvalKey_bdda
{
    public:
        CircuitEvalKey_bdda_X(std::string name) : CircuitEvalKey_bdda(User::Alice, name) {}

        void save();
        using CircuitEvalKey_bdda::key;
};

class CircuitEvalKey_bddf_X : public CircuitEvalKey_bddf
{
    public:
        CircuitEvalKey_bddf_X(std::string name) : CircuitEvalKey_bddf(User::Alice, name) {}

        void save();
        using CircuitEvalKey_bddf::key;
};
