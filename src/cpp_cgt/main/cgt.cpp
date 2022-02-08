// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// E3 (Encrypt-Everything-Everywhere) for Fully Homomorphic Encryption
// Oleg Mazonka, Eduardo Chielle
// MoMA lab, New York University Abu Dhabi, 2018-2020


#include <cstdlib>
#include <iostream>
#include <exception>
#include <filesystem>

#include "bdda.h"

#include "os_filesys.h"
#include "cgtutil.h"
#include "cfgparser.h"
#include "cloparser.h"
#include "def_mpir.h"

#include "cgt.h"

namespace fs = std::filesystem;
using namespace e3::cr;

using std::cout;

inline std::string optParam(std::string s)
{
    return "[" + s + "]";
}

int main(int ac, char * av[])
try
{
    try
    {
        if ( ac < 2 )
        {
            usage();
            return 0;
        }

        Params params = parse(ac, av);
        execute(params);
    }
    catch (...)
    {
        ///cout << "working dir: " << os::FileSys::cwd().str() << '\n';
        cout << "working dir: " << fs::current_path().string() << '\n';
        throw;
    }
}
catch (int e)
{
    cout << nm::cgt << " error (int): " << e << "\n";
    return 1;
}
catch (string e)
{
    cout << nm::cgt << " error (str): " << e << "\n";
    return 1;
}
catch (const char * e)
{
    cout << nm::cgt << " error (cc): " << e << "\n";
    return 1;
}
catch (const std::exception & e)
{
    cout << nm::cgt << " error (std): " << e.what() << "\n";
    return 1;
}
catch (...)
{
    cout << "Unknown exception\n";
    return 1;
}

void execute(Params params)
{
    std::string cmd = params.cmd;
    if ( cmd == nm::cmd_dec ) dec(params);
    else if ( cmd == nm::cmd_enc ) enc(params);
    else if ( cmd == nm::cmd_gen ) gen(params);
    else if ( cmd == nm::cmd_help ) usage(true);
    else if ( cmd == nm::cmd_key ) key(params);
    else throw errorMsg("this cannot happen");
}

void dec(Params params)
{
    std::string cfg = params.cfg;
    std::string name = params.name;
    bool sign = params.sign == Params::Sign::SIGNED;
    size_t bitsize = (size_t) params.bitsize;

    // read and parse configuration file
    ConfigParser par(cfg);
    par.loadOrGenKeys(false, true);
    std::vector<SecType *> sectypes = loadSecTypes(name, par);

    std::ifstream in_f;
    std::istream * in = &std::cin;

    if ( !params.file.empty() )
    {
        in_f.open(params.file, std::ios::binary);
        in = &in_f;
    }

    // go through the stream and decrypt it accordingly
    for (string line; std::getline(*in, line);)
    {
        ol::istr is(line);
        bool newline = true;
        for ( string s; is >> s;)
        {
            bool found = false;
            std::string sm;
            for ( auto sectype : par.sectypes )
            {
                sm = sectype->decrypt(s);
                if ( !sm.empty() ) found = true;
                if ( found ) break;
            }

            if ( !newline ) cout << ' ';
            newline = false;

            if ( found )
            {
                if ( sign ) sm = e3::util::unsigned2signed(sm, bitsize);
                cout << sm;
            }
            else cout << s;
        }
        cout << '\n';
    }
}

void enc(Params params)
{
    std::string cfg = params.cfg;
    std::string name = params.name;

    ConfigParser par(cfg);
    if ( params.passwordset ) par.setCloPassword(params.password);
    par.loadOrGenKeys(false, false);

    std::vector<SecType *> sectypes = loadSecTypes(name, par);

    if ( sectypes.size() < 1 )
        throw errorMsg("the configuration file '"
                       + cfg + "' has no classname defined");

    if ( sectypes.size() > 1 )
        throw errorMsg("too many classnames. Specify it using '"
                       + nm::cmd_name + "'");

    auto sectype = sectypes[0];

    // go through the stream and encrypt it accordingly
    for (string line; std::getline(std::cin, line);)
    {
        ol::istr is(line);
        bool newline = true;
        for ( string s; is >> s;)
        {
            std::string sx;
            s = e3::util::trim(s);
            // if ( e3::util::isNumber(s) ) sx = sectype->encrypt(s); // deprecated
            if ( e3::util::isFloat(s) ) sx = sectype->encrypt(s);
            else sx = s;
            if ( !newline ) cout << ' ';
            newline = false;

            cout << sx;
        }
        cout << '\n';
    }
}

void gen(Params params)
try
{
    std::string cfg = params.cfg;

    extern const char * g_platname;
    cout << nm::cgt << ": generating for " << g_platname << '\n';

    ConfigParser par(cfg);
    if ( params.userdirset ) par.userdir = params.userdir;
    if ( params.passwordset ) par.setCloPassword(params.password);
    par.loadOrGenKeys(false, false);

    if (par.userdir.empty()) par.userdir = ".";
    cout << "userdir: " << par.userdir << "\n";

    par.makeSecint( params.cgtdir, nm::e3_lib );
    par.makeDepend();
    par.saveConsts();

    cout << nm::cgt << ": ok\n";
}
catch (...)
{
    cout << nm::cgt << ": failed, cleaning up\n";
    cleanup();
    throw;
}

