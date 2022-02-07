// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SEC_NATIVE_H_
#define _E3_SEC_NATIVE_H_

#include "sectype.h"

class Native : public SecType
{
        virtual void fixEncType() {}

    public:
        Native(std::istream & is, string nm);
        ~Native() {}

        virtual void writeH(string root, std::ostream & os, string user_dir) const;
        virtual void writeInc(string root, std::ostream & os) const;
        virtual void writeCpp(string root, std::ostream & os) const;
        virtual void copyDependencies() const {}
        virtual void genKeys(bool forceGen, bool forceLoad,
                             std::string seed, const ConfigParser * par);
};
#endif // _E3_SEC_NATIVE_H_
