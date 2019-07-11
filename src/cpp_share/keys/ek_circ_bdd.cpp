#include <fstream>

#include "ek_circ_bdd.h"

bool CircuitEvalKey_bdd::load() { return true; }

std::string CircuitEvalKey_bdd::filename() const { return EvalKey::filename(); }

/*///
std::string CircuitEvalKey_bdd::decor(const std::string & s, bool add) const
{
    return prefix(s, add, name);
}

std::string CircuitEvalKey_bddn::decor(const std::string & s, bool add) const
{
    return prefix(s, add, "BN");
}

std::string CircuitEvalKey_bdda::decor(const std::string & s, bool add) const
{
    return prefix(s, add, "BA");
}

std::string CircuitEvalKey_bddf::decor(const std::string & s, bool add) const
{
    return prefix(s, add, "BF");
}
*/
