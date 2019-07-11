#include <fstream>
#include <iostream>

#include "ek_circ_heli.h"
#include "def_heli1.h"

using std::cout;

bool CircuitEvalKey_heli::load()
{
    init_properties_heli(&properties, name);
    key = new FHEPubKey(*properties->pcontext);

    if (e3heli::PRN)
        std::cout << "loading ek " <<  filename() << " : " << std::flush;

    FHEPubKey & k = *e3heli::toek(key);
    std::ifstream in(filename());

    if ( !in )
    {
        if (e3heli::PRN) std::cout << "failed\n";
        return false;
    }

    in >> k;
    if (e3heli::PRN) std::cout << "done\n";
    return true;
}

///std::string CircuitEvalKey_heli::decor(const std::string & s, bool add) const{    return prefix(s, add, "H");}

std::string CircuitEvalKey_heli::filename() const { return EvalKey::filename(); }
