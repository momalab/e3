#include <iostream>

#include "e3int.h"

int main()
{
	SecureInt<8> a = _2_E;
	SecureInt<8> b = _3_E;
	std::cout << (a*b) << '\n';
}

