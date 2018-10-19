#include "e3int.h"

int main()
{
	using Number = TypeInt<8>;
	Number a = _3_N;
	std::cout<<(a+_2_N)<<'\n';
}
