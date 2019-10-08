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
    kv[secNames::polyModulusDegree] = &polyModulusDegree;
    kv[secNames::plaintextModulus] = &plaintextModulus;

    string slambda;
    kv[secNames::lambda] = &slambda;

    loadPairs(is, kv);
    globPairs(kv, globs);

    fixEncType();

    if ( encType.empty() ) throw "encryption type must be defined for " + nm;
    else if ( encType == secNames::encPila ) {}
    else if ( encType == secNames::encPail ) {}
    else if ( encType == secNames::encPailg ) {}
    else if ( encType == secNames::encSeal ) {}
    else if ( encType[0] == '@' ) {}
    else throw "encryption type [" + encType + "] is not known; valid=("
        + secNames::encPila + "," + secNames::encPail + "," + secNames::encPailg + ")";

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

    else if ( encType == secNames::encPail )
        sk = shared_ptr<PrivKey>
             (new PailPrivKey(name, forceGen, forceLoad, seed, lambda));

    else if ( encType == secNames::encPailg )
        sk = shared_ptr<PrivKey>
             (new PailgPrivKey(name, forceGen, forceLoad, seed, lambda));

    else if ( encType == secNames::encSeal )
        sk = shared_ptr<PrivKey>
             (new SealPrivKey(name, forceGen, forceLoad, seed, lambda, polyModulusDegree, plaintextModulus));

    else if (encType[0] == '@')
    {
        makeBridge(par, 1); if (!bridge) never("bridge");

        if (0) {}

        else if (encType == secNames::encPila)
        {
            PilBasePrivKey * p = dynamic_cast<PilBasePrivKey *>(bridge->get_sk_raw());
            if (!p) never("bad bridge");
            sk = shared_ptr<PrivKey>(new PilaPrivKey(*p, name.typ));
        }

        else
            throw "Circuit: Bridge is not supperted for type ["
            + encType + "] in " + name.typ;
    }

    else
        throw "(Partial::genKeys) Bad encryption type [" + encType + "] in " + name.typ;

    // set max size for constants
    if ( plaintext_size < 0 ) plaintext_size = lambda - 1;
}

void Partial::writeH(string root, std::ostream & os, string user_dir) const
{
    string dbf = cfgNames::dotH(cfgNames::dbfilePartial + '.' + encType);
    ///string f = ol::file2str(root + cfgNames::templDir + dbf);
    ///ol::replaceAll(f, secNames::R_TypName, name.typ);
    ///ol::replaceAll(f, secNames::R_FilName, name.fil);
    ///ol::replaceAll(f, secNames::R_ClsName, encType);
    ///ol::replaceAll(f, secNames::R_ariUnit, sk->encrypt("1", 1));
    ///ol::replaceAll(f, secNames::R_ariZero, sk->encrypt("0", 1));

    using namespace secNames;

    string f = loadDbTemplAri(root, dbf);

    auto allconsts = find_constants(user_dir);
    ol::replaceAll(f, R_postfixDefines, makeDefines(allconsts) );

    os << f;
}

void Partial::writeInc(string root, std::ostream & os) const
{
    string dbf = cfgNames::dotInc(cfgNames::dbfilePartial + '.' + encType + implVer());
    ///string f = ol::file2str(root + cfgNames::templDir + dbf);
    ///ol::replaceAll(f, secNames::R_TypName, name.typ);
    ///ol::replaceAll(f, secNames::R_FilName, name.fil);
    ///ol::replaceAll(f, secNames::R_ClsName, encType);
    ///ol::replaceAll(f, secNames::R_lambda, ol::tos(lambda) );

    string f = loadDbTemplAri(root, dbf);
    os << f;
}

void Partial::writeCpp(string root, std::ostream & os) const
{
    string dbf = cfgNames::dotCpp(cfgNames::dbfilePartial + '.' + encType + implVer());

    ///string f = ol::file2str(root + cfgNames::templDir + dbf);
    ///ol::replaceAll(f, secNames::R_TypName, name.typ);
    ///ol::replaceAll(f, secNames::R_FilName, name.fil);
    ///ol::replaceAll(f, secNames::R_ClsName, encType);
    ///ol::replaceAll(f, secNames::R_lambda, ol::tos(lambda) );
    ///ol::replaceAll(f, secNames::R_ariUnit, sk->encrypt("1", 1));
    ///ol::replaceAll(f, secNames::R_ariZero, sk->encrypt("0", 1));
    string f = loadDbTemplAri(root, dbf);
    os << f;
}

void Partial::fixEncType()
{
    if ( encType == secNames::encPilBase ) { encType = secNames::encPila; }
}

string Partial::loadDbTemplAri(string root, string fn) const
{
    using namespace secNames;
    string f = loadDbTempl(root, fn);
    if ( f.find(R_ariZero) != string::npos ) ol::replaceAll(f, R_ariZero, sk->encrypt("0", 1));
    if ( f.find(R_ariUnit) != string::npos ) ol::replaceAll(f, R_ariUnit, sk->encrypt("1", 1));
    return f;
}
