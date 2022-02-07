// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_CFGNAMES_H_
#define _E3_CFGNAMES_H_

namespace cfgNames
{
const std::string templDir = "db/templ/";
const std::string top = templDir + "atop";
const std::string topH = top + ".h";
const std::string topInc = top + ".inc";
const std::string topCpp = top + ".cpp";

const std::string circDirt = "db/circuit/";
const std::string circleDir0 = "db/circle/";
const std::string circleDir1 = circleDir0 + "k2/";
const std::string bddmain = circleDir0 + "bddkey";

const std::string op_nand = circleDir1 + "op_nand";
const std::string op_and = circleDir1 + "op_and";
const std::string op_or = circleDir1 + "op_or";
const std::string op_xnor = circleDir1 + "op_xnor";
const std::string op_nor = circleDir1 + "op_nor";
const std::string op_mux = circleDir1 + "op_mux";
const std::string op_not_ker = circleDir1 + "op_not.ker";
const std::string op_not_nok = circleDir1 + "op_not.nok";
const std::string op_not_nand = circleDir1 + "op_not.nand";
const std::string op_xor_nok = circleDir1 + "op_xor.nok";
const std::string op_xor_ker = circleDir1 + "op_xor.ker";

const std::string kerdir = "ker/";
const std::string kername = "kernel";

const std::string password = "password";
const std::string sourceDir = "source_dir";
const std::string maxinline = "maxinline"; // max size of inline constants

const std::string circuitFilename = "circuits.inc";

const std::string dbfileNative = "native";
const std::string dbfileCircuit = "circuit";
const std::string dbfileCircuitBase = "circuit.base";
const std::string dbfileModular = "ring";
const std::string dbfileModPilx = "bridge.pilx";
const std::string dbfileModSeal = "bridge.seal";

inline std::string dotH(std::string s) { return s + ".h"; }
inline std::string dotInc(std::string s) { return s + ".inc"; }
inline std::string dotCpp(std::string s) { return s + ".cpp"; }
}
#endif // _E3_CFGNAMES_H_
