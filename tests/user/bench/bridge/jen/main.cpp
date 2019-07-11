#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#ifndef SZ
#define SZ 32
#endif

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;
using SecureMint = TypeMint;

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
    hash += hash << _3_Ep;
    hash ^= hash >> _11_Ep;
    hash += hash << _15_Ep;
    return hash;
}

int main(void)
{
    vector<SecureInt> v = { _1_Ep, _2_Ep };
    Timer t;
    auto res = jenkins_one_at_a_time_hash(v);
    auto r = t.get();
    // cout << res << '\n';
    cout << "Runtime: " << r << " us\n";
}
