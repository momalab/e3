// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include "def_palisade_ckks1.h"
#include "ekx_palisade_ckks.h"

namespace e3
{

void PalisadeCkksEvalKeyExt::save()
{
    palisade_ckks::Context & context = *palisade_ckks::toContext(key.cc);
    palisade_ckks::PublicKey & publicKey = *palisade_ckks::toPublicKey(key.pk);
    palisade_ckks::saveContext(context, name.fil);
    palisade_ckks::saveParams(name.fil, multDepth, scaleFactorBits, batchSize, securityLevel, ringDimension, rescale, rotations);
    palisade_ckks::savePublicKey(publicKey, name.fil);
    palisade_ckks::saveEvaluationKey(context, name.fil);
}

} // e3
