#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

using namespace std;

#ifndef SZ
#define SZ 32
#endif

//#define ROR(x, r) ((x >> r) | (x << ((sizeof(uint16_t) * 8) - r)))
//#define ROL(x, r) ((x << r) | (x >> ((sizeof(uint16_t) * 8) - r)))
#define ROR(x, r, one) ((x >> r) | (x << (one*SecureUint<SZ>::size() - r)))
#define ROL(x, r, one) ((x << r) | (x >> (one*SecureUint<SZ>::size() - r)))
#define R(x, y, k, seven, two, one) (x = ROR(x, seven, one), x += y, x ^= k, y = ROL(y, two, one), y ^= x)

template <class T>
void printVector(const vector<T> & v)
{
    for (size_t i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << std::endl;
}

template <class T>
vector<T> speck_expand(const vector<T> & key, size_t rounds)
{
    vector<T> s (rounds);
    T b = key[0];
    vector<T> a (key.size() - 1);
    for (size_t i = 0; i < a.size() ; i++)
    {
        a[i] = key[i + 1];
    }
    s[0] = b;
    T ei = _0_E;
    T seven = _7_E;
    T two = _2_E;
    T one = _1_E;
    for (size_t i = 0; i < rounds - 1; i++, ei++)
    {
        R(a[i % a.size()], b, ei, seven, two, one);
        s[i + 1] = b;
    }
    return s;
}

int main(void)
{
    // vector<SecureUint<SZ>> keyi = { _256_E, _2312_E, _4368_E, _6424_E };
    vector<SecureUint<SZ>> keyi = { _6_E, _12_E, _8_E, _4_E };
    const size_t rounds = 11;
    Timer t;
    auto expi = speck_expand(keyi, rounds);
    auto r = t.get();
    // printVector(expi);
    cout << "Runtime: " << r << " us\n";
}
