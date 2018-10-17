
#pragma once

#include <string>

#include "sectype.h"
#include "cfgparser.h"

namespace nm
{
const std::string logo = "E3 Framework, NYUAD, 2018, ver 0.1.4";
const std::string cgt = "cgt";
const std::string cgtexe = cgt + ".exe";
const std::string default_cfg = cgt + ".cfg";
const std::string err_msg_try = "Try '" + cgtexe + " help' for more information.";

const std::string cmd_dec = "dec";
const std::string cmd_enc = "enc";
const std::string cmd_gen = "gen";
const std::string cmd_key = "key";
const std::string cmd_help = "help";

const std::string param_cfg = "-c";
const std::string param_name = "-n";
const std::string param_signed = "-s";
const std::string param_userdir = "-d";
const std::string param_password = "-p";
const std::string param_file = "-f"; // FIXME e finish -f for dec/enc and help

const std::string cmd_cfg = param_cfg + " cfg";
const std::string cmd_name = param_name + " name";
const std::string cmd_signed = param_signed + " bitsize";
const std::string cmd_userdir = param_userdir + " userdir";
const std::string cmd_password = param_password + " password";

const std::string e3_lib = "secint";
const std::string lib_h = e3_lib + ".h";
const std::string lib_cpp = e3_lib + ".cpp";
const std::string lib_inc = e3_lib + ".inc";
const std::string lib_3p_basedir = "lib3p/";
const std::string inc_3p_dir = lib_3p_basedir + "include/";
const std::string lib_3p_dir = lib_3p_basedir + "lib/";
const std::string flag_random_password = "time";
} //nm

struct Params
{
    std::string cmd;
    std::string cfg;
    std::string name;
    std::string userdir;
    bool userdirset = false;
    std::string password;
    bool passwordset = false;
    enum class Sign { UNDEFINED, SIGNED, UNSIGNED } sign = Sign::UNDEFINED;
    int bitsize = 0;
    std::string file;
};

Params parse(int ac, char ** av);
void execute(Params params);

void dec(Params params);
void enc(Params params);
void gen(Params params);
void key(Params params);

void cleanup();
std::vector<SecType *> loadSecTypes(std::string name, ConfigParser & );
void usage(bool isHelp = false);
std::string libsTFH();
