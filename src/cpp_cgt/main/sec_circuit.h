#pragma once

#include "sectype.h"

class Circuit: public SecType
{
    private:
        std::string encType;
        std::string circDb;
        std::vector<int> sizes; // which circuits (template specializations) to include
        CircuitPrivKey * csk = nullptr; // direct access to bit encryption
        int lambda;

    public:
        Circuit(std::istream & is, string nm);
        ~Circuit() {}

        virtual void writeH(std::ostream & os, string user_dir) const;
        virtual void writeInc(std::ostream & os) const;
        virtual void writeCpp(std::ostream & os) const;
        virtual void copyDependencies() const {}
        virtual void genKeys(bool forceGen, bool forceLoad, std::string seed);
};
