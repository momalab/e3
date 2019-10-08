#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_arith_seal.h"
#include "def_seal1.h"

using namespace seal;
using std::cout;

void e3::SealBaseEvalKeyExt::save()
{
    cout << "Saving evaluation key .. " << std::flush;
    auto fileParams = filename() + ".params.key";
    auto fileRelin  = filename() + ".relin.key";
    std::ofstream ofParams(fileParams, std::ios::binary);
    std::ofstream ofRelin (fileRelin , std::ios::binary);
    EncryptionParameters::Save( *(e3seal::toek(key)->params), ofParams );
    e3seal::toek(key)->relinkeys.save(ofRelin);
    cout << "ok\n";
}
