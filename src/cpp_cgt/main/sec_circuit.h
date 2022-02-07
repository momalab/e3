// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SEC_CIRCUIT_H_
#define _E3_SEC_CIRCUIT_H_

#include "sectype.h"

class Circuit: public SecType
{
    private:

        std::string basType; // Generic type BDD for all BDDs

        std::string circDb;
        std::vector<int> sizes; // which circuits (template specializations) to include
        e3::CircuitPrivKey * csk = nullptr; // direct access to bit encryption
        std::string formula; // Circle formula
        std::string compile; // optional compilation key command
        std::string kernel; // Circle kernel
        int modifier; // use mux / use neg gates

        std::string polyModulusDegree; // Seal
        std::string plaintextModulus; // Seal
        std::string encoder; // Seal

        virtual void fixEncType();
        string loadDbTemplCir(string root, string fn) const;

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
#endif // _E3_SEC_CIRCUIT_H_
