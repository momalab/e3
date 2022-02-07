// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_CIRC_BDD_H_
#define _E3_SK_CIRC_BDD_H_

#include <vector>

#include "sk_circ.h"
#include "ekx_circ_bdd.h"


namespace e3
{

namespace cr { class Bbs; }

class CircuitPrivKey_bdd : public CircuitPrivKey
{
        using SecKey = std::string;

        virtual bool load();
        virtual void save();
        virtual void gen();
        virtual void trygen() = 0;
        virtual bool checkio() const = 0;

    protected:
        SecKey key;
        string xdir;

        static string default_formula() { return "FLF"; }
        static string default_kernel() { return "default"; }

        string hg_name(string n) const { return xdir + "op_" + n; }
        string bd_name(string n) const { return xdir + "bdd_" + n; }

        string formula;
        string compile;
        string kernel;

        void gen_init(string & tid, string & dir);
        void gen_bbs(cr::Bbs & bbs, string dir, bool hash);
        void gen_enc(cr::Bbs & bbs, string dir, string & encfn, string & decfn);
        static void gen_cir2c(string fn, bool ren);
        void gen_op(string op, string pfx, string decfn,
                    string encfn, string & opfn, string & bddfn);
        bool checkbdd(string name) const;

    public:

        CircuitPrivKey_bdd
        (KeyName name, std::string seed, int lam,
         std::string formula, std::string compile, std::string kernel);

        virtual std::vector<bool> decbitstr(const std::string & s, bool * ok) const;
        virtual std::string encbitstr(std::vector<bool> b) const;

        virtual string filename() const;
        string filecpp() const;
        string fileexe() const;

        virtual std::string getTid() const { return key; }
};

class CircuitPrivKey_bdda : public CircuitPrivKey_bdd
{
        virtual void trygen();
        virtual bool checkio() const;
        bool modifier_not;

    public:
        CircuitPrivKey_bdda(KeyName name, bool forceGen,
                            bool forceLoad, std::string seed,
                            int lam, std::string formula,
                            std::string compile, std::string kernel, bool m);
};

class CircuitPrivKey_bddn : public CircuitPrivKey_bdd
{
        virtual void trygen();
        virtual bool checkio() const;
        bool modifier_xor;

        using EncBit = std::vector<bool>;

    public:
        CircuitPrivKey_bddn(KeyName name, bool forceGen,
                            bool forceLoad, std::string seed,
                            int lam, std::string formula,
                            std::string compile, std::string kernel, bool m);
};

class CircuitPrivKey_bddf : public CircuitPrivKey_bdd
{
        virtual void trygen();
        virtual bool checkio() const;
        bool modifier_mux;

    public:
        CircuitPrivKey_bddf(KeyName name, bool forceGen,
                            bool forceLoad, std::string seed,
                            int lam, std::string formula,
                            std::string compile, std::string kernel, bool m);
};

} // e3
#endif // _E3_SK_CIRC_BDD_H_
