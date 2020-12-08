#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_seal.h"
#include "def_seal1.h"

using namespace seal;
using std::cout;

void e3::SealBaseEvalKeyExt::save()
{
    cout << "Saving evaluation key .. " << std::flush;
    auto fileParams = filename() + ".params.key";
    auto filePublicKey = filename() + ".publickey.key";
    auto fileRelin  = filename() + ".relin.key";
    auto fileGalois = filename() + ".galois.key";
    auto fileConfig = filename() + ".config.key";
    std::ofstream ofParams(fileParams, std::ios::binary);
    std::ofstream ofPublicKey(filePublicKey, std::ios::binary);
    std::ofstream ofRelin (fileRelin , std::ios::binary);
    std::ofstream ofGalois(fileGalois, std::ios::binary);
    std::ofstream ofConfig(fileConfig, std::ios::binary);
    EncryptionParameters::Save( *(e3seal::toek(key)->params), ofParams );
    e3seal::toek(key)->publickey.save(ofPublicKey);
    e3seal::toek(key)->relinkeys.save(ofRelin);
    e3seal::toek(key)->galoiskeys.save(ofGalois);
    ofConfig << (unsigned char) (e3seal::toek(key)->isBatchEncoder);
    cout << "ok\n";
}
