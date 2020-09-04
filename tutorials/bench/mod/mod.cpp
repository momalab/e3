#include <iostream>
#include "e3int.h"
#include "e3key.h"

using namespace std;

int main()
{
    Secure a = _3_E, b = _2_E;
    Secure sum, sub, mul;

    sum = a + b;
    sub = a - b;
    mul = a * b;

    cout << a << " + " << b << " = " << sum << "\n";
    cout << a << " - " << b << " = " << sub << "\n";
    cout << a << " * " << b << " = " << mul << "\n";
}
