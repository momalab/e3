#include <set>

#include "cfgparser.h"
#include "secnames.h"
#include "sec_bridge.h"

using namespace e3;

Bridge::Bridge(std::istream & is, string nm, const std::map<string, string> & globs)
    : SecType(nm)
{
    std::map<string, string *> kv;

    kv[secNames::encryption] = &encType;
    kv[secNames::module] = &module;

    string slambda;
    kv[secNames::lambda] = &slambda;

    loadPairs(is, kv);
    globPairs(kv, globs);

    if ( encType.empty() ) throw "encryption type must be defined for " + nm;
    else if ( encType == secNames::encPilBase ) {}
    else throw "encryption type [" + encType + "] is not known; valid=" "(pil)";

    if ( slambda.empty() )
    {
        lambda = 10;
        std::cout << "Warning: lambda is not defined for "
                  << nm << ", using " << lambda << '\n';
    }
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

    else
        throw "Partial: Bad encryption type ["
        + encType + "] in " + name.typ;
}

void Bridge::writeH(string root, std::ostream & os, string user_dir) const
{
    if (!needModDb(Ext::H)) return;

    string dbf = cfgNames::dotH(module);
    string f = ol::file2str(root + cfgNames::templDir + dbf);

    for ( size_t i = 0; i < registered.size(); i++ )
        ol::replaceAll(f, secNames::R_TypName + ol::tos(i), registered[i]->getTypName());

    os << f;
}

void Bridge::writeInc(string root, std::ostream & os) const
{
    if (!needModDb(Ext::Inc)) return;

    string dbf = cfgNames::dotInc(module);
    string f = ol::file2str(root + cfgNames::templDir + dbf);

    for ( size_t i = 0; i < registered.size(); i++ )
        ol::replaceAll(f, secNames::R_TypName + ol::tos(i), registered[i]->getTypName());

    os << f;
}

void Bridge::writeCpp(string root, std::ostream & os) const
{
    if (!needModDb(Ext::Cpp)) return;

    string dbf = cfgNames::dotCpp(module);
    string f = ol::file2str(root + cfgNames::templDir + dbf);

    for ( size_t i = 0; i < registered.size(); i++ )
        ol::replaceAll(f, secNames::R_TypName + ol::tos(i), registered[i]->getTypName());

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

    else throw "Bad module name [" + module + "], use (" + cfgNames::dbfileModPilx + ",...)";
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
