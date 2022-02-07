// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <algorithm>
#include <complex>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "sk_palisade_ckks.h"
#include "def_palisade_ckks1.h"

#include "palisade.h"

using std::complex;
using std::ifstream;
using std::map;
using std::string;
using std::vector;

namespace e3
{

namespace palisade_ckks
{

template <class T, class U>
bool isKeyIn(const map<T, U> & m, const T & key)
{
    return !( m.find(key) == m.end() );
}

bool validateParams(map<string, string> params)
{
    vector<string> keys = { "seed", "lambda", "muldepth", "scale", "useslots" };
    for ( auto & key : keys ) if ( !isKeyIn(params, key) ) return false;
    return true;
}

} // sk_palisade_ckks

PalisadeCkksPrivKey::PalisadeCkksPrivKey (
    KeyName name, bool forceGen, bool forceLoad, map<string, string> params)
    : PrivKey(name, params["seed"], (int)std::stoul(params["lambda"]) ), ek(name)
{
    if ( !forceLoad )
    {
        if ( !palisade_ckks::validateParams(params) )
            throw "Missing parameters. Check the configuration file.";
        try
        {
            ek.securityLevel   = std::stoul( params["lambda"  ] );
            ek.multDepth       = std::stoul( params["muldepth"] );
            ek.scaleFactorBits = std::stoul( params["scale"   ] );
            ek.batchSize       = std::stoul( params["useslots"] );
            if ( palisade_ckks::isKeyIn(params, string("logn") ) && !params["logn"].empty() )
            {
                auto logn = std::stoi( e3::util::trim(params["logn"]) );
                ek.ringDimension = logn ? 1 << logn : 0;
            }
            if ( palisade_ckks::isKeyIn(params, string("rescale") ) && !params["rescale"].empty() )
            {
                auto strRescale = params["rescale"];
                std::transform(strRescale.begin(), strRescale.end(), strRescale.begin(), [](unsigned char c) { return std::tolower(c); } );
                if ( strRescale == "exact" || strRescale == "approx" ) ek.rescale = strRescale;
                else throw;
            }
            if ( palisade_ckks::isKeyIn(params, string("rotations") ) && !params["rotations"].empty() )
                ek.rotations = params["rotations"];
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
    auto context = palisade_ckks::makeContext(ek.multDepth, ek.scaleFactorBits, ek.batchSize, ek.securityLevel, ek.ringDimension, ek.rescale);
    auto keys = palisade_ckks::generateKeys(context, ek.rotations);
    ek.key.cc = new palisade_ckks::Context(context);
    ek.key.pk = new palisade_ckks::PublicKey(keys.publicKey);
    sk = new palisade_ckks::SecretKey(keys.secretKey);
}

bool PalisadeCkksPrivKey::load()
{
    auto fileSecretKey = filename();
    {
        ifstream fin(fileSecretKey);
        if (!fin) return false;
    }
    palisade_ckks::SecretKey secretKey = palisade_ckks::loadSecretKey(fileSecretKey);
    sk = new palisade_ckks::SecretKey(secretKey);

    ek.load();
    return true;
}

vector<string> PalisadeCkksPrivKey::rawDecrypt(const string & undecor) const
{
    if ( undecor.empty() ) return vector<string>(1, "");
    PalisadeCkksNativeCiphertext nativeCiphertext(undecor, &ek);
    palisade_ckks::Context & context = *palisade_ckks::toContext(ek.key.cc);
    palisade_ckks::SecretKey & secretKey = *palisade_ckks::toSecretKey(sk);
    palisade_ckks::Ciphertext_t & ciphertext = nativeCiphertext.p->ct;
    vector<complex<double>> vPlaintext = palisade_ckks::decrypt<vector<complex<double>>>(context, secretKey, ciphertext, ek.batchSize);
    vector<string> vsPlaintext;
    for ( auto e : vPlaintext ) vsPlaintext.push_back( e3::util::to_string(e) );
    return vsPlaintext;
}

void PalisadeCkksPrivKey::save()
{
    palisade_ckks::saveSecretKey( *palisade_ckks::toSecretKey(sk), filename() );
    ek.save();
}

} // e3
