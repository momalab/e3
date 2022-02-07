// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
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

    if ( !in ) throw "Cannot open " + fname;

    try
    {
        string s;
        e3seal::SealEvalKey * ekey = new e3seal::SealEvalKey;
        e3seal::SealEvalKey & evalkey = *ekey;
        getline(in, s);
        evalkey.polyModulusDegree = uint64_t( stoull(s) );
        getline(in, s);
        evalkey.plaintextModulus  = uint64_t( stoull(s) );
        getline(in, s);
        evalkey.isBatchEncoder    = bool( stoi(s) );
        key = ekey;
    }
    catch (...) { throw "Bad data in " + fname; }

    return !!in;
}

string SealBaseEvalKey::rawEncrypt(const string & s, int) const
{
    string strout;
    auto evalkey = e3seal::toek(key);
    auto & isBatchEncoder = evalkey->isBatchEncoder;
    if ( isBatchEncoder )
    {
        auto v = e3::util::split(s, '_');
        auto & slots = evalkey->polyModulusDegree;
        v.resize(size_t(slots), v.back());
        strout = e3::util::merge(v, "_");
    }
    else strout = s;
    return strout;
}

size_t SealBaseEvalKey::slots()
{
    const auto & k = e3seal::toek(key);
    return size_t(k->isBatchEncoder ? k->polyModulusDegree : 1);
}

uint64_t SealBaseEvalKey::getPlaintextModulus() const
{
    return e3seal::toek(key)->getPlaintextModulus();
}

} // e3
