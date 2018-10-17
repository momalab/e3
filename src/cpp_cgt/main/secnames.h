#pragma once

namespace secNames
{

// Types
const std::string typeNative = "native";
const std::string typeCircuit = "circuit";

// Encryption schemes
const std::string encPlain = "plain";
const std::string encTfhe = "tfhe";
const std::string encFhew = "fhew";
const std::string encHeli = "heli";

// Keywords for replacement
const std::string R_name = "$Name";
const std::string R_postfixDefines = "$PostfixDefines";
const std::string R_encryption = "$Encryption";
const std::string R_bitZero = "$BitZero";

// Identifiers
const std::string msize = "msize";
const std::string postfix = "postfix";
const std::string postneg = "postneg";
const std::string encryption = "encryption";
const std::string circDb = "circuitDB";
const std::string sizes = "sizes";

}
