#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#ifndef SZ
#define SZ 8
#endif

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;

template <class T>
void printVector(const vector<T> & v)
{
    for ( size_t i = 0; i < v.size(); i++ ) cout << v[i] << ' ';
    cout << std::endl;
}

void insertionSort(vector<SecureInt> & v)
{
    for ( size_t i = 1 ; i < v.size() ; i++ )
    {
        auto j = i;
        while ( j != 0 )
        {
            SecureInt x = v[j - 1];
            SecureInt & y = v[j];

            SecureBool cond = x > y;
            v[j - 1] = cond.mux(y, x); // min
            v[j] = cond.mux(x, y); // max

            j--;
        }
    }
}

int main(void)
{
    vector<SecureInt> v = { _4_Ep, _2_Ep, _5_En, _9_Ep };
    Timer t;
    insertionSort(v);
    auto r = t.get();
    // printVector(v);
    cout << "Runtime: " << r << " us\n";
}
