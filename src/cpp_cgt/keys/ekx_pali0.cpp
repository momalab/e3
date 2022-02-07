// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>

#include "cgtutil.h"
#include "olc.h"

#include "ekx_pali.h"

void e3::PaliBfvEvalKeyExt::save()
{
    std::ofstream of(filename(), std::ios::binary);
    of << polyDegree << "\n";
    of << mulDepth << "\n";
    of << useSlots << "\n";
    of << maxDepth << "\n";
    of << p_n << "\n";
}
