#include <iostream>
#include <fstream>

#include "ek_arith_seal.h"
#include "def_seal1.h"

using std::cout;
using namespace seal;

bool e3::SealBaseEvalKey::load(string fname)
{
    if (!NOCOUT) cout << "Loading evaluation key .. " << std::flush;

    auto fileParams = fname + ".params.key";
    auto fileRelin  = fname + ".relin.key";
    std::ifstream inParams(fileParams, std::ios::binary);
    std::ifstream inRelin (fileRelin , std::ios::binary);
    if ( !inParams || !inRelin ) return false;

    static e3seal::SealEvalKey evalkey;
    try
    {
        static auto params = EncryptionParameters::Load(inParams);
        evalkey.context = SEALContext::Create(params);
        ///static auto evaluator = Evaluator(evalkey.context);
        static Evaluator evaluator(evalkey.context);
        evalkey.params = &params;
        evalkey.evaluator = &evaluator;
        evalkey.relinkeys.load(evalkey.context, inRelin);
    }
    catch (...) { throw "Bad " + filename() + " eval key"; }

    key = &evalkey;

    if (!NOCOUT) cout << "ok\n";
    return true;
}
