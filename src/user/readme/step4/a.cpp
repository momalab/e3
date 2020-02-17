#include <iostream>

#include "e3int.h"
#include "e3key.h"

int main()
{
	SecureInt<8> a = _2_E;
	SecureInt<8> b = _3_E;
	std::cout << e3::decrypt(a*b) << '\n';
}

