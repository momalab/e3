/*
    The input and output are Sensitive
    Change the datatype from 'unsigned' to 'Sensitive' for the appropriate variables
    Make the code data oblivious
*/

#include <iostream>

using Sensitive = unsigned;
using namespace std;

unsigned factorial(unsigned n)
{
    unsigned i;
    unsigned f = 1; // result
    for (i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

int main()
{
    unsigned n = 5; // input
    auto f = factorial(n); // output
    cout << "fact(" << n << ") = " << f << '\n';
}
