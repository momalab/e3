// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "sk_pali.h"
#include "def_pali1.h"

#include "palisade.h"

///using std::cout; // debug FIXME remove

using std::stoi;

///using namespace lbcrypto;

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
    return PrivKey::filename();
}

void PaliBfvPrivKey::gen()
{
    // example e3::pali::make_context(65537, 2, 128);
    auto cc = e3::pali::make_context(ek.polyDegree, ek.mulDepth, lambda, ek.maxDepth, ek.p_n);
    auto keys = e3::pali::gen_keys(cc);

    ek.key.cc = new e3::pali::Cc(cc);
    ek.key.pk = new e3::pali::PubKey(keys.publicKey);
    sk = new e3::pali::SecKey(keys.secretKey);
}

bool PaliBfvPrivKey::load()
{
    auto fileSecretKey = filename();

    {
        std::ifstream in(fileSecretKey);
        if (!in) return false;
    }

    e3::pali::SecKey lsk = e3::pali::load_priv(fileSecretKey);
    sk = new e3::pali::SecKey(lsk);

    ek.load();

    return true;
}

std::vector<string> PaliBfvPrivKey::rawDecrypt(const string & undecor) const
{
    if (undecor.empty()) return vector<string>(1, "");

    PaliBfvNativeCiphertext pct(undecor, &ek);

    e3::pali::Cc & cc = *e3::pali::tocc(ek.key.cc);
    e3::pali::SecKey & k = *e3::pali::tosk(sk);

    e3::pali::Ct & ct = pct.p->ct;

    e3::pali::vi64 x = e3::pali::decrypt<e3::pali::vi64>(cc, k, ct, ek.useSlots);

    vector<string> m;
    for ( auto i : x ) m.push_back(std::to_string(i));

    return m;
}

void PaliBfvPrivKey::save()
{
    e3::pali::save_priv( *e3::pali::tosk(sk), filename() );
    ek.save();
}


} // e3
