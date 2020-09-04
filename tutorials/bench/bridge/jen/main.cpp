#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#include "e3key.h"
template<class T> inline std::string de(T x) { return e3::decrypt<T>(x); }

#ifndef SZ
#define SZ 8
#endif

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;
//using SecureMint = TypeMint;

SecureInt jenkins_one_at_a_time_hash(const vector<SecureInt> & key)
{
    size_t i = 0;
    SecureInt hash = _0_Ep;
    SecureInt ten = _10_Ep;
    SecureInt six = _6_Ep;
    while (i != key.size())
    {
        hash += key[i++];
        hash += hash << ten;
        hash ^= hash >> six;
    }
    hash += hash << SecureInt(_3_Ep);
    hash ^= hash >> SecureInt(_11_Ep);
    hash += hash << SecureInt(_15_Ep);
    return hash;
}

int main(void)
{
    vector<SecureInt> v = { _1_Ep, _2_Ep };
    Timer t;
    auto res = jenkins_one_at_a_time_hash(v);
    auto r = t.get();
    cout << de(res) << '\n';
    cout << "Runtime: " << r << " us\n";
}
