/*
    The input and output are Sensitive
    Change the datatype from 'unsigned' to 'Sensitive' for the appropriate variables
    Make the code data oblivious
*/

#include <iostream>

using Sensitive = unsigned;
using namespace std;

unsigned fibonacci(unsigned n)
{
    unsigned f = 0;
    unsigned f1 = 1;
    unsigned f2 = 1;
    for (unsigned i = 2; i < n; i++)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    return f;
}

int main()
{
    unsigned n = 7; // input
    auto f = fibonacci(n); // output
    cout << "fib(" << n << ") = " << f << '\n';
}
