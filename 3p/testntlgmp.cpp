//g++ -std=c++14 testntlgmp.cpp -lgmp -lntl -o testntlgmp.exe
#include <gmp.h>
#include <NTL/pair.h>

#include <iostream>
int main()
{
    mpz_t a;
    NTL::Pair<int, int> b;
    std::cout << "NTL/GMP installed\n";
}

