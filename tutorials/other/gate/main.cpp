#include <iostream>
#include <vector>
#include "gate_functions.h"

using namespace std;

int main()
{
    // We create SecureBits by creating SecureInts or SecureBools.
    // Then, we access the individual bits of the SecureInt/SecureBools
    // to get the SecureBits.
    SecureUint<2> n = _2_Ep;
    vector<SecureBit> b = { n[0], n[1] };

    vector<SecureBool> c(2);
    c[0][0] = b[0];
    c[1][0] = b[1];
    cout << "Bit 0: " << c[0] << "\n";
    cout << "Bit 1: " << c[1] << "\n";

    // We can operate on SecureBits by calling gate functions
    cout << "\n";
    for ( size_t i=0; i<b.size(); i++ )
        cout << "NOT( " << c[i] << " ) = " << gate_not( b[i] ) << "\n";

    cout << "\n";
    for ( size_t i=0; i<b.size(); i++ )
        for ( size_t j=0; j<b.size(); j++ )
            cout << "AND( " << c[i] << " , " << c[j] << " ) = " << gate_and(b[i],b[j]) << "\n";

    cout << "\n";
    for ( size_t i=0; i<b.size(); i++ )
        for ( size_t j=0; j<b.size(); j++ )
            cout << "OR( " << c[i] << " , " << c[j] << " ) = " << gate_or(b[i],b[j]) << "\n";

    cout << "\n";
    for ( size_t i=0; i<b.size(); i++ )
        for ( size_t j=0; j<b.size(); j++ )
            cout << "XOR( " << c[i] << " , " << c[j] << " ) = " << gate_xor(b[i],b[j]) << "\n";

    cout << "\n";
    for ( size_t i=0; i<b.size(); i++ )
        for ( size_t j=0; j<b.size(); j++ )
            cout << "NAND( " << c[i] << " , " << c[j] << " ) = " << gate_nand(b[i],b[j]) << "\n";

    cout << "\n";
    for ( size_t i=0; i<b.size(); i++ )
        for ( size_t j=0; j<b.size(); j++ )
            cout << "NOR( " << c[i] << " , " << c[j] << " ) = " << gate_nor(b[i],b[j]) << "\n";

    cout << "\n";
    for ( size_t i=0; i<b.size(); i++ )
        for ( size_t j=0; j<b.size(); j++ )
            cout << "XNOR( " << c[i] << " , " << c[j] << " ) = " << gate_xnor(b[i],b[j]) << "\n";

    cout << "\n";
    for ( size_t i=0; i<b.size(); i++ )
        for ( size_t j=0; j<b.size(); j++ )
            for ( size_t k=0; k<b.size(); k++ )
            cout << "MUX( " << c[i] << " , " << c[j] << " , " << c[k] << " ) = " << gate_mux(b[i],b[j],b[k]) << "\n";
}
