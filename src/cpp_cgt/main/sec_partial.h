#pragma once

#include "sectype.h"

class Partial : public SecType
{
    private:

        ///int lambda;

        virtual void fixEncType();

    public:
        Partial(std::istream & is, string nm, const std::map<string, string> & globs);
        ~Partial() {}

        virtual void writeH(string root, std::ostream & os, string user_dir) const;
        virtual void writeInc(string root, std::ostream & os) const;
        virtual void writeCpp(string root, std::ostream & os) const;
        virtual void copyDependencies() const {}
        virtual void genKeys(bool forceGen, bool forceLoad,
                             std::string seed, const ConfigParser * par);
};
