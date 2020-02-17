#include <iostream>
#include "e3int.h"

int main()
{
	SecureInt<4> a = _2_E;
	SecureInt<4> b = _3_E;
	std::cout << "add: " << (a+b) << '\n';
	std::cout << "mul: " << (a*b) << '\n';
}
