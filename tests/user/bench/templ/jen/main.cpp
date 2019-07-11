#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

using namespace std;

#ifndef SZ
#define SZ 32
#endif

template <class T>
T jenkins_one_at_a_time_hash(const vector<T> & key)
{
    size_t i = 0;
    T hash = _0_E;
    T ten = _10_E;
    T six = _6_E;
    while (i != key.size())
    {
        hash += key[i++];
        hash += hash << ten;
        hash ^= hash >> six;
    }
    hash += hash << _3_E;
    hash ^= hash >> _11_E;
    hash += hash << _15_E;
    return hash;
}

int main(void)
{
    vector<SecureInt<SZ>>  vi = {_1_E, _2_E};
    Timer t;
    auto resi = jenkins_one_at_a_time_hash(vi);
    auto r = t.get();
    // cout << resi << '\n';
    cout << "Runtime: " << r << " us\n";
}
