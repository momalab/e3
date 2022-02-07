// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SEC_PARTIAL_H_
#define _E3_SEC_PARTIAL_H_

#include "sectype.h"

class Modular : public SecType
{
    private:

        virtual void fixEncType();
        string loadDbTemplAri(string root, string fn) const;
        std::string polyModulusDegree; // Seal
        std::string plaintextModulus; // Seal
        std::string encoder; // Seal
        int beta; // PaillierG
        std::string copheeIsArduino = "false";
        std::string copheeBaudRate = "921600";
        std::string scale; // Seal CKKS
        std::string primes; // Seal CKKS
        std::string smuldepth; // circuit depth, used by Pali
        int useSlots = 1;
        std::string smaxdepth; // circuit depth, used by Pali
        std::string sp_n; // param n, used by Pali
        std::string rotations, rescale; // Palisade CKKS
        std::map<std::string, std::string> params; // used by Palisade CKKS (trying to standardize)

    public:
        Modular(std::istream & is, string nm, const std::map<string, string> & globs);
        ~Modular() {}

        virtual void writeH(string root, std::ostream & os, string user_dir) const;
        virtual void writeInc(string root, std::ostream & os) const;
        virtual void writeCpp(string root, std::ostream & os) const;
        virtual void copyDependencies() const {}
        virtual void genKeys(bool forceGen, bool forceLoad,
                             std::string seed, const ConfigParser * par);
};
#endif // _E3_SEC_PARTIAL_H_
