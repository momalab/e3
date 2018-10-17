#pragma once

#include "sectype.h"

class Native : public SecType
{
    public:
        Native(std::istream & is, string nm);
        ~Native() {}

        virtual void writeH(std::ostream & os, string user_dir) const;
        virtual void writeInc(std::ostream & os) const;
        virtual void writeCpp(std::ostream & os) const;
        virtual void copyDependencies() const {}
        virtual void genKeys(bool forceGen, bool forceLoad, std::string seed);
};
