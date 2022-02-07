// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_CIRC_H_
#define _E3_SK_CIRC_H_

#include <vector>
#include "ek_circ.h"
#include "sk_abstract.h"

namespace e3
{

class CircuitPrivKey : public PrivKey
{
    private: // important
        std::string encrypt_cir(const std::string & s, int ptsz) const;
        std::string decrypt_cir(const std::string & s) const;


    public:
        CircuitPrivKey(KeyName name, const string & seed, int lam)
            : PrivKey(name, seed, lam) {}

        virtual std::vector<bool> decbitstr(const std::string & s, bool * ok) const = 0;
        virtual std::string encbitstr(std::vector<bool> b) const = 0;

        virtual std::string decrypt(const std::string & s) const;
        virtual std::string encrypt(const std::string & s, int ptsz) const;

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

        virtual std::vector<bool> decbitstr
        (const std::string & s, bool * ok)
        const { throw "dec extern"; }

        virtual std::string encbitstr(std::vector<bool> b)
        const { return b[0] ? "1" : "0"; }
};

} // e3
#endif // _E3_SK_CIRC_H_
