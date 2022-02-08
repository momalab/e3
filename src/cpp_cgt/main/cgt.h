// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_CGT_H_
#define _E3_CGT_H_


#include <string>

#include "sectype.h"
#include "cfgparser.h"
#include "cloparser.h"

namespace nm
{
// Careful with logo: number of words importand for amalgam
const std::string logo = "E3 FHE, NYUAD, 2018-2022, ver 0.3.1";
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
const std::string param_file = "-f";
const std::string param_root = "-r";

const std::string cmd_cfg = param_cfg + " cfg";
const std::string cmd_name = param_name + " name";
const std::string cmd_signed = param_signed + " bitsize";
const std::string cmd_userdir = param_userdir + " userdir";
const std::string cmd_password = param_password + " password";
const std::string cmd_file = param_file + " file";
const std::string cmd_root = param_root + " cgtdir";

const std::string e3_lib = "secint";
const std::string lib_h = e3_lib + ".h";
const std::string lib_cpp = e3_lib + ".cpp";
const std::string lib_inc = e3_lib + ".inc";
const std::string flag_random_password = "time";
} //nm

void execute(Params params);

void dec(Params params);
void enc(Params params);
void gen(Params params);
void key(Params params);

void cleanup();
std::vector<SecType *> loadSecTypes(std::string name, ConfigParser & );
void usage(bool isHelp = false);
std::string libsTFH();
#endif // _E3_CGT_H_
