#include <iostream>

using Secure = int;
using SecureBool = int;

using namespace std;

void swap(Secure & x, Secure & y, SecureBool cond)
{
    auto t = x ;
    x = cond * y + !cond * x;
    y = cond * t + !cond * y;
}

void bubbleSort(Secure arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            swap(arr[j], arr[j + 1], arr[j + 1] < arr[j] );
}

void printArray(Secure arr[], int size)
{
    for (int i = 0; i < size; i++) cout << ' ' << arr[i];
    cout << '\n';
}

int main()
{
    Secure arr[] = {5, 12, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array :"; printArray(arr, n);
    bubbleSort(arr, n);
    cout << "Sorted  array  :"; printArray(arr, n);
}