void key(Params params)
{
    std::string cfg = params.cfg;
    std::string name = params.name;

    ConfigParser par(cfg);
    if ( params.passwordset ) par.password = params.password;

    std::vector<SecType *> sectypes = loadSecTypes(name, par);
    for ( auto sectype : sectypes ) sectype->genKeys(true, false, par.password, &par);
}

void cleanup()
{
    ///os::FileSys::erase(nm::lib_h);
    ///os::FileSys::erase(nm::lib_inc);
    ///os::FileSys::erase(nm::lib_cpp);
	fs::remove(nm::lib_h);
	fs::remove(nm::lib_inc);
	fs::remove(nm::lib_cpp);
}

std::vector<SecType *> loadSecTypes(std::string name, ConfigParser & par)
{
    // set vector of sectypes
    // if name is empty, decrypt for everyone as unsigned
    // otherwise, check if name exists and only returns that one
    std::vector<SecType *> sectypes;
    if ( name.empty() ) sectypes = par.sectypes;
    else
    {
        for ( auto sectype : par.sectypes )
        {
            if ( name == sectype->getTypName() )
                sectypes.push_back(sectype);
        }
        // if name does not exists, throw exception
        if ( sectypes.empty() )
            throw errorMsg("'" + name
                           + "' is not defined in the configuration file");
    }
    return sectypes;
}

void usage(bool isHelp)
{
    cout << nm::logo << ", " << libsTFH() << "\n";

    cout << "Usage:\n";

    cout << ' ' << nm::cgtexe << ' ' << nm::cmd_dec << ' '
         << optParam(nm::cmd_cfg) << ' ' << optParam(nm::cmd_name)
         << ' ' << optParam(nm::cmd_signed)
         << ' ' << optParam(nm::cmd_file) << '\n';

    cout << ' ' << nm::cgtexe << ' ' << nm::cmd_enc << ' '
         << optParam(nm::cmd_cfg) << ' ' << optParam(nm::cmd_name)
         << ' ' << optParam(nm::cmd_password)
         << ' ' << optParam(nm::cmd_file) << '\n';

    cout << ' ' << nm::cgtexe << ' ' << nm::cmd_gen << ' '
         << optParam(nm::cmd_cfg) << ' ' << optParam(nm::cmd_userdir)
         << ' ' << optParam(nm::cmd_password)
         << ' ' << optParam(nm::cmd_root) << '\n';

    cout << ' ' << nm::cgtexe << ' ' << nm::cmd_key << ' '
         << optParam(nm::cmd_cfg) << ' ' << optParam(nm::cmd_name)
         << ' ' << optParam(nm::cmd_password) << '\n';

    cout << ' ' << nm::cgtexe << ' ' << nm::cmd_help << '\n';

    if (isHelp)
    {
        ///cout << "Current working dir: " << os::FileSys::cwd().str() << '\n';
        cout << "Current working dir: " << fs::current_path().string() << '\n';

        cout << std::endl;
        cout << "Commands:\n";

        cout << " dec";
        cout << "\tdecrypt numbers using the keys of the classname specified\n";
        cout << "\t  if the classname is not specified, "
             "try to decrypt for all keys\n";

        // cout << std::endl;
        cout << " enc";
        cout << "\tencrypt numbers to the classname specified\n";

        cout << "\t  if not present and there is only one classname "
             "in the configuration file,\n";

        cout << "\t  encrypt to that; otherwise, fail\n";

        // cout << std::endl;
        cout << " gen";

        cout << "\tgenerate the E3 library and keys (existing "
             "keys are not replaced)\n";

        // cout << std::endl;
        cout << " key";
        cout << "\tgenerate keys, replacing existing ones\n";

        cout << "\t  if the classname is not informed, generate "
             "new keys for all classnames\n";

        // cout << std::endl;
        cout << " help";
        cout << "\tshow this help\n";

        cout << std::endl;
        cout << "Parameters:\n";

        cout << " -c";
        cout << "\tconfiguration file; if not informed, '"
             + nm::default_cfg + "' is used\n";

        cout << " -d";
        cout << "\tthis parameter informs the base directory of "
             "the user source files\n";
        cout << "\t  if not informed, the one indicated in the "
             "configuration file is used\n";

        cout << " -f";
        cout << "\tinput file to be encrypted/decrypted\n";

        cout << " -n";
        cout << "\tthis parameter specifies the classname\n";

        cout << " -p";
        cout << "\tthe user password is specified by this parameter\n";
        cout << "\t  When used with the keyword '" + nm::flag_random_password
             + "', a random password is generated\n";
        cout << "\t  if not informed, the one indicated in "
             "the configuration file is used\n";

        cout << " -s";
        cout << "\tplaintexts are considered as signed numbers "
             "(the default is unsigned)\n";
        cout << "\t  the bitsize must be passed\n";
    }
}


string libsTFH()
{
    ol::ostr r;
    r << "LibsTSFHMCP " << e3::tfhe_impl() << e3::seal_impl() << e3::fhew_impl()
      << e3::heli_impl() << e3::mpir_impl() << e3::cr::cudd_impl() << e3::pali_impl();
    return r.str();
}
