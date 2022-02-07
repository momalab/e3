// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#ifndef _E3_SECNAMES_H_
#define _E3_SECNAMES_H_

namespace secNames
{

// Types
const std::string typeNative = "native";
const std::string typeCircuit = "circuit";
const std::string typeRing = "ring";
const std::string typeBridge = "bridge";

// Encryption schemes
const std::string encPlain = "plain";
const std::string encFhew = "fhew";
const std::string encHeli = "heli";
const std::string encTfhe = "tfhe";
const std::string encExt = "extern";
const std::string encPail = "pail";
const std::string encPailg = "pailg";

const std::string encBdd = "bdd"; // base type
const std::string encBddn = "bddn";
const std::string encBdda = "bdda";
const std::string encBddf = "bddf";
const std::string encBddaz = "bddaz";
const std::string encBddfm = "bddfm";
const std::string encBddnx = "bddnx";

const std::string encPilBase = "pil";
const std::string encPilc = "pilc";
const std::string encPila = "pila";

const std::string encSeal = "seal";
const std::string encBfvProt = "bfv_prot";
const std::string encPali = "palisade";
const std::string encCkks = "ckks";
const std::string encBgv = "bgv";
const std::string encBfv = "bfv";
const std::string encGatcou = "gatcou";
const std::string encGatcow = "gatcow";


// Keywords for replacement
const std::string R_TypName = "$Name";
const std::string R_FilName = "$Filencname";
const std::string R_ClsName = "$Clsencname";
const std::string R_postfixDefines = "$PostfixDefines";
const std::string R_bitZero = "$BitZero";
const std::string R_bitUnit = "$BitUnit";
const std::string R_lambda = "$CtSize";
const std::string R_x2lambda = "$Ct2Size";
const std::string R_dec = "$dec";
const std::string R_enc = "$enc";
const std::string R_tid = "$tid";
const std::string R_Modifier = "$Modifier";
const std::string R_bbshash = "$bbshash";
const std::string R_ariUnit = "$ArithUnit";
const std::string R_ariZero = "$ArithZero";
const std::string R_Pailgfkf = "$Pailgfkf";
const std::string R_copheeIsArduino = "$Cophee_isUsingArduino";
const std::string R_copheeBaudRate = "$Cophee_baudRate";

// Identifiers
const std::string msize = "msize";
const std::string postfix = "postfix";
const std::string postneg = "postneg";
const std::string encryption = "encryption";
const std::string circDb = "circuitDB";
const std::string sizes = "sizes";
const std::string formula = "formula";
const std::string lambda = "lambda"; // security level
const std::string compile = "compile";
const std::string kernel = "kernel";
const std::string module = "module";
const std::string polyModulusDegree1 = "polyModulusDegree"; // FIXME this is a mess
const std::string plaintextModulus1 = "plaintextModulus";
const std::string polyModulusDegree2 = "logn";
const std::string plaintextModulus2 = "t";
const std::string scale = "scale"; // Seal and Palisade (CKKS)
const std::string primes = "primes";
const std::string encoder = "encoder";
const std::string pailBeta = "beta";
const std::string copheeIsArduino = "arduino";
const std::string copheeBaudRate = "baud";
const std::string scheme = "scheme";
const std::string muldepth = "muldepth"; // Palisade (BFV and CKKS)
const std::string maxdepth = "maxdepth";
const std::string useslots = "useslots"; // Palisade (BFV and CKKS)
const std::string paramn = "polyn";
const std::string rotations = "rotations"; // Palisade (CKKS)
const std::string rescale = "rescale"; // Palisade (CKKS)

}
#endif // _E3_SECNAMES_H_
