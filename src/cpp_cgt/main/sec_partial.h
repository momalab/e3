#ifndef _E3_SEC_PARTIAL_H_
#define _E3_SEC_PARTIAL_H_

#include "sectype.h"

class Partial : public SecType
{
    private:

        virtual void fixEncType();
        string loadDbTemplAri(string root, string fn) const;
        std::string polyModulusDegree; // Seal
        std::string plaintextModulus; // Seal
        std::string encoder; // Seal
        int beta; // PaillierG

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
#endif // _E3_SEC_PARTIAL_H_
