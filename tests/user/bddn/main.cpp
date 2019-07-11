#include <string>
#include <iostream>

#include "func.h"
#include "../alice.h"

using std::cout;
using std::string;

inline string de(Secure x){ return decs(x); }

int main()
try
{
    cout << "This must be [ enc(13) ] = " << de(Secure(Secure(_13_EN).str())) << '\n';
    cout << "This must be [ enc(-3) ] = " << de(Secure(Secure(_3_ENn).str())) << '\n';

    {
        Secure x = _7_EN, y = _5_EN;
        cout << de(x) << " & " << de(y) << " = " << de(x & y) << "\n";
    }
    {
        Secure x = _7_EN, y = _3_ENn;
        cout << de(x) << " + " << de(y) << " = " << de(f(x, y)) << "\n";
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
