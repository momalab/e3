// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SEC_BRIDGE_H_
#define _E3_SEC_BRIDGE_H_

#include <string>
#include <vector>

#include "sectype.h"

using std::string;

class Bridge : public SecType
{
    private:
        string module;
        std::vector<SecType *> registered;
        std::string polyModulusDegree; // Seal
        std::string plaintextModulus; // Seal
        std::string encoder; // Seal

        virtual void fixEncType() {}

        enum class Ext { H, Inc, Cpp };
        bool needModDb(Ext f) const;

        string loadDbTemplBri(string root, string fn) const;

    public:
        Bridge(std::istream & is, string nm, const std::map<string, string> & globs);
        ~Bridge() {}

        virtual void writeH(string root, std::ostream & os, string user_dir) const;
        virtual void writeInc(string root, std::ostream & os) const;
        virtual void writeCpp(string root, std::ostream & os) const;
        virtual void copyDependencies() const {}
        virtual void genKeys(bool forceGen, bool forceLoad,
                             std::string seed, const ConfigParser * par);

        virtual const Bridge * getBridge() const { return this; }
        virtual Bridge * getBridge() { return this; }

        void regist(SecType * st, int index);
        bool isConnected(int size) const;
        int getLam() const { return lambda; }
};
#endif // _E3_SEC_BRIDGE_H_
