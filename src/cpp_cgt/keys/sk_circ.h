#pragma once

#include "ek_circ.h"
#include "sk_abstract.h"

namespace e3
{

class CircuitPrivKey : public PrivKey
{
    private: // important
        std::string encrypt_cir(const std::string & s, int ptsz) const;
        std::string decrypt_cir(const std::string & s) const;

        /// reference to the right EvalKey, needed for EK decoration function
        ///CircuitEvalKey * pek;

        // end of private section (do not change privacy)

    public:
        CircuitPrivKey(KeyName name, const string & seed, int lam)
            : PrivKey(name, seed, lam) {}
        ///CircuitPrivKey(KeyName name, const string & seed, int lam, CircuitEvalKey * k)
        ///    : PrivKey(name, seed, lam), pek(k) {}

        virtual std::string encbitstr(bool b) const = 0;
        virtual bool decbitstr(const std::string & s, bool * ok) const = 0;

        virtual std::string encrypt(const std::string & s, int ptsz) const;
        virtual std::string decrypt(const std::string & s) const;

        virtual std::string getTid() const { return "TidNotExist"; }
};

// External encryption (maybe need to be extracted into a separate file)
class CircuitPrivKey_ext : public CircuitPrivKey
{
        virtual bool load() { return true; }
        virtual void save() {}
        virtual void gen() {}
    public:
        CircuitPrivKey_ext() : CircuitPrivKey(KeyName(), "", 0) {}
        virtual bool decbitstr(const std::string & s, bool * ok) const { throw "dec extern"; }
        virtual std::string encbitstr(bool b) const { return b ? "1" : "0"; }
};

} // e3
