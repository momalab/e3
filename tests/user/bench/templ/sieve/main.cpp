#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

using namespace std;

#ifndef SZ
#define SZ 32
#endif

template <class T>
void printVector(const vector<T> & v)
{
    for (size_t p = 2; p < v.size(); p++)
        cout << v[p] << ' ';
    cout << std::endl;
}

vector<SecureUint<SZ>> sieveOfEratosthenes(size_t n)
{
    vector<SecureUint<SZ>> ret (n + 1);
    vector<SecureBool> prime (n + 1, _1_E);
    for (int p = 2; p * p < n + 1 ; p++)
    {
        for (int i = 2 * p; i < n + 1 ; i += p) // Update all multiples of p
            prime[i] = _0_E;
    }
    SecureUint<SZ> pe = _2_E;
    for (int p = 2; p < n + 1; pe++, p++)
        ret[p] = pe * prime[p];
    return ret;
}

int main(void)
{
    const size_t n = 100;
    Timer t;
    auto vu = sieveOfEratosthenes(n);
    auto r = t.get();
    // printVector(vu);
    cout << "Runtime: " << r << " us\n";
}
