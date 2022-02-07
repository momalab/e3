// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <string>
#include <vector>

#include "e3util.h"
#include "def_palisade_ckks0.h"
#include "ek_palisade_ckks.h"

using namespace std;

namespace e3
{

bool PalisadeCkksEvalKey::load(string fname)
{
    ifstream fin( fname, std::ios::binary );
    if ( !fin ) return false;
    fin >> multDepth >> scaleFactorBits >> batchSize >> securityLevel >> ringDimension;
    if ( !fin ) return false;
    palisade_ckks::dummy();
    key.cc = &ringDimension;
    return true;
}

string PalisadeCkksEvalKey::rawEncrypt(const string & strPlaintext, int msz) const
{
    vector<double> v;
    auto vs = util::split(strPlaintext, '_');
    for ( auto e : vs ) v.push_back( (double) stod(e) );
    v.resize( slots(), 0 );
    PalisadeCkksCiphertext ciphertext {v};
    return ciphertext.str();
}

size_t PalisadeCkksEvalKey::slots() const
{
    // return batchSize;
    return ringDimension >> 1;
}

} // e3
