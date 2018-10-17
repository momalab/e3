#pragma once

#include "ek_circ.h"
#include "sk_abstract.h"

class CircuitPrivKey : public PrivKey
{
    private: // important
        std::string encrypt_cir(const std::string & s, int ptsz) const;
        std::string decrypt_cir(const std::string & s) const;

        // reference to the right EvalKey, needed for EK decoration function
        CircuitEvalKey * pek;

        // end of private section (do not change privacy)

    public:
        CircuitPrivKey(string name, const string & seed, int lam, CircuitEvalKey * k)
            : PrivKey(name, seed, lam), pek(k) {}

        virtual std::string encbitstr(bool b) const = 0;
        virtual bool decbitstr(const std::string & s, bool * ok) const = 0;

        virtual std::string encrypt(const std::string & s, int ptsz) const;
        virtual std::string decrypt(const std::string & s) const;
};
