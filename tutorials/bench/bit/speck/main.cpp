#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#include "e3key.h"
template<class T> inline std::string de(T x) { return e3::decrypt<T>(x); }

#ifndef SZ
#define SZ 8
#endif

#define N_ROUNDS 11

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;

//#define ROR(x, r) ((x >> r) | (x << ((sizeof(uint16_t) * 8) - r)))
//#define ROL(x, r) ((x << r) | (x >> ((sizeof(uint16_t) * 8) - r)))
#define ROR(x, r, one) ((x >> r) | (x << (one*SecureInt::size - r)))
#define ROL(x, r, one) ((x << r) | (x >> (one*SecureInt::size - r)))
#define R(x, y, k, seven, two, one) (x = ROR(x, seven, one), x += y, x ^= k, y = ROL(y, two, one), y ^= x)

#define PROR(x, r) ((x >> r) | (x << (SecureInt::size - r)))
#define PROL(x, r) ((x << r) | (x >> (SecureInt::size - r)))
#define PR(x, y, k) (x = PROR(x, 7), x += y, x ^= k, y = PROL(y, 2), y ^= x)

template <class T>
void printVector(const vector<T> & v)
{
    for (size_t i = 0; i < v.size(); i++) cout << ' ' << de(v[i]);
    cout << std::endl;
}

vector<SecureInt> speck_expand(const vector<SecureInt> & key, size_t rounds)
{
    vector<SecureInt> s (rounds);
    SecureInt b = key[0];
    vector<SecureInt> a (key.size() - 1);
    for (size_t i = 0; i < a.size() ; i++)
    {
        a[i] = key[i + 1];
    }
    s[0] = b;
    SecureInt ei = _0_Ep;
    //SecureInt seven = _7_Ep;
    //SecureInt two = _2_Ep;
    //SecureInt one = _1_Ep;
    for (size_t i = 0; i < rounds - 1; i++, ei++)
    {
        auto & x = a[i % a.size()];
        //R(x, b, ei, seven, two, one); // slow
        PR(x, b, ei); // fast
        s[i + 1] = b;
    }
    return s;
}

int main(void)
{
    vector<SecureInt> key = { _6_Ep, _12_Ep, _8_Ep, _4_Ep };
    Timer t;
    auto exp = speck_expand(key, N_ROUNDS);
    auto r = t.get();
    printVector(exp);
    cout << "Runtime: " << r << " us\n";
}
