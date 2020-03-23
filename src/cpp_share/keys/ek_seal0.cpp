#include <fstream>

#include "ek_seal.h"
#include "def_seal0.h"

using std::stoi;
using std::stoull;
using std::string;

namespace e3
{

bool SealBaseEvalKey::load(string fname)
{
    std::ifstream in(fname, std::ios::binary);
    string s;
    static e3seal::SealEvalKey evalkey;
    getline(in, s);
    evalkey.polyModulusDegree = uint64_t( stoull(s) );
    getline(in, s);
    evalkey.plaintextModulus  = uint64_t( stoull(s) );
    getline(in, s);
    evalkey.isBatchEncoder    = bool( stoi(s) );
    key = &evalkey;
    return !!in;
}

string SealBaseEvalKey::rawEncrypt(const string & s, int msz) const
{
    return s;
}

size_t SealBaseEvalKey::slots()
{
    const auto & k = e3seal::toek(key);
    return size_t(k->isBatchEncoder ? k->polyModulusDegree : 1);
}

} // e3
