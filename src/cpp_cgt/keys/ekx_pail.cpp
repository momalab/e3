#include <cstdlib>
#include <sstream>
#include <fstream>

#include "cgtutil.h"
#include "olc.h"

#include "ekx_pail.h"

void e3::PailEvalKeyExt::save()
{
    std::ofstream of(filename(), std::ios::binary);
    of << N << "\t";
}
