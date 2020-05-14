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
using SecureInt  = TypeInt<SZ>;
using SecureBool = TypeBool;

template <class T>
void printVector(const vector<T> & v)
{
    cout << "vector:" << std::flush;
    for ( size_t i = 0; i < v.size(); i++ )
        cout << ' ' << de(v[i]) << std::flush;
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
            v[j - 1] = e3::mux(cond, y, x); // min
            v[j] = e3::mux(cond, x, y); // max

            j--;
            //printVector(v);
        }
    }
}

int main(void)
try
{
    vector<SecureInt> v { _9_Ep, _2_Ep, _5_Ep, _4_Ep };
    printVector(v);
    Timer t;
    insertionSort(v);
    auto r = t.get();
    printVector(v);
    cout << "Runtime: " << r << " us\n";
}
catch (string e)
{
    cout << "Oops: " << e << "\n";
    return 1;
}
catch (...)
{
    cout << "Oops ...\n";
    return 1;
}
