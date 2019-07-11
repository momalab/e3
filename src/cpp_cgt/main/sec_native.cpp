#include "cfgparser.h" // ConfigNames

#include "secnames.h"
#include "sec_native.h"

Native::Native
(std::istream & is, string nm) : SecType(nm)
{
    std::map<string, string *> kv;
    kv[secNames::postfix] = &postfixP;
    kv[secNames::postneg] = &postfixN;
    loadPairs(is, kv);

    if ( plaintext_size < 0 ) plaintext_size = 8 * sizeof(e3util::ull);
}

void Native::writeH(string root, std::ostream & os, string user_dir) const
{
    string dbf = cfgNames::dotH(cfgNames::dbfileNative);
    string f = ol::file2str(root + cfgNames::templDir + dbf);
    ol::replaceAll(f, secNames::R_Tname, tname);
    ol::replaceAll(f, secNames::R_Ename, ename);
    ol::replaceAll(f, secNames::R_encryption, secNames::typeNative);

    auto allconsts = find_constants(user_dir);
    ol::replaceAll(f, secNames::R_postfixDefines, makeDefines(allconsts) );

    os << f;
}

void Native::writeInc(string root, std::ostream & os) const
{
    string dbf = cfgNames::dotInc(cfgNames::dbfileNative);
    string f = ol::file2str(root + cfgNames::templDir + dbf);
    ol::replaceAll(f, secNames::R_Tname, tname);
    ol::replaceAll(f, secNames::R_Ename, ename);
    os << f;
}

void Native::writeCpp(string root, std::ostream & os) const
{
    string dbf = cfgNames::dotCpp(cfgNames::dbfileNative);
    string f = ol::file2str(root + cfgNames::templDir + dbf);
    ol::replaceAll(f, secNames::R_Tname, tname);
    ol::replaceAll(f, secNames::R_Ename, ename);
    os << f;
}

void Native::genKeys(bool forceGen, bool forceLoad, std::string seed, const ConfigParser * par)
{
    sk = shared_ptr<PrivKey>(
             new NativePrivKey(tname, forceGen, forceLoad, tname + seed));
}
