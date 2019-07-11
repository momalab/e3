#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

#ifndef SZ
#define SZ 8
#endif

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;

template <class T>
void printMatrix(const vector<vector<T>> & m)
{
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m[0].size(); j++) cout << m[i][j] << ' ';
        cout << std::endl;
    }
}

vector<vector<SecureInt>> matrixMul(const vector<vector<SecureInt>> & a, const vector<vector<SecureInt>> & b)
{
    vector<vector<SecureInt>> c (a.size(), vector<SecureInt>(b[0].size()));
    SecureInt zero = _0_Ep;
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
    vector<vector<SecureInt>> a = {  \
        { _1_Ep, _2_Ep, _3_Ep }, \
        { _2_Ep, _3_Ep, _4_Ep }, \
        { _3_Ep, _4_Ep, _5_Ep }
    };
    vector<vector<SecureInt>> b = {  \
        { _1_En, _2_Ep, _3_Ep }, \
        { _2_En, _3_Ep, _4_Ep }, \
        { _3_En, _4_Ep, _5_Ep }
    };

    Timer t;
    auto c = matrixMul(a, b);
    auto r = t.get();

    // printMatrix(c);
    cout << "Runtime: " << r << " us\n";
}
