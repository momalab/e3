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
using SecureMint = TypeMint;

template <class T>
void printMatrix(const vector<vector<T>> & m)
{
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m[0].size(); j++) cout << ' ' << de(m[i][j]);
        cout << std::endl;
    }
}

template <class T>
vector<vector<T>> matrixMul
(const vector<vector<T>> & a, const vector<vector<T>> & b, const T & zero)
{
    vector<vector<T>> c (a.size(), vector<T>(b[0].size()));

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
        auto c = matrixMul<SecureMint>(a, b, _0_Ea);
        auto r = t.get();
        printMatrix(c);
        cout << "SecureMint Runtime: " << r << " us\n";
    }
}
