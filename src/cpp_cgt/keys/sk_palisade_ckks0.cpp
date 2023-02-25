// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <map>
#include <string>

#include "sk_palisade_ckks.h"
#include "def_palisade_ckks0.h"

using namespace std;

namespace e3
{

namespace palisade_ckks
{

template <class T, class U>
bool isKeyIn(const std::map<T, U> & m, const T & key)
{
    return !( m.find(key) == m.end() );
}

bool validateParams(std::map<std::string, std::string> params)
{
    std::vector<std::string> keys = { "seed", "lambda", "muldepth", "scale", "useslots" };
    for ( auto & key : keys ) if ( !isKeyIn(params, key) ) return false;
    return true;
}

int getRingDimension(uint32_t multDepth, uint32_t batchSize)
{
    int ringDimension;
    if ( multDepth <= 1 ) ringDimension = 1 << 13;
    else if ( multDepth <= 5 ) ringDimension = 1 << 14;
    else ringDimension = 1 << 15;
    if ( int(batchSize) > (ringDimension << 1) )
        throw "The batch size cannot be larger than ring dimension / 2.";
    return ringDimension;
}

} // palisade_ckks

PalisadeCkksPrivKey::PalisadeCkksPrivKey (
    KeyName name, bool forceGen, bool forceLoad, map<string, string> params)
    : PrivKey(name, params["seed"], (int)stoul(params["lambda"]) ), ek(name)
{
    if ( !forceLoad )
    {
        if ( !palisade_ckks::validateParams(params) )
            throw "Missing parameters. Check the configuration file.";
        try
        {
            auto mstoul = [&params](string a) -> unsigned long
            {
                auto x = params[a];
                return a.empty() ? 0 : stoul(a);
            };
            ek.securityLevel   = mstoul( params["lambda"  ] );
            ek.multDepth       = mstoul( params["muldepth"] );
            ek.scaleFactorBits = mstoul( params["scale"   ] );
            ek.batchSize       = mstoul( params["useslots"] );
            ek.ringDimension   = palisade_ckks::getRingDimension(ek.multDepth, ek.batchSize);
        }
        catch (...) { throw "Invalid parameters. Check the configuration file."; }
    }
    init_final(forceGen, forceLoad);
}

string PalisadeCkksPrivKey::filename() const
{
    return PrivKey::filename();
}

void PalisadeCkksPrivKey::gen()
{
    ek.key.cc = &ek.ringDimension;
}

bool PalisadeCkksPrivKey::load()
{
    auto fileSecretKey = filename();
    {
        ifstream fin(fileSecretKey);
        if (!fin) return false;
    }
    ek.load();
    return true;
}

vector<string> PalisadeCkksPrivKey::rawDecrypt(const string & strCiphertext) const
{
    return util::split(strCiphertext, '^');
}

void PalisadeCkksPrivKey::save()
{
    ofstream fout( filename() );
    ek.save();
}

} // e3
