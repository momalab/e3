#include <iostream>
#include <utility>

#include "../../e3int.h"
#include "../alice.h"

using namespace std;
using SecureInt = PilcUint<8>;

int main()
{
    SecureInt num1 = _2_Eu;
    SecureInt num2 = _2_Eu;
    SecureInt res = _0_Eu;

    res = num1 + num2;

    std::cout << "Hello World \n";
    std::cout << "num1 = " << num1 << "\n";
    std::cout << "num1d = " << dec(num1,"Pilc") << "\n";
    std::cout << "num2 = " << num2 << "\n";
    std::cout << "Result = " << res << "\n";
}
