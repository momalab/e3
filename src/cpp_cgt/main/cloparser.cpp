// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include <filesystem>
namespace fs = std::filesystem;

#include "os_filesys.h"
#include "cgtutil.h"

#include "cloparser.h"
#include "cgt.h"

std::string errorMsg(std::string s)
{
    return nm::cgt + ": " + s + '\n' + nm::err_msg_try;
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
            ///if ( !os::isFile(cfg) )
            if ( !fs::is_regular_file(cfg) )
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
            if ( !e3::util::isVarName(name) )
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
            // if ( !e3::util::isNumber(sbs) || ((bitsize = std::stoi(sbs)) <= 0) ) // deprecated
            if ( !e3::util::isPositiveInteger(sbs) || ((bitsize = std::stoi(sbs)) <= 0) )
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
            ///if ( !os::isDir(userdir) )
            if ( !fs::is_directory(userdir) )
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
            params.file = av[++i];
        }
        else if (s == nm::param_root )
        {
            params.cgtdir = av[++i];
        }
        else throw errorMsg("invalid option '" + s + "'");
    }
    // set default case unset
    if ( params.sign == Params::Sign::UNDEFINED )
        params.sign = Params::Sign::UNSIGNED;

    if ( params.cfg.empty() ) params.cfg = nm::default_cfg;

    return params;
}
