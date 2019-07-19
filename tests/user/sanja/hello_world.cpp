#include <iostream>
#include <utility>

#include "e3int.h"
#include "../alice.h"

using namespace std;
using SecureInt = PilcUint<8>;

// _1_Em

int main()
try
{
    SecureInt num1 = _2_Eu;
    SecureInt num2 = _2_Eu;
    SecureInt res = _0_Eu;

    res = num1 + num2;

    std::cout << "Hello World \n";
    std::cout << "num1 = " << num1 << "\n";
    std::cout << "num1d = " << dec(num1) << "\n";
    std::cout << "num2 = " << num2 << "\n";
    std::cout << "Result = " << dec(res) << "\n";

    PilMint pm = _3_Em;
    std::cout << "PilMint3: " << dec(pm) << "\n";
}
catch (string e)
{
    cout << "Error: " << e << "\n";
    return 1;
}
catch (...)
{
    cout << "Exception\n";
    return 1;
}
