
#include "sk_abstract.h"

void PrivKey::init_final(bool forceGen, bool forceLoad)
{
    if (forceGen) genAndSave();
    else if (forceLoad)
    {
        if (!load()) throw "Cannot load the key [" + filename() + "]";
    }
    else // both false
    {
        if (!load()) genAndSave();
    }
}

void PrivKey::genAndSave()
{
    gen();
    loaded = false;
    save();
}
