// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_seal.h"
#include "def_seal1.h"

// using namespace seal;
using std::cout;

void e3::SealBaseEvalKeyExt::save()
{
    cout << "Saving evaluation key .. " << std::flush;
    auto fileParams = filename() + ".params.key";
    auto filePublicKey = filename() + ".publickey.key";
    auto fileRelin  = filename() + ".relin.key";
    auto fileGalois = filename() + ".galois.key";
    auto fileConfig = filename() + ".config.key";

	//<< sizeof()

    auto k = e3seal::toek(key);

    {
        cout << "[param" << std::flush;
        std::ofstream ofParams(fileParams, std::ios::binary);
#if SEALVER == 332
        seal::EncryptionParameters::Save( *(e3seal::toek(key)->params), ofParams );
#else
        ///e3seal::toek(key)->params->save( ofParams );
        k->params->save( ofParams );
#endif
        cout << "] " << std::flush;
    }

    {
        cout << "[pk" <<  std::flush;
        std::ofstream ofPublicKey(filePublicKey, std::ios::binary);
        k->publickey.save(ofPublicKey);
        cout << "] " << std::flush;
    }

    {
        cout << "[rel" << std::flush;
        std::ofstream ofRelin (fileRelin , std::ios::binary);
        k->relinkeys.save(ofRelin);
        cout << "] " << std::flush;
    }

    {
        cout << "[gal" << std::flush;
        std::ofstream ofGalois(fileGalois, std::ios::binary);
        k->galoiskeys.save(ofGalois);
        cout << "] " << std::flush;
    }

    {
        cout << "[cfg" << std::flush;
        std::ofstream ofConfig(fileConfig, std::ios::binary);
        ofConfig << (unsigned char) (k->isBatchEncoder);
        cout << "] " << std::flush;
    }

    cout << "ok\n";
}
