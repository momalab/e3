#include "ek_abstract.h"


void e3::EvalKey::loadOrDie()
{
    if (!load()) throw "Cannot load the key [" + filename() + "]";
}

