#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

using namespace std;

#ifndef SZ
#define SZ 32
#endif

template <class T>
void printMatrix(const vector<vector<T>> & m)
{
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m[0].size(); j++) cout << m[i][j] << ' ';
        cout << std::endl;
    }
}

template <class T>
vector<vector<T>> matrixMul(const vector<vector<T>> & a, const vector<vector<T>> & b)
{
    vector<vector<T>> c (a.size(), vector<T>(b[0].size()));
    T zero = _0_E;
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < b[0].size(); j++)
        {
            c[i][j] = zero;
            for (int k = 0; k < b.size(); k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main(void)
{
    vector<vector<SecureInt<SZ>>> ai = {  \
        { _1_E, _2_E, _3_E }, \
        { _2_E, _3_E, _4_E }, \
        { _3_E, _4_E, _5_E }
    };
    vector<vector<SecureInt<SZ>>> bi = {  \
        { _1_En, _2_E, _3_E }, \
        { _2_En, _3_E, _4_E }, \
        { _3_En, _4_E, _5_E }
    };

    Timer t;
    auto ci = matrixMul(ai, bi);
    auto r = t.get();

    // printMatrix(ci);
    cout << "Runtime: " << r << " us\n";
}
