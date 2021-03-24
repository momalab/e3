#include <iostream>
#include "e3int.h"
#include "e3key.h"

using namespace std;

int main()
try {
    cout << "main::Started\n";
    cout << "main::default constructor\n";
    Secure a;
    cout << "main::string constructor\n";
    Secure b = _2_3_E, add, sub, mul;
    a = _5_4_E;
    cout << "main::os\n";
    cout << e3::decrypt(a) << '\n';
    cout << e3::decrypt(b) << '\n';
    cout << "main::add\n"; add = a + b; cout << e3::decrypt(add) << '\n';
    cout << "main::sub\n"; sub = a - b; cout << e3::decrypt(sub) << '\n';
    cout << "main::mul\n"; mul = a * b; cout << e3::decrypt(mul) << '\n';
    cout << "main::Finished\n";
}
catch(const string & e) { cout << e << '\n'; }
