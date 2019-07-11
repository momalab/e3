#pragma once

#include <string>
#include <vector>

#include "sectype.h"

using std::string;

class Bridge : public SecType
{
    private:
        ///int lambda;
        string module;
        std::vector<SecType *> registered;

        virtual void fixEncType() {}

        enum class Ext { H, Inc, Cpp };
        bool needModDb(Ext f) const;

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
