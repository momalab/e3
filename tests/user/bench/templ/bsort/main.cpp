#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

using namespace std;

#ifndef SZ
#define SZ 32
#endif

template <class T>
void printArray(const vector<T> & arr)
{
    for ( size_t i = 0; i < arr.size(); i++ ) cout << arr[i] << " ";
    std::cout << std::endl;
}

template <class T>
void bubbleSort(vector<T> & arr)
{
    auto n = arr.size();
    T smaller;
    SecureBool cond;

    for ( size_t i = 0; i < n - 1; i++ )
    {
        for ( size_t j = 0; j < n - i - 1; j++ )
        {
            cond = arr[j] <= arr[j + 1];
            smaller = cond.mux(arr[j], arr[j + 1]);
            arr[j + 1] = cond.mux(arr[j + 1], arr[j]);
            arr[j] = smaller;
        }
    }
}

int main()
{
    vector<SecureInt<SZ>>  ai = {_7_E, _12_E, _2_E, _0_E, _1_En, _15_E};
    Timer t;
    bubbleSort(ai);
    auto r = t.get();
    // printArray(ai);
    cout << "Runtime: " << r << " us\n";
}
