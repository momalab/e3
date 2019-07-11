#pragma once

#include <vector>

#include "sk_circ.h"
#include "ekx_circ_bdd.h"

class Bbs;

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
        void gen_bbs(Bbs & bbs, string dir, bool hash);
        void gen_enc(Bbs & bbs, string dir, string & encfn, string & decfn);
        static void gen_cir2c(string fn, bool ren);
        void gen_op(string op, string pfx, string decfn,
                    string encfn, string & opfn, string & bddfn);
        bool checkbdd(string name) const;

    public:

        CircuitPrivKey_bdd
        (std::string name, std::string seed, int lam, CircuitEvalKey * ek,
         std::string formula, std::string compile, std::string kernel);

        virtual std::string encbitstr(bool b) const;
        virtual bool decbitstr(const std::string & s, bool * ok) const;

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

    private:
        CircuitEvalKey_bdda_X ek; // this is used only for decorations (decor)

    public:
        CircuitPrivKey_bdda(std::string name, bool forceGen,
                            bool forceLoad, std::string seed,
                            int lam, std::string formula,
                            std::string compile, std::string kernel, bool m);
};

class CircuitPrivKey_bddn : public CircuitPrivKey_bdd
{
        virtual void trygen();
        virtual bool checkio() const;
        bool modifier_xor; // use no-hash for not and xor FIXME o

        using EncBit = std::vector<bool>;

    private:
        CircuitEvalKey_bddn_X ek; // this is used only for decorations (decor)

    public:
        CircuitPrivKey_bddn(std::string name, bool forceGen,
                            bool forceLoad, std::string seed,
                            int lam, std::string formula,
                            std::string compile, std::string kernel, bool m);
};

class CircuitPrivKey_bddf : public CircuitPrivKey_bdd
{
        virtual void trygen();
        virtual bool checkio() const;
        bool modifier_mux;

    private:
        CircuitEvalKey_bddf_X ek; // this is used only for decorations (decor)

    public:
        CircuitPrivKey_bddf(std::string name, bool forceGen,
                            bool forceLoad, std::string seed,
                            int lam, std::string formula,
                            std::string compile, std::string kernel, bool m);
};
