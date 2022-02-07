// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_seal_ckks.h"
#include "def_seal_ckks1.h"

using namespace seal;
using std::cout;

void e3::SealCkksBaseEvalKeyExt::save()
{
    cout << "Saving evaluation key .. " << std::flush;
    auto fileParams = filename() + ".params.key";
    auto filePublicKey = filename() + ".publickey.key";
    auto fileRelin  = filename() + ".relin.key";
    auto fileConfig = filename() + ".config.key";
    std::ofstream ofParams(fileParams, std::ios::binary);
    std::ofstream ofPublicKey(filePublicKey, std::ios::binary);
    std::ofstream ofRelin (fileRelin , std::ios::binary);
    std::ofstream ofConfig(fileConfig, std::ios::binary);

#if SEALVER == 332
    seal::EncryptionParameters::Save( *(e3seal_ckks::toek(key)->params), ofParams );
#else
    e3seal_ckks::toek(key)->params->save( ofParams );
#endif

    e3seal_ckks::toek(key)->publickey.save(ofPublicKey);
    e3seal_ckks::toek(key)->relinkeys.save(ofRelin);
    ofConfig << (e3seal_ckks::toek(key)->scale);
    cout << "ok\n";
}
