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
    for ( size_t i = 0; i < v.size(); i++ ) cout << v[i] << ' ';
    cout << std::endl;
}

template <class T>
void insertionSort(vector<T> & v)
{
    for ( size_t i = 1 ; i < v.size() ; i++ )
    {
        auto j = i;
        while ( j != 0 )
        {
            T x = v[j - 1];
            T & y = v[j];

            SecureBool cond = x > y;
            v[j - 1] = cond.mux(y, x); // min
            v[j] = cond.mux(x, y); // max

            j--;
        }
    }
}

int main(void)
{
    vector<SecureInt<SZ>>  vi = {_4_E, _2_E, _5_En, _9_E};
    Timer t;
    insertionSort(vi);
    auto r = t.get();
    // printVector(vi);
    cout << "Runtime: " << r << " us\n";
}
