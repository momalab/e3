#include <string>
#include <iostream>

#include "func.h"
#include "fib.h"

using std::cout;
using std::string;

int main()
try
{
    cout << "This must be [ enc(13) ] = " << Secure(Secure(_13_EN).str()) << '\n';
    cout << "This must be [ enc(-3) ] = " << Secure(Secure(_3_ENn).str()) << '\n';

    cout << "AAA 1\n";
    Secure x = _7_EN;
    cout << "AAA 2\n";
    Secure y = _3_ENn;
    cout << "AAA 3\n";
    //x + y;
    f(x,y);
    cout << "AAA 4\n";
    cout << "This must be [ enc (7) ] = " << x << '\n';
    cout << "AAA 5\n";
    // cout << x << " + " << y << " = " << f(x, y) << "\n";
    cout << "AAA 0\n";
    Secure natiNum = _7_EN;
    // Secure natiRes = fib(natiNum, 10);
    // cout << "fib( " <<  natiNum << " ) = " << natiRes << "\n";
}
//catch(...){ cout<<"ERR"; }
catch (int e)
{
    cout << " error (int): " << e << "\n";
    return 1;
}
catch (string e)
{
    cout << " error (str): " << e << "\n";
    return 1;
}
catch (const char * e)
{
    cout << " error (cc): " << e << "\n";
    return 1;
}
catch (...)
{
    cout << "Unknown exception\n";
    return 1;
}
