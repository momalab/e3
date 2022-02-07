// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>

#include "cgtutil.h"
#include "olc.h"

#include "ekx_pil.h"

void e3::PilBaseEvalKeyExt::save()
{
    std::ofstream of(filename(), std::ios::binary);

    if ( kv.ver != 22 ) nevers("version");

    of << kv.N << "\t";
    of << kv.S.n << "\n";
    of << kv.A.n << "\t";
    of << kv.B.n << "\t";
    of << kv.C.n << "\n";
    of << kv.D.n << "\t";
    of << kv.E.n << "\t";
    of << kv.F.n << "\t";
}
