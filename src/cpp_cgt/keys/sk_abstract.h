// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SK_ABSTRACT_H_
#define _E3_SK_ABSTRACT_H_

#include "e3util.h"
#include "olrnd.h"
#include "anykey.h"

using std::string;

namespace e3
{

class PrivKey : public AnyKey
{
        bool loaded;

    protected:
        mutable cr::Rnd * rnd; // no delete
        int lambda;

        string filenamex(string fx) const { return name.fil + fx + ".secret.key"; }
        virtual string filename() const { return filenamex(""); }

        void init_final(bool forceGen, bool forceLoad);

        // always generate both priv and eval keys and saves
        // this is top level non-virtual function managing freshKey and saving
        void genAndSave();

    private:
        // this function generates both keys it is private and
        //should be privately redefined for descentants
        virtual void gen() = 0;

    public:
        PrivKey(KeyName nm, const string & seed, int lam)
            : AnyKey(nm), loaded(true), rnd(cr::Rnd::newRnd(seed)), lambda(lam) {}

        virtual std::string decrypt(const string & s) const = 0;
        virtual void decrypt(const std::string & s, std::vector<std::complex<double>> & r)  { throw "Cannot decrypt to std::vector<std::complex<double>>."; }
        virtual void decrypt(const std::string & s, std::vector<double> & r)  { throw "Cannot decrypt to std::vector<double>."; }
        virtual void decrypt(const std::string & s, std::vector<int> & r)  { throw "Cannot decrypt to std::vector<int>."; }
        virtual string encrypt(const string & s, int msz) const = 0;

        virtual bool load() = 0;
        virtual void save() = 0;

        bool isLoaded() { return loaded; }
};

} // e3
#endif // _E3_SK_ABSTRACT_H_
