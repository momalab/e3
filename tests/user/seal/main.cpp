#include <iostream>
#include "e3int.h"

using namespace std;

int main()
{
    cout << "main::Started\n";
    SecureInt<8> a;
    cout << "main::1\n";
    a = _4_Ep;
    cout << "main::2\n";
    cout << a << '\n';
    cout << "main::Finished\n";
}
