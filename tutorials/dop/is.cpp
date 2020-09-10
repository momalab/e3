/*
    The content of the array 'v' is sensitive
    Change the datatype from 'int' to 'Sensitive' for the appropriate variables
    Make the code data oblivious
*/

#include <iostream>
#include <vector>

using Sensitive = int;
using namespace std;

void insertionSort(vector<int> & v)
{
    for ( int i = 1 ; i < v.size() ; i++ )
    {
        auto key = v[i];
        auto j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

void printVector(const vector<int> & v)
{
    for ( size_t i = 0; i < v.size(); i++ ) cout << v[i] << ' ';
    cout << '\n';
}

int main(void)
{
    vector<int> v = {4, 2, -5, 9};
    insertionSort(v);
    printVector(v);
}
