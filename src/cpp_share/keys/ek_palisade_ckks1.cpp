// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <complex>
#include <fstream>
#include <string>
#include <vector>

#include "base64.h"
#include "e3util.h"
#include "def_palisade_ckks1.h"
#include "ek_palisade_ckks.h"

using namespace std;

namespace e3
{

bool PalisadeCkksEvalKey::load(string fname)
{
    if ( !palisade_ckks::isLoadPublicKeyPossible(name.fil) ) return false;

    key.cc = new palisade_ckks::Context;
    key.pk = new palisade_ckks::PublicKey;

    palisade_ckks::Context & context = *palisade_ckks::toContext(key.cc);
    palisade_ckks::PublicKey & publicKey = *palisade_ckks::toPublicKey(key.pk);

    palisade_ckks::loadParams(name.fil, multDepth, scaleFactorBits, batchSize, securityLevel, ringDimension, rescale, rotations);
    context = palisade_ckks::loadContext(name.fil);
    publicKey = palisade_ckks::loadPublicKey(name.fil);
    palisade_ckks::loadEvaluationKey(context, name.fil);
    return true;
}

string PalisadeCkksEvalKey::rawEncrypt(const string & strPlaintext, int msz) const
{
    vector<complex<double>> v;
    auto vs = util::split(strPlaintext, '_');
    for ( auto & s : vs )
    {
        auto vsd = util::split(s, '+');
        double real = vsd.size() > 0 ? std::stod( vsd[0] ) : 0;
        double imag = vsd.size() > 1 ? std::stod( vsd[1].substr(0, vsd[1].size() - 1) ) : 0;
        v.push_back( complex<double>(real, imag) );
    }
    v.resize( slots(), 0 );


    auto & context = *palisade_ckks::toContext(key.cc);
    auto & publicKey = *palisade_ckks::toPublicKey(key.pk);
    auto ciphertext = e3::palisade_ckks::encrypt(context, publicKey, v);

    string strCiphertext = util::base64::enc( palisade_ckks::ciphertextToString(ciphertext) );
    return strCiphertext;
}

size_t PalisadeCkksEvalKey::slots() const
{
    return ( *palisade_ckks::toContext(key.cc) )->GetRingDimension() >> 1;
}

} // e3
