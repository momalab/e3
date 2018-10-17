#pragma once

#include "e3util.h"
#include "cgtrnd.h"
#include "anykey.h"

using std::string;

class PrivKey : public AnyKey
{
        bool loaded;

    protected:
        mutable e3util::ull salt;
        util::Rnd rnd;
        int lambda;

        virtual string filename() { return name + ".priv.key"; }
        void init_final(bool forceGen, bool forceLoad);

        // always generate both priv and eval keys and saves
        // this is top level non-virtual function managing freshKey and saving
        void genAndSave();

    private:
        // this function generates both keys it is private and
        //should be privately redefined for descentants
        virtual void gen() = 0;

    public:
        PrivKey(string nm, const string & seed, int lam)
            : AnyKey(nm), loaded(true), rnd(seed), lambda(lam) {}

        virtual string decrypt(const string & s) const = 0;
        virtual string encrypt(const string & s, int msz) const = 0;

        virtual bool load() = 0;
        virtual void save() = 0;

        bool isLoaded() { return loaded; }
};
