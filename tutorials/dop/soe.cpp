/*
    The content of the array 'v' is sensitive
    Change the datatype from 'unsigned' to 'Sensitive' for the appropriate variables
    Make the code data oblivious
*/

#include <iostream>
#include <vector>

using Sensitive = unsigned;
using namespace std;

vector<unsigned> sieveOfEratosthenes(unsigned n)
{
    vector<bool> prime (n + 1, true);
    for (unsigned p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (unsigned i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    vector<unsigned> ret (n + 1);
    for (unsigned p = 2; p <= n; p++)
        ret[p] = prime[p] ? p : 0;

    return ret;
}

void printVector(const vector<unsigned> & v)
{
    for (unsigned p = 2; p < v.size(); p++)
        cout << v[p] << ' ';
    cout << '\n';
}

int main(void)
{
    unsigned n = 30;
    auto v = sieveOfEratosthenes(n);
    printVector(v);
}
