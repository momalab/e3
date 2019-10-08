#include <fstream>
#include <iostream>

#include "ek_circ_seal.h"
#include "def_seal1.h"

using namespace seal;
using std::cout;

bool e3::CircuitEvalKey_seal::load()
{
    if (!NOCOUT) cout << "Loading evaluation key .. " << std::flush;

    auto fileParams = filename() + ".params.key";
    auto fileRelin  = filename() + ".relin.key";
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

std::string e3::CircuitEvalKey_seal::filename() const { return EvalKey::filename(); }
