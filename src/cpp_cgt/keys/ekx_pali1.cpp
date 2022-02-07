// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>

#include "cgtutil.h"
#include "olc.h"

#include "ekx_pali.h"
#include "def_pali1.h"

void e3::PaliBfvEvalKeyExt::save()
{
    e3::pali::Cc & cc = *e3::pali::tocc(key.cc);
    e3::pali::PubKey & pk = *e3::pali::topk(key.pk);

    e3::pali::save_context(cc, name.fil);
    e3::pali::save_pub_main(pk, name.fil);
    e3::pali::save_pub_eval(cc, name.fil);
    e3::pali::save_params(name.fil, polyDegree, mulDepth, useSlots, maxDepth, p_n);
}
