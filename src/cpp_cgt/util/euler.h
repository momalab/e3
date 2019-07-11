
#include "olrnd.h"
#include "def_mpir.h"

const int TESTNPRIMES = 3;

namespace euler
{

Bigun prime(int lam, Rnd * rnd, Bigun skip);
bool isprime(Bigun x);
Bigun random(Bigun mod, Rnd * rnd);
///bool invert(Bigun x, Bigun mod, Bigun &res);

template<class T> inline T gcd(T a, T b)
{
    if ( b == T(0) ) return a;
    return gcd(b, a % b);
}

} //euler


