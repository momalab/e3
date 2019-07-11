#pragma once

namespace secNames
{

// Types
const std::string typeNative = "native";
const std::string typeCircuit = "circuit";
const std::string typePartial = "partial";
const std::string typeBridge = "bridge";

// Encryption schemes
const std::string encPlain = "plain";
const std::string encFhew = "fhew";
const std::string encHeli = "heli";
const std::string encSeal = "seal";
const std::string encTfhe = "tfhe";
const std::string encBddn = "bddn";
const std::string encBdda = "bdda";
const std::string encBddf = "bddf";
const std::string encBddaz = "bddaz";
const std::string encBddfm = "bddfm";
const std::string encBddnx = "bddnx";
const std::string encBdd = "bdd"; // base type
const std::string encPilBase = "pil";
const std::string encPilc = "pilc";
const std::string encPila = "pila";
const std::string encExt = "extern";

// Keywords for replacement
const std::string R_Tname = "$Name";
const std::string R_Ename = "$Ename";
const std::string R_postfixDefines = "$PostfixDefines";
const std::string R_encryption = "$Encryption";
const std::string R_bitZero = "$BitZero";
const std::string R_bitUnit = "$BitUnit";
const std::string R_lambda = "$CtSize";
const std::string R_x2lambda = "$Ct2Size";
const std::string R_dec = "$dec";
const std::string R_enc = "$enc";
const std::string R_tid = "$tid";
const std::string R_Modifier = "$Modifier";
const std::string R_bbshash = "$bbshash";
const std::string R_pilUnit = "$PilUnit";
const std::string R_pilZero = "$PilZero";

// Identifiers
const std::string msize = "msize";
const std::string postfix = "postfix";
const std::string postneg = "postneg";
const std::string encryption = "encryption";
const std::string circDb = "circuitDB";
const std::string sizes = "sizes";
const std::string formula = "formula";
const std::string lambda = "lambda";
const std::string compile = "compile";
const std::string kernel = "kernel";
const std::string module = "module";

}
