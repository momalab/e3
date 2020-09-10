#include <iostream>

#include "secure3.h"

using namespace std;

void swap(Secure & x, Secure & y)
{
    auto temp = x;
    x = y;
    y = temp;
}

void bubbleSort(Secure arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j + 1] < arr[j])
                swap(arr[j], arr[j + 1]);
}

void printArray(Secure arr[], int size)
{
    for (int i = 0; i < size; i++) cout << ' ' << arr[i];
    cout << '\n';
}

int main()
{
    Secure arr[] = {64, 34, 25, 12, 22, 90, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array :"; printArray(arr, n);
    bubbleSort(arr, n);
    cout << "Sorted  array  :"; printArray(arr, n);
}
