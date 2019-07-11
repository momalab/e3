#include <iostream>
#include <fstream>

#include "cipherbit.h"


Key Cipherbit::key;

void Key::init()
{
    std::ifstream in("eval.key");
    if ( !in ) throw "Cannot open eval key";
    in >> k;
}
