
// global o FIXMEs

// FIXME e add tests for cgt CLO
// FIXME e add lambda to the top level of cfg

// FIXME o add to logo type of TFHE(0/1)
// FIXME o need 2 different bin directories: one for CCN and another for CCT
// FIXME o (bug make) objects are built with CCN, but user.exe should be built with CCT


#include <cstdlib>
#include <iostream>
#include <exception>

#include "os_filesys.h"
#include "util.h"
#include "cfgparser.h"

#include "cgt.h"

using std::cout;

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
const char * g_platname = TOSTRING(PLAT);

inline std::string errorMsg(std::string s)
{
    return nm::cgt + ": " + s + '\n' + nm::err_msg_try;
}

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
        cout << "working dir: " << os::FileSys::cwd().str() << '\n';
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

Params parse(int ac, char ** av)
{
    Params params;

    std::string cmd = av[1];
    if ( cmd != nm::cmd_dec && cmd != nm::cmd_enc
            && cmd != nm::cmd_gen && cmd != nm::cmd_help
            && cmd != nm::cmd_key )
        throw errorMsg("invalid command '" + cmd + "'");

    params.cmd = cmd;
    for (auto i = 2; i < ac; i++)
    {
        std::string s = av[i];
        if ( s == nm::param_cfg )
        {
            if ( cmd != nm::cmd_dec && cmd != nm::cmd_enc
                    && cmd != nm::cmd_gen && cmd != nm::cmd_key )
                throw errorMsg("invalid option '" + s
                               + "' for command " + cmd + "'");

            if ( !params.cfg.empty() )
                throw errorMsg("redefinition of option '" + s + "'");

            if ( i + 1 >= ac )
                throw errorMsg("missing filename for option '" + s + "'");

            std::string cfg = av[++i];
            if ( !os::isFile(cfg) )
                throw errorMsg("invalid filename '" + cfg
                               + "' for option '" + s + "'");

            params.cfg = cfg;
        }
        else if ( s == nm::param_name )
        {
            if ( cmd != nm::cmd_dec && cmd != nm::cmd_enc && cmd != nm::cmd_key )
                throw errorMsg("invalid option '" + s
                               + "' for command " + cmd + "'");

            if ( !params.name.empty() )
                throw errorMsg("redefinition of option '" + s + "'");

            if ( i + 1 >= ac )
                throw errorMsg("missing name for option '" + s + "'");

            std::string name = av[++i];
            if ( !util::isVarName(name) )
                throw errorMsg("invalid name '" + name
                               + "' for option '" + s + "'");

            params.name = name;
        }
        else if ( s == nm::param_signed )
        {
            if ( cmd != nm::cmd_dec )
                throw errorMsg("invalid option '" + s
                               + "' for command " + cmd + "'");

            if ( params.sign != Params::Sign::UNDEFINED )
                throw errorMsg("sign already defined");

            if ( i + 1 >= ac )
                throw errorMsg("missing bitsize for option '" + s + "'");

            std::string sbs = av[++i];
            int bitsize = 0;
            if ( !util::isNumber(sbs) || ((bitsize = std::stoi(sbs)) <= 0) )
                throw errorMsg("invalid bitsize '" + sbs
                               + "' for option '" + s + "'");

            params.sign = Params::Sign::SIGNED;
            params.bitsize = bitsize;
        }
        else if ( s == nm::param_userdir )
        {
            if ( cmd != nm::cmd_gen )
                throw errorMsg("invalid option '" + s
                               + "' for command " + cmd + "'");

            if ( !params.userdir.empty() )
                throw errorMsg("redefinition of option '" + s + "'");

            if ( i + 1 >= ac )
                throw errorMsg("missing directory name for option '" + s + "'");

            std::string userdir = av[++i];
            if ( !os::isDir(userdir) )
                throw errorMsg("invalid directory '" + userdir
                               + "' for option '" + s + "'");

            params.userdir = userdir;
            params.userdirset = true;
        }
        else if ( s == nm::param_password )
        {
            if ( cmd != nm::cmd_enc && cmd != nm::cmd_gen
                    && cmd != nm::cmd_key )
                throw errorMsg("invalid option '" + s
                               + "' for command " + cmd + "'");

            if ( !params.password.empty() )
                throw errorMsg("redefinition of option '" + s + "'");

            if ( i + 1 >= ac )
                throw errorMsg("missing name for option '" + s + "'");

            std::string password = av[++i];
            if ( password == nm::flag_random_password ) password = "";
            params.password = password;
            params.passwordset = true;
        }
        else if ( s == nm::param_file )
        {
            params.file = av[++i]; // FIXME e add stuff
        }
        else throw errorMsg("invalid option '" + s + "'");
    }
    // set default case unset
    if ( params.sign == Params::Sign::UNDEFINED )
        params.sign = Params::Sign::UNSIGNED;

    if ( params.cfg.empty() ) params.cfg = nm::default_cfg;

    return params;
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
                ///sm = sectype->decrypt(s, &found);
                ///if ( found ) break;
                sm = sectype->decrypt(s);
                if ( !sm.empty() ) found = true;
                if ( found ) break;
            }

            if ( !newline ) cout << ' ';
            newline = false;

            if ( found )
            {
                if ( sign ) sm = util::unsigned2signed(sm, bitsize);
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
            s = util::trim(s);
            if ( util::isNumber(s) ) sx = sectype->encrypt(s);
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

    cout << nm::cgt << ": generating for " << g_platname << '\n';

    ///os::FileSys::erase(nm::lib_3p_basedir);
    ///os::FileSys::trymkdir(nm::lib_3p_basedir);

    ///os::FileSys::erase(nm::inc_3p_dir);
    ///os::FileSys::erase(nm::lib_3p_dir);

    ///os::FileSys::trymkdir(nm::inc_3p_dir);
    ///os::FileSys::trymkdir(nm::lib_3p_dir + g_platname);

    ConfigParser par(cfg);
    if ( params.userdirset ) par.userdir = params.userdir;
    if ( params.passwordset ) par.setCloPassword(params.password);
    par.loadOrGenKeys(false, false);

    par.makeSecint(nm::e3_lib);
    par.makeDepend();

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
    for ( auto sectype : sectypes ) sectype->genKeys(true, false, par.password);
}

