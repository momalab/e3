// #include <dlfcn.h>
#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"
#include "circuits.inc"

using namespace std;

template <class Bit, class Uint>
vector<Bit> uint2bit(const vector<Uint> & vu)
{
    vector<Bit> vb;
    for ( int i = vu.size() - 1; i >= 0; i-- )
    {
        for ( int j = 0; j < Uint::size(); j++ )
        {
            auto copy = vu[i][j];
            vb.push_back(copy);
        }
    }
    return vb;
}

template <class Uint, class Bit>
vector<Uint> bit2uint(const vector<Bit> & vb)
{
    vector<Uint> vu;
    Uint u;
    for ( int i = vb.size() - 1; i >= 0; i-- )
    {
        auto j = i % Uint::size();
        u[j] = vb[i];
        if ( !j )
        {
            auto copy = u;
            vu.push_back(copy);
        }
    }
    return vu;
}

int main()
{
    // vector<SecureUint<8>> state =
    // {
    //     _0x39_E, _0x25_E, _0x84_E, _0x1D_E,
    //     _0x02_E, _0xDC_E, _0x09_E, _0xFB_E,
    //     _0xDC_E, _0x11_E, _0x85_E, _0x97_E,
    //     _0x19_E, _0x6A_E, _0x0B_E, _0x32_E
    // };

    vector<SecureUint<8>> state =
    {
        _0x32_E, _0x43_E, _0xf6_E, _0xa8_E,
        _0x88_E, _0x5a_E, _0x30_E, _0x8d_E,
        _0x31_E, _0x31_E, _0x98_E, _0xa2_E,
        _0xe0_E, _0x37_E, _0x07_E, _0x34_E
    };

    // vector<SecureUint<8>> key =
    // {
    //     _0x2B_E, _0x7E_E, _0x15_E, _0x16_E,
    //     _0x28_E, _0xAE_E, _0xD2_E, _0xA6_E,
    //     _0xAB_E, _0xF7_E, _0x15_E, _0x88_E,
    //     _0x09_E, _0xCF_E, _0x4F_E, _0x3C_E
    // };

    vector<SecureUint<8>> key =
    {
        _0x2b_E, _0x7e_E, _0x15_E, _0x16_E,
        _0x28_E, _0xae_E, _0xd2_E, _0xa6_E,
        _0xab_E, _0xf7_E, _0x15_E, _0x88_E,
        _0x09_E, _0xcf_E, _0x4f_E, _0x3c_E
    };

    vector<SecureUint<8>> output =
    {
        _0_E, _0_E, _0_E, _0_E,
        _0_E, _0_E, _0_E, _0_E,
        _0_E, _0_E, _0_E, _0_E,
        _0_E, _0_E, _0_E, _0_E,
    };

    vector<SecureBit> bitState = uint2bit<SecureBit, SecureUint<8>>(state );
    vector<SecureBit> bitKey   = uint2bit<SecureBit, SecureUint<8>>(key   );
    vector<SecureBit> bitOut   = uint2bit<SecureBit, SecureUint<8>>(output);

    // cout << bitState.size() << '\n';
    // cout <<   bitKey.size() << '\n';
    // cout <<   bitOut.size() << '\n';

    Timer t;
    aes(bitOut, bitState, bitKey);
    auto r = t.get();

    output.clear();
    output = bit2uint<SecureUint<8>, SecureBit>(bitOut);

    // for ( auto u : output ) cout << u << ' ';
    // cout << '\n';

    cout << "Runtime: " << r << " us\n";
    // vector<SecureUint<8>> st = { _0x19_E, _0x3d_E, _0xe3_E, _0xbe_E };
    // vector<SecureBit> stb = uint2bit<SecureBit, SecureUint<8>>(st);
    // vector<SecureBit> p0b,p1b,p2b,p3b;
    // p0b.resize(32);
    // p1b.resize(32);
    // p2b.resize(32);
    // p3b.resize(32);
    // table_lookup(p0b,p1b,p2b,p3b,stb);
    // vector<SecureUint<8>> p0,p1,p2,p3;
    // p0 = bit2uint<SecureUint<8>, SecureBit>(p0b);
    // for ( auto u : p0 ) cout << u << ' ';
    // cout << '\n';
    // p1 = bit2uint<SecureUint<8>, SecureBit>(p1b);
    // for ( auto u : p1 ) cout << u << ' ';
    // cout << '\n';
    // p2 = bit2uint<SecureUint<8>, SecureBit>(p2b);
    // for ( auto u : p2 ) cout << u << ' ';
    // cout << '\n';
    // p3 = bit2uint<SecureUint<8>, SecureBit>(p3b);
    // for ( auto u : p3 ) cout << u << ' ';
    // cout << '\n';

}
