#include <string>
#include <iostream>

#include "func.h"
#include "../alice.h"

using std::cout;
using std::string;

int main()
try
{
    cout << "This must be [ enc(13) ] = " << dec(Secure(Secure(_13_EN).str())) << '\n';
    cout << "This must be [ enc(-3) ] = " << dec(Secure(Secure(_3_ENn).str())) << '\n';

    {
        Secure x = _7_EN, y = _5_EN;
        cout << dec(x) << " & " << dec(y) << " = " << dec(x & y) << "\n";
    }
    {
        Secure x = _7_EN, y = _3_ENn;
        cout << dec(x) << " + " << dec(y) << " = " << dec(f(x, y)) << "\n";
    }
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
