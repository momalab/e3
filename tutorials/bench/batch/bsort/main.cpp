/*
This program performs the bubble sorting algorithm on a vector of
packed ciphertexts returns the sorted vector.
*/

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
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;
//using SecureMint = TypeMint;

// Function for printing vector
template <class T>
void printArray(const vector<T> & arr)
{
    for ( size_t i = 0; i < arr.size(); i++ )
        cout << ' ' << de(arr[i]);
    std::cout << std::endl;
}

// bubble sorting function
void bubbleSort(vector<SecureInt> & arr)
{
    auto n = arr.size();
    SecureInt smaller;
    SecureBool cond;

    for ( size_t i = 0; i < n - 1; i++ )
    {
        for ( size_t j = 0; j < n - i - 1; j++ )
        {
            cond = arr[j] <= arr[j + 1];
            smaller = e3::mux( cond, arr[j], arr[j + 1] );
            arr[j + 1] = e3::mux( cond, arr[j + 1], arr[j] );
            arr[j] = smaller;
        }
    }
}

int main()
{
    //vector of packed ciphertexts
    vector<SecureInt> a = { _7_4_3_8_1_0_Ep, _12_0_2_7_2_0_Ep, _2_1_9_3_5_0_Ep, _0_12_13_1_7_0_Ep, _1_2_3_4_5_0_Ep, _15_14_7_3_2_0_Ep };
    Timer t;
    bubbleSort(a);
    auto r = t.get();
    printArray(a);
    cout << "Runtime: " << r << " us\n";
}
