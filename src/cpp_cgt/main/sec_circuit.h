#pragma once

#include "sectype.h"

class Circuit: public SecType
{
    private:

        std::string basType; // Generic type BDD for all BDDs

        std::string circDb;
        std::vector<int> sizes; // which circuits (template specializations) to include
        e3::CircuitPrivKey * csk = nullptr; // direct access to bit encryption
        ///int lambda;
        std::string formula; // Circle formula
        std::string compile; // optional compilation key command
        std::string kernel; // Circle kernel
        int modifier; // use mux / use neg gates

        virtual void fixEncType();

    public:
        Circuit(std::istream & is, string nm, const std::map<string, string> & globs);
        ~Circuit() {}

        virtual void writeH(string root, std::ostream & os, string user_dir) const;
        virtual void writeInc(string root, std::ostream & os) const;
        virtual void writeCpp(string root, std::ostream & os) const;
        virtual void copyDependencies() const {}
        virtual void genKeys(bool forceGen, bool forceLoad,
                             string seed, const ConfigParser * par);
};
