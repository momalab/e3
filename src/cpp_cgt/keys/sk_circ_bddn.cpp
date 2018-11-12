#include <fstream>

#include "e3util.h"
#include "sk_circ_bddn.h"

CircuitPrivKey_bddn::CircuitPrivKey_bddn
(std::string name, bool forceGen, bool forceLoad, std::string seed, int lam)
    : CircuitPrivKey(name, seed, lam, &ek), ek(name)
{
    init_final(forceGen, forceLoad);
}

void CircuitPrivKey_bddn::gen()
{
	FIX;
}

string CircuitPrivKey_bddn::filename()
{
	FIX;
}

void CircuitPrivKey_bddn::save()
{
	FIX;
}

bool CircuitPrivKey_bddn::load()
{
	FIX;
}

std::string CircuitPrivKey_bddn::encbitstr(bool b) const
{
	FIX;
}

bool CircuitPrivKey_bddn::decbitstr(const std::string & s, bool * ok) const
{
	FIX;
}

