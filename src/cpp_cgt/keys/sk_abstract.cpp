// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include "sk_abstract.h"

void e3::PrivKey::init_final(bool forceGen, bool forceLoad)
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

void e3::PrivKey::genAndSave()
{
    gen();
    loaded = false;
    save();
}