void cleanup()
{
    ///os::FileSys::erase(nm::lib_3p_dir);
    os::FileSys::erase(nm::lib_h);
    os::FileSys::erase(nm::lib_inc);
    os::FileSys::erase(nm::lib_cpp);
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
            if ( name.find(sectype->getName()) != std::string::npos )
                sectypes.push_back(sectype);

            // if name does not exists, throw exception
            if ( sectypes.empty() )
                throw errorMsg("'" + name
                               + "' is not defined in the configuration file");
        }
    }
    return sectypes;
}

void usage(bool isHelp)
{
    cout << nm::logo << ", " << libsTFH() << "\n";

    cout << "Usage:\n";

    cout << ' ' << nm::cgtexe << ' ' << nm::cmd_dec << ' '
         << optParam(nm::cmd_cfg) << ' ' << optParam(nm::cmd_name)
         << ' ' << optParam(nm::cmd_signed) << '\n';

    cout << ' ' << nm::cgtexe << ' ' << nm::cmd_enc << ' '
         << optParam(nm::cmd_cfg) << ' ' << optParam(nm::cmd_name)
         << ' ' << optParam(nm::cmd_password) << '\n';

    cout << ' ' << nm::cgtexe << ' ' << nm::cmd_gen << ' '
         << optParam(nm::cmd_cfg) << ' ' << optParam(nm::cmd_userdir)
         << ' ' << optParam(nm::cmd_password) << '\n';

    cout << ' ' << nm::cgtexe << ' ' << nm::cmd_key << ' '
         << optParam(nm::cmd_cfg) << ' ' << optParam(nm::cmd_name)
         << ' ' << optParam(nm::cmd_password) << '\n';

    cout << ' ' << nm::cgtexe << ' ' << nm::cmd_help << '\n';

    if (isHelp)
    {
        cout << "Current working dir: " << os::FileSys::cwd().str() << '\n';

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

        cout << " -n";
        cout << "\tthis parameter specifies the classname\n";
        cout << " -s";

        cout << "\tplaintexts are considered as signed numbers "
             "(the default is unsigned)\n";

        cout << "\t  the bitsize must be passed\n";
        cout << " -d";

        cout << "\tthis parameter informs the base directory of "
             "the user source files\n";

        cout << "\t  if not informed, the one indicated in the "
             "configuration file is used\n";

        cout << " -p";
        cout << "\tthe user password is specified by this parameter\n";

        cout << "\t  When used with the keyword '" + nm::flag_random_password
             + "', a random password is generated\n";

        cout << "\t  if not informed, the one indicated in "
             "the configuration file is used\n";
    }
}


string libsTFH()
{
    ol::ostr r;
    r << "LibsTFH " << tfhe_impl() << ' ' << fhew_impl() << ' ' << heli_impl();
    return r.str();
}
