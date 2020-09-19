/*
    The content of the array 'arr' is sensitive
    Change the datatype from 'int' to 'Secure' for the appropriate variables
    Make the code data oblivious
*/

#include <iostream>

using namespace std;

void swap(int & x, int & y)
{
    int temp = x;
    x = y;
    y = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j + 1] < arr[j])
                swap(arr[j], arr[j + 1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) cout << ' ' << arr[i];
    cout << '\n';
}

// Driver program to test above functions
int main()
{
    int arr[] = {5, 12, 9, 2}; // values to be secret
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array :"; printArray(arr, n);
    bubbleSort(arr, n);
    cout << "Sorted  array  :"; printArray(arr, n);
}
