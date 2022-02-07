// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "sk_pali.h"
#include "def_pali0.h"


namespace e3
{

PaliBfvPrivKey::PaliBfvPrivKey
(KeyName name, bool forceGen, bool forceLoad, std::string seed, int lam,
 string pD, string muldep, int useSlots, string maxdep, string sp_n)
    : PrivKey(name, seed, lam), ek(name)
{
    try
    {
        if ( !pD.empty() ) ek.polyDegree = stoi(pD);
        if ( !muldep.empty() ) ek.mulDepth = stoi(muldep);
        if ( !maxdep.empty() ) ek.maxDepth = stoi(maxdep);
        if ( !sp_n.empty() ) ek.p_n = stoi(sp_n);
    }
    catch (...)
    {
        throw "check that params are numbers";
    }

    ek.useSlots = useSlots;

    init_final(forceGen, forceLoad);
}


string PaliBfvPrivKey::filename() const
{
    return PrivKey::filenamex("_0");
}

void PaliBfvPrivKey::gen()
{
    ek.key.pk = &ek.useSlots;
}

bool PaliBfvPrivKey::load()
{
    auto fileSecretKey = filename();

    {
        std::ifstream in(fileSecretKey);
        if (!in) return false;
    }

    ek.load();
    return true;
}

std::vector<string> PaliBfvPrivKey::rawDecrypt(const string & c) const
{
    return e3::util::split(c, '^');
}

void PaliBfvPrivKey::save()
{
    std::ofstream of( filename() );
    ek.save();
}


} // e3
