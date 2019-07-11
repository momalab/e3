#include <iostream>
#include <string>
#include <vector>

#include "e3int.h"

using namespace std;


template<class U, class B>
void validateGates(U zero, U unit)
{
    U s = zero;

    s[0] = B::gate_or(zero[0], unit[0]);
    cout << " " << zero << " | " << unit << " = " << s << '\n';
}

int main(int ac, char * av[])
try
{
    validateGates<FUint<1>, FBit>(_0_Ef, _1_Ef);
}
catch (string e)
{
    cout << "Error: " << e << "\n";
}
catch (...)
{
    cout << "exception\n";
}
