#include <iostream>
#include <string>
#include <vector>

#include "e3int.h"
#include "e3key.h"

using namespace std;

template<class T> inline std::string de(T x) { return e3::decrypt<T>(x); }

void test0(Secure x, Secure y)
{
    cout << de(x) << " * " << de(y) << " = " << de(x * y) << '\n';
    cout << de(x) << " + " << de(y) << " = " << de(x + y) << '\n';

    for ( int i = 0; i < 23; i++ )
        cout << de(++x) << ' ';

    cout << '\n';

    cout << de(x) << " + " << de(y) << " = " << de(x + y) << '\n';
    cout << de(x) << " - " << de(y) << " = " << de(x - y) << '\n';
    cout << de(x) << " + (" << 7 << ") = " << de(x + 7) << '\n';
    cout << de(x) << " * " << de(y) << " = " << de(x * y) << '\n';
}

void test1()
{
    Secure x = _2_En, y = _3_En;
	test0(x,y);
}

void test2()
{
    Secure x = _1_2_En, y = _2_3_En;
	test0(x,y);
}

void test3()
{
	Secure::query()->print();
}

int main(int ac, char * av[])
try
{
	test1(); cout<<'\n';
	test2();
	test3();
}
catch (string e)
{
    cout << "Error: " << e << "\n";
}
catch (const char * e)
{
    cout << "Error: " << e << "\n";
}
catch (std::exception& e)
{
    cout << "Error (std): " << e.what() << endl;
}
catch (...)
{
    cout << "exception\n";
}
