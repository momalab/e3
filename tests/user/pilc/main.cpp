#include <iostream>
#include <string>
#include <vector>

#include "e3int.h"
///#include "timer.h"

#include "../alice.h"

using namespace std;

enum Gate { NOT = 0, AND, OR, XOR, NAND, NOR, XNOR, MUX };
Gate gates[] = { NOT, AND, OR, XOR, NAND, NOR, XNOR, MUX };
string names[] = { "NOT...", "AND...", "OR....", "XOR...", "NAND..", "NOR...", "XNOR..", "MUX..." };

template<class U, class B>
void validateGates(U zero, U unit)
{
    const bool PR = false;
    ///U xs0;

    U s0 = zero, s1 = unit, s, pass, passt;
    vector<B> b = { s0[0], s1[0] }, bo;
    passt = s1;

    cout << dec(zero) << ' ' << dec(unit) << " NOT";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        s[0] = B::gate_not(b[i]);
        if (PR) cout << " - ~" << i << " = " << dec(s) << ' ' << flush;

        s[0] = i ? B::gate_not(s[0]) : s[0];
        pass[0] = B::gate_and(pass[0], s[0]);
    }
    cout << ": " << dec(pass) << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "AND";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            U zi = zero, zj = zero;
            zi[0] = b[i];
            zj[0] = b[j];
            s[0] = B::gate_and(b[i], b[j]);
            ///if (PR) cout << "(" << dec(zi) << ')' << flush;
            ///if (PR) cout << "(" << dec(zj) << ')' << flush;
            ///if (PR) cout << "(" << dec(zi) << "&" << dec(zj) << "=" << dec(s) << ')' << flush;
            if (PR) cout << " - " << i << '&' << j << " = " << dec(s) << ' ' << flush;

            s[0] = i & j ? s[0] : B::gate_not(s[0]);
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << dec(pass) << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "OR";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_or(b[i], b[j]);
            if (PR) cout << " - " << i << '|' << j << " = " << dec(s) << ' ' << flush;

            s[0] = i | j ? s[0] : B::gate_not(s[0]);
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << dec(pass) << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "XOR";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_xor(b[i], b[j]);
            if (PR) cout << " - " << i << '^' << j << " = " << dec(s) << ' ' << flush;

            s[0] = i ^ j ? s[0] : B::gate_not(s[0]);
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << dec(pass) << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "NAND";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_nand(b[i], b[j]);
            if (PR) cout << " - " << i << "!&" << j << " = " << dec(s) << ' ' << flush;

            s[0] = i & j ? B::gate_not(s[0]) : s[0];
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << dec(pass) << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "NOR";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_nor(b[i], b[j]);
            if (PR) cout << " - " << i << "!|" << j << " = " << dec(s) << ' ' << flush;

            s[0] = i | j ? B::gate_not(s[0]) : s[0];
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << dec(pass) << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "XNOR";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_xnor(b[i], b[j]);
            if (PR) cout << " - " << i << "!^" << j << " = " << dec(s) << ' ' << flush;

            s[0] = i ^ j ? B::gate_not(s[0]) : s[0];
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << dec(pass) << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);


    cout << "MUX";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            for ( size_t k = 0; k < b.size(); k++ )
            {
                s[0] = B::gate_mux(b[i], b[j], b[k]);
                if (PR) cout << " - " << i << '?' << j << ':' << k << " = " << dec(s) << ' ' << flush;

                s[0] = (i ? j : k) ? s[0] : B::gate_not(s[0]);
                pass[0] = B::gate_and(pass[0], s[0]);
            }
        }
    }
    cout << ": " << dec(pass) << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "ALL: " << dec(passt) << '\n';
}

int main(int ac, char * av[])
try
{
    cout << "N... "; validateGates<PilUint<1>, PilBit>(_0_En, _1_En);
}
catch (string e)
{
    cout << "Error: " << e << "\n";
}
catch (const char * e)
{
    cout << "Error: " << e << "\n";
}
catch (...)
{
    cout << "exception\n";
}
