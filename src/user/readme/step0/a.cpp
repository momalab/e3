#include <iostream>

#include "e3int.h"
//#include "e3key.h"

int main()
{
    SecureInt<32> a=2, b=3;
    std::cout << a * b << '\n';
    //std::cout << e3::decrypt(a * b) << '\n';
}
