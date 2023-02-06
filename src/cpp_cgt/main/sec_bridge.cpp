// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <set>

#include "cfgparser.h"
#include "secnames.h"
#include "sec_bridge.h"

using namespace e3;
using namespace e3::cr;
using e3::cr::ol::replaceAll;
using std::shared_ptr;
using std::cout;

Bridge::Bridge(std::istream & is, string nm, const std::map<string, string> & globs)
    : SecType(nm)
{
    std::map<string, string *> kv = stdParams();

    kv[secNames::scheme] = &scheme;

    kv[secNames::module] = &module;
    kv[secNames::polyModulusDegree1] = &polyModulusDegree;
    kv[secNames::plaintextModulus1] = &plaintextModulus;
    kv[secNames::polyModulusDegree2] = &polyModulusDegree;
    kv[secNames::plaintextModulus2] = &plaintextModulus;
    kv[secNames::encoder] = &encoder;

    string slambda;
    kv[secNames::lambda] = &slambda;

    loadPairs(is, kv);
    globPairs(kv, globs);

    if ( encType.empty() ) throw "encryption type must be defined for " + nm;
    else if ( encType == secNames::encPilBase ) {}
    else if ( encType == secNames::encSeal ) {}
    else throw "encryption type [" + encType + "] is not known; valid=" "(pil)";

    if ( slambda.empty() ) lambda = 2;
    else lambda = std::stoi(slambda);
}

void Bridge::genKeys(bool forceGen, bool forceLoad,
                     std::string seed, const ConfigParser * par)
{
    seed = name.typ + seed;

    if (0) {}

    else if ( encType == secNames::encPilBase )
        sk = shared_ptr<PrivKey>
             (new PilBasePrivKey(name, forceGen,
                                 forceLoad, seed, lambda));

    else if ( encType == secNames::encSeal )
    {
        if ( scheme == secNames::encBfv || scheme.empty() )
            sk = shared_ptr<PrivKey>(
                     new SealBasePrivKey(
                         name, forceGen, forceLoad, seed, lambda,
                         polyModulusDegree, plaintextModulus, encoder
                     )
                 );
        else throw "Bridge: Scheme not supported for type ["
            + encType + "] in " + name.typ;
    }

    else
        throw "Bridge: Bad encryption type ["
        + encType + "] in " + name.typ;
}

void Bridge::writeH(string root, std::ostream & os, string user_dir) const
{
    if (!needModDb(Ext::H)) return;

    string dbf = cfgNames::dotH(module);
    string f = loadDbTemplBri(root, dbf);

    os << f;
}

void Bridge::writeInc(string root, std::ostream & os) const
{
    if (!needModDb(Ext::Inc)) return;

    string dbf = cfgNames::dotInc(module);
    string f = loadDbTemplBri(root, dbf);
    os << f;
}

void Bridge::writeCpp(string root, std::ostream & os) const
{
    if (!needModDb(Ext::Cpp)) return;

    string dbf = cfgNames::dotCpp(module);
    string f = loadDbTemplBri(root, dbf);
    os << f;
}

void Bridge::regist(SecType * st, int index)
{
    while ( (int)registered.size() < index + 1 ) registered.push_back(nullptr);
    registered[index] = st;
}

bool Bridge::needModDb(Ext f) const
{
    if (module.empty()) return false;

    if (0) {}

    else if ( module == cfgNames::dbfileModPilx )
    {
        if ( !isConnected(2) ) return false;
        return f == Ext::H || f == Ext::Inc;
    }

    else if ( module == cfgNames::dbfileModSeal )
    {
        if ( !isConnected(2) ) return false;
        return f == Ext::H || f == Ext::Inc;
    }

    else throw "Bad module name [" + module + "], use (" + cfgNames::dbfileModPilx + ", " + cfgNames::dbfileModSeal + "...)";
}

bool Bridge::isConnected(int sz) const
{
    auto warn = [&]()
    {
        static bool warned = false;
        if ( !warned )
        {
            warned = true;
            cout << "Warning: bridge [" + name.typ
                 + "] is defined but not fully connected: ignoring\n";
        }
    };

    if (sz > (int)registered.size())
    {
        warn();
        return false;
    }

    for ( auto x : registered )
    {
        if ( !x )
        {
            warn();
            return false;
        }
    }
    return true;
}

string Bridge::loadDbTemplBri(string root, string fn) const
{
    using namespace secNames;

    string f = loadDbTemplNorep(root, fn);

    for ( size_t i = 0; i < registered.size(); i++ )
        ol::replaceAll(f, secNames::R_TypName + ol::tos(i), registered[i]->getTypName());

    return f;
}
