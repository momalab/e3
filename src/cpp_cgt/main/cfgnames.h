#pragma once

namespace cfgNames
{
const std::string templDir = "db/templ/";
const std::string top = templDir + "atop";
const std::string topH = top + ".h";
const std::string topInc = top + ".inc";
const std::string topCpp = top + ".cpp";

const std::string circDirt = "db/circuit/";

const std::string password = "password";
const std::string sourceDir = "source_dir";

const std::string circuitFilename = "circuits.inc";

const std::string dbfileNative = "native";
const std::string dbfileCircuit = "circuit";

inline std::string dotH(std::string s) { return s + ".h"; }
inline std::string dotInc(std::string s) { return s + ".inc"; }
inline std::string dotCpp(std::string s) { return s + ".cpp"; }
}
