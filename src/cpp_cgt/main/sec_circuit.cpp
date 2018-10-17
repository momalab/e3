#include <set>

#include "cfgparser.h" // ConfigNames
#include "secnames.h"
#include "sec_circuit.h"


Circuit::Circuit(std::istream & is, string nm) : SecType(nm)
{
    std::map<string, string *> kv;
    kv[secNames::postfix] = &postfixP;
    kv[secNames::postneg] = &postfixN;
    kv[secNames::encryption] = &encType;
    kv[secNames::circDb] = &circDb;

    string ssizes;
    kv[secNames::sizes] = &ssizes;

    loadPairs(is, kv);

    if ( encType.empty() ) throw "encryption type must be defined for " + nm;
    else if ( encType == secNames::encPlain ) {}
    else if ( encType == secNames::encTfhe ) {}
    else if ( encType == secNames::encFhew ) {}
    else if ( encType == secNames::encHeli ) {}
    else throw "encryption type [" + encType + "] is not known; valid=(plain,tfhe,fhew,heli)";

    if ( circDb.empty() ) circDb = encType;

    // parse ssizes;
    sizes.push_back(1);
    ol::istr sis(ssizes);
    for ( string s; std::getline(sis, s, ','); )
    {
        auto dash = s.find('-');
        if ( dash == string::npos )
        {
            sizes.push_back(std::stoi(s));
            continue;
        }

        int a = std::stoi(s.substr(0, dash));
        int b = std::stoi(s.substr(dash + 1));

        if (a <= b) for ( int i = a; i <= b; i++ ) sizes.push_back(i);
    }

    // set max plaintext size
    for ( auto x : sizes ) if ( x > plaintext_size ) plaintext_size = x;

    // FIXME e add lambda parameter. Here it is just hardcoded
    lambda = 10; // 110
}

void Circuit::genKeys(bool forceGen, bool forceLoad, std::string seed)
{
    if (0) {}

    else if ( encType == secNames::encHeli )
        sk = shared_ptr<PrivKey>
             (csk = new CircuitPrivKey_heli(name, forceGen, forceLoad, seed, lambda));

    else if ( encType == secNames::encFhew )
        sk = shared_ptr<PrivKey>
             (csk = new CircuitPrivKey_fhew(name, forceGen, forceLoad, seed, lambda));

    else if ( encType == secNames::encTfhe )
        sk = shared_ptr<PrivKey>
             (csk = new CircuitPrivKey_tfhe(name, forceGen, forceLoad, seed, lambda));

    else if ( encType == secNames::encPlain )
        sk = shared_ptr<PrivKey>
             (csk = new CircuitPrivKey_plain(name, forceGen, forceLoad, seed));

    else
        throw "Bad encryption type in " + name;
}

void Circuit::writeH(std::ostream & os, string user_dir) const
{

    // write Bit class defintion
    {
        string dbf = cfgNames::dotH(
                         cfgNames::dbfileCircuit + '.' + encType);

        string f = ol::file2str(cfgNames::templDir + dbf);
        ol::replaceAll(f, secNames::R_name, name);
        os << f;
    }


    {
        string dbf = cfgNames::dotH(cfgNames::dbfileCircuit);
        string f = ol::file2str(cfgNames::templDir + dbf);
        ol::replaceAll(f, secNames::R_name, name);

        auto allconsts = find_constants(user_dir);
        ol::replaceAll(f, secNames::R_postfixDefines, makeDefines(allconsts) );

        os << f;
    }
}

void Circuit::writeInc(std::ostream & os) const
{
    {
        string dbf = cfgNames::dotInc(cfgNames::dbfileCircuit);
        string f = ol::file2str(cfgNames::templDir + dbf);
        ol::replaceAll(f, secNames::R_name, name);
        ol::replaceAll(f, secNames::R_encryption, encType);
        os << f;
    }
}

void Circuit::writeCpp(std::ostream & os) const
{
    // write circuits
    std::set<int> done;
    for ( auto i : sizes )
    {
        if ( done.find(i) != done.end() ) continue;
        done.insert(i);

        string path = cfgNames::circDirt + circDb + "/" + ol::tos(i)
                      + "/" + cfgNames::circuitFilename;

        string cf = ol::file2str(path);
        ol::replaceAll(cf, secNames::R_name, name);
        os << cf;
    }

    // write class globals and non-template function
    {
        string dbf = cfgNames::dotCpp(cfgNames::dbfileCircuit);

        string f = ol::file2str(cfgNames::templDir + dbf);
        ol::replaceAll(f, secNames::R_name, name);
        ol::replaceAll(f, secNames::R_encryption, encType);
        ol::replaceAll(f, secNames::R_bitZero, csk->encbitstr(false) );
        os << f;
    }

    // write gate implementations
    {
        string ver;
        if ( encType == secNames::encTfhe ) ver = tfhe_impl();
        if ( encType == secNames::encFhew ) ver = fhew_impl();
        if ( encType == secNames::encHeli ) ver = heli_impl();

        string dbf = cfgNames::dotCpp(cfgNames::dbfileCircuit
                                      + '.' + encType + ver);

        string f = ol::file2str(cfgNames::templDir + dbf);
        ol::replaceAll(f, secNames::R_name, name);
        os << f;
    }
}
