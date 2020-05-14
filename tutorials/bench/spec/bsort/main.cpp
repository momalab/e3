#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"
#include "../circuits.inc"

#include "e3key.h"
template<class T> inline std::string de(T x) { return e3::decrypt<T>(x); }

#ifndef SZ
#define SZ 8
#endif

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;
//using SecureMint = TypeMint;
using SecureBit  = TypeBit;

template <class T>
void printArray(const vector<T> & arr)
{
    for ( size_t i = 0; i < arr.size(); i++ )
        cout << ' ' << de(arr[i]);
    std::cout << std::endl;
}

void bubbleSort(vector<SecureInt> & arr)
{
    auto n = arr.size();
    SecureInt smaller;
    SecureBool cond;

    for ( size_t i = 0; i < n - 1; i++ )
    {
        for ( size_t j = 0; j < n - i - 1; j++ )
        {
            // cond = arr[j] <= arr[j + 1];
            // smaller = e3::mux( cond, arr[j], arr[j + 1] );
            // arr[j + 1] = e3::mux( cond, arr[j + 1], arr[j] );
            // arr[j] = smaller;
            SecureInt current_in = arr[j];
            SecureInt next_in = arr[j+1];
            bsort_round<SecureInt, SecureBit>(arr[j], arr[j+1], current_in, next_in);
        }
    }
}

int main()
{
    vector<SecureInt> a = { _7_Ep, _12_Ep, _2_Ep, _0_Ep, _1_Ep, _15_Ep };
    Timer t;
    bubbleSort(a);
    auto r = t.get();
    printArray(a);
    cout << "Runtime: " << r << " us\n";
}
