/*
This program performs matrix multiplication on two 3x3 matrices of
packed ciphertexts
*/
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

//Function for printing matrix
template <class T>
void printMatrix(const vector<vector<T>> & m)
{
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m[0].size(); j++) cout << ' ' << de(m[i][j]);
        cout << std::endl;
    }
}

//Function for multiplying two matrices
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
    //A matrix is declared as a vector of vectors
    //The inner vectors are the rows and their elements are the columns
    {
        vector<vector<SecureMint>> a = {  \
            { _1_2_3_1_0_Ea, _2_5_1_2_0_Ea, _3_9_1_3_0_Ea }, \
            { _2_1_0_2_0_Ea, _3_4_2_3_0_Ea, _4_6_1_4_0_Ea }, \
            { _3_3_4_3_0_Ea, _4_7_1_4_0_Ea, _5_6_8_5_0_Ea }
        };
        vector<vector<SecureMint>> b = {  \
            { _1_2_3_1_0_Ea, _2_5_1_2_0_Ea, _3_9_1_3_0_Ea }, \
            { _2_1_0_2_0_Ea, _3_4_2_3_0_Ea, _4_6_1_4_0_Ea }, \
            { _3_3_4_3_0_Ea, _4_7_1_4_0_Ea, _5_6_8_5_0_Ea }
        };
        Timer t;
        auto c = matrixMul<SecureMint>(a, b, _0_Ea);
        auto r = t.get();
        printMatrix(c);
        cout << "SecureMint Runtime: " << r << " us\n";
    }
}
