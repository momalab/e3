#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#include "e3key.h"
template<class T> inline std::string de(T x) { return e3::decrypt<T>(x); }

#ifndef SZ
#define SZ 8
#endif
#define N_ELEMS 101

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;

template <class T>
void printVector(const vector<T> & v)
{
    bool z = false;
    for (size_t p = 2; p < v.size(); p++)
        if ( p < 10 || p + 10 > v.size() )
            cout << ' ' << de(v[p]);
        else
        {
            if (z) continue;
            z = true;
            cout << " ... ";
        }
    cout << std::endl;
}

template <class T>
vector<T> sieveOfEratosthenes(size_t n, const T & one)
{
    vector<T> ret (n + 1);

    vector<SecureBool> prime (n + 1, _1_Ep);
    for (int p = 2; p * p < n + 1 ; p++)
    {
        for (int i = 2 * p; i < n + 1 ; i += p) // Update all multiples of p
            prime[i] = _0_Ep;
    }

    T pe = 2 * one;
    for (int p = 2; p < n + 1; pe += one, p++)
        ret[p] = pe * prime[p];

    return ret;
}

int main(void)
{
    {
        Timer t;
        auto v = sieveOfEratosthenes<SecureInt>(N_ELEMS, _1_Ep);
        auto r = t.get();
        printVector(v);
        cout << "SecureInt Runtime: " << r << " us\n";
    }
}
