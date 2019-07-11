#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#ifndef SZ
#define SZ 32
#endif

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;
using SecureMint = TypeMint;

template <class T>
void printMatrix(const vector<vector<T>> & m)
{
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m[0].size(); j++) cout << m[i][j] << ' ';
        cout << std::endl;
    }
}

vector<vector<SecureMint>> matrixMul(const vector<vector<SecureMint>> & a, const vector<vector<SecureMint>> & b)
{
    vector<vector<SecureMint>> c (a.size(), vector<SecureMint>(b[0].size()));
    SecureMint zero = _0_Ea;
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < b[0].size(); j++)
        {
            c[i][j] = zero;
            for (size_t k = 0; k < b.size(); k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main(void)
{
    vector<vector<SecureMint>> a = {  \
        { _1_Ea, _2_Ea, _3_Ea }, \
        { _2_Ea, _3_Ea, _4_Ea }, \
        { _3_Ea, _4_Ea, _5_Ea }
    };
    vector<vector<SecureMint>> b = {  \
        { _1_Ea, _2_Ea, _3_Ea }, \
        { _2_Ea, _3_Ea, _4_Ea }, \
        { _3_Ea, _4_Ea, _5_Ea }
    };
    Timer t;
    auto c = matrixMul(a, b);
    auto r = t.get();
    // printMatrix(c);
    cout << "Runtime: " << r << " us\n";
}
