#include "ek_abstract.h"


void EvalKey::loadOrDie()
{
    if (!load()) throw "Cannot load the key [" + filename() + "]";
}

