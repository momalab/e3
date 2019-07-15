#include <set>

#include "cfgparser.h"
#include "secnames.h"
#include "sec_bridge.h"
#include "sec_partial.h"

using namespace e3;

Partial::Partial(std::istream & is, string nm, const std::map<string, string> & globs) : SecType(nm)
{
    std::map<string, string *> kv;

    kv[secNames::postfix] = &postfixP;
    kv[secNames::postneg] = &postfixN;
    kv[secNames::encryption] = &encType;

    string slambda;
    kv[secNames::lambda] = &slambda;

    loadPairs(is, kv);
    globPairs(kv, globs);

    fixEncType();

    if ( encType.empty() ) throw "encryption type must be defined for " + nm;
    else if ( encType == secNames::encPila ) {}
    else if ( encType[0] == '@' ) {}
    else throw "encryption type [" + encType + "] is not known; valid=" "(pil)";

    if ( encType[0] == '@' )
    {
        if ( !slambda.empty() ) cout << "Warning: lambda is ignored for " << nm << '\n';
    }
    else
    {
        if ( slambda.empty() )
        {
            lambda = 10;
            std::cout << "Warning: lambda is not defined for "
                      << nm << ", using " << lambda << '\n';
        }
        else lambda = std::stoi(slambda);
    }
}

void Partial::genKeys(bool forceGen, bool forceLoad,
                      std::string seed, const ConfigParser * par)
{
    seed = name.typ + seed;

    if (0) {}

    else if ( encType == secNames::encPila )
        sk = shared_ptr<PrivKey>
             (new PilaPrivKey(name, forceGen, forceLoad, seed, lambda));

    else if ( encType[0] == '@' ) makeBridge(par, 1);

    else
        throw "Partial: Bad encryption type [" + encType + "] in " + name.typ;

    // set max size for constants
    if ( plaintext_size < 0 ) plaintext_size = lambda - 1;
}

void Partial::writeH(string root, std::ostream & os, string user_dir) const
{
    string dbf = cfgNames::dotH(cfgNames::dbfilePartial + '.' + encType);
    string f = ol::file2str(root + cfgNames::templDir + dbf);
    ol::replaceAll(f, secNames::R_TypName, name.typ);
    ol::replaceAll(f, secNames::R_FilName, name.fil);
    ol::replaceAll(f, secNames::R_ClsName, encType);
    ol::replaceAll(f, secNames::R_pilUnit, sk->encrypt("1", 1));
    ol::replaceAll(f, secNames::R_pilZero, sk->encrypt("0", 1));

    auto allconsts = find_constants(user_dir);
    ol::replaceAll(f, secNames::R_postfixDefines, makeDefines(allconsts) );

    os << f;
}

void Partial::writeInc(string root, std::ostream & os) const
{
    {
        string dbf = cfgNames::dotInc(cfgNames::dbfilePartial + '.' + encType);
        string f = ol::file2str(root + cfgNames::templDir + dbf);
        ol::replaceAll(f, secNames::R_TypName, name.typ);
        ol::replaceAll(f, secNames::R_FilName, name.fil);
        ol::replaceAll(f, secNames::R_ClsName, encType);
        ol::replaceAll(f, secNames::R_lambda, ol::tos(lambda) );
        os << f;
    }
}

void Partial::writeCpp(string root, std::ostream & os) const
{
    {
        string dbf = cfgNames::dotCpp(cfgNames::dbfilePartial + '.' + encType);

        string f = ol::file2str(root + cfgNames::templDir + dbf);
        ol::replaceAll(f, secNames::R_TypName, name.typ);
        ol::replaceAll(f, secNames::R_FilName, name.fil);
        ol::replaceAll(f, secNames::R_ClsName, encType);
        ol::replaceAll(f, secNames::R_lambda, ol::tos(lambda) );
        ol::replaceAll(f, secNames::R_pilUnit, sk->encrypt("1", 1));
        os << f;
    }
}

void Partial::fixEncType()
{
    if ( encType == secNames::encPilBase ) { encType = secNames::encPila; }
}

