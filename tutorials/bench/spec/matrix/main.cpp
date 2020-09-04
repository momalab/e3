#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"
#include "../circuits.inc"

#include "e3key.h"
template<class T> inline std::string de(T x) { return e3::decrypt<T>(x); }

#ifndef SZ
#define SZ 8
#endif

using namespace std;
using SecureInt  = TypeUint<SZ>;
using SecureBool = TypeBool;
using SecureBit  = TypeBit;

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
                SecureInt c_in = c[i][j];
                matrix_round<SecureInt, SecureBit>(c[i][j], a[i][k], b[k][j], c_in);
            }
        }
    }
    return c;
}

int main(void)
{
    {
        vector<vector<SecureInt>> a = {  \
            { _1_Ep, _2_Ep, _3_Ep }, \
            { _2_Ep, _3_Ep, _4_Ep }, \
            { _3_Ep, _4_Ep, _5_Ep }
        };
        vector<vector<SecureInt>> b = {  \
            { _1_Ep, _2_Ep, _3_Ep }, \
            { _2_Ep, _3_Ep, _4_Ep }, \
            { _3_Ep, _4_Ep, _5_Ep }
        };
        Timer t;
        auto c = matrixMul<SecureInt>(a, b, _0_Ep);
        auto r = t.get();
        printMatrix(c);
        cout << "SecureInt Runtime: " << r << " us\n";
    }
}
