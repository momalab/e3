/*
    The content of the matrices 'a', 'b', and 'c' is sensitive
    Change the datatype from 'int' to 'Sensitive' for the appropriate variables
    Make the code data oblivious
*/

#include <iostream>
#include <vector>

using Sensitive = int;
using namespace std;

vector<vector<int>> matrixMultiplication(const vector<vector<int>> & a, const vector<vector<int>> & b)
{
    vector<vector<int>> c (a.size(), vector<int>(b[0].size()));
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < b[0].size(); j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < b.size(); k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    return c;
}

void printMatrix(const vector<vector<int>> & m)
{
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m[0].size(); j++) cout << m[i][j] << ' ';
        cout << '\n';
    }
}

int main(void)
{
    vector<vector<int>> a = {  \
        { 1, 2, 3 }, \
        { 2, 3, 4 }, \
        { 3, 4, 5 }
    };
    vector<vector<int>> b = {  \
        { -1, 2, 3 }, \
        { -2, 3, 4 }, \
        { -3, 4, 5 }
    };

    auto c = matrixMultiplication(a, b);
    printMatrix(c);
}
