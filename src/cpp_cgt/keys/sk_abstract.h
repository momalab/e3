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

        string filenamex(string fx) const { return name.fil + fx + ".priv.key"; }
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

        virtual string decrypt(const string & s) const = 0;
        virtual string encrypt(const string & s, int msz) const = 0;

        virtual bool load() = 0;
        virtual void save() = 0;

        bool isLoaded() { return loaded; }
};

} // e3
#endif // _E3_SK_ABSTRACT_H_
