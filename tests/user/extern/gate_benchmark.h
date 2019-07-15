/*
#include <iostream>
#include <string>
#include <vector>

#include "e3int.h"
#include "timer.h"
*/

using namespace std;

enum Gate { NOT = 0, AND, OR, XOR, NAND, NOR, XNOR, MUX };
Gate gates[] = { NOT, AND, OR, XOR, NAND, NOR, XNOR, MUX };
//string gate_names[] = { "NOT...", "AND...", "OR....", "XOR...", "NAND..", "NOR...", "XNOR..", "MUX..." };
string gate_names[] = { "not", "and", "or", "xor", "nand", "nor", "xnor", "mux" };

template<class Bit> inline void cycle_not (Bit & a0, Bit & a1, Bit & b0, Bit & b1)
{
    Bit t = a0;
    a0 = Bit::gate_not(b1);
    b1 = Bit::gate_not(b0);
    b0 = Bit::gate_not(a1);
    a1 = Bit::gate_not(t);
}
template<class Bit> inline void cycle_and (Bit & a0, Bit & a1, Bit & b0, Bit & b1)
{
    a1 = Bit::gate_and(a1, b1);
    b1 = Bit::gate_and(b1, a1);
    a0 = Bit::gate_and(b0, a1);
    b0 = Bit::gate_and(a0, b0);
}
template<class Bit> inline void cycle_or  (Bit & a0, Bit & a1, Bit & b0, Bit & b1)
{
    a0 = Bit::gate_or(a0, b0);
    b0 = Bit::gate_or(b0, a0);
    a1 = Bit::gate_or(b1, a0);
    b1 = Bit::gate_or(a1, b1);
}
template<class Bit> inline void cycle_xor (Bit & a0, Bit & a1, Bit & b0, Bit & b1)
{
    a0 = Bit::gate_xor(a0, b0);
    b0 = Bit::gate_xor(b1, a1);
    a1 = Bit::gate_xor(a0, b1);
    b1 = Bit::gate_xor(a1, b0);
}
template<class Bit> inline void cycle_nand(Bit & a0, Bit & a1, Bit & b0, Bit & b1)
{
    a0 = Bit::gate_nand(a1, b1);
    a1 = Bit::gate_nand(a0, b1); // (b0, a0);
    b1 = Bit::gate_nand(b0, a1);
    b0 = Bit::gate_nand(b1, a1);
}
template<class Bit> inline void cycle_nor (Bit & a0, Bit & a1, Bit & b0, Bit & b1)
{
    a1 = Bit::gate_nor(a0, b0);
    a0 = Bit::gate_nor(b0, a1);
    b0 = Bit::gate_nor(a1, a0); // was a1 b1
    b1 = Bit::gate_nor(a0, b0);
}
template<class Bit> inline void cycle_xnor(Bit & a0, Bit & a1, Bit & b0, Bit & b1)
{
    a0 = Bit::gate_xnor(b0, b1);
    b0 = Bit::gate_xnor(b1, a0);
    a1 = Bit::gate_xnor(a0, b0);
    b1 = Bit::gate_xnor(a1, b1);
}
template<class Bit> inline void cycle_mux (Bit & a0, Bit & a1, Bit & b0, Bit & b1)
{
    a0 = Bit::gate_mux(a0, b1, b0);
    a1 = Bit::gate_mux(b1, a1, a0);
    b0 = Bit::gate_mux(a1, a0, b1);
    b1 = Bit::gate_mux(b0, a0, a1);
}

template<class Bit>
double test(Gate g, const Bit & zero, const Bit & one, unsigned time)
{
    Bit a0, a1, b0, b1;
    a0 = b0 = zero;
    a1 = b1 = one;
    unsigned long long elapsed;
    unsigned cycleSize = 4, counter = 0;
    Timer t;
    while ( (elapsed = t.get()) < time )
    {
        switch (g)
        {
            case NOT : cycle_not (a0, a1, b0, b1); break;
            case AND : cycle_and (a0, a1, b0, b1); break;
            case OR  : cycle_or  (a0, a1, b0, b1); break;
            case XOR : cycle_xor (a0, a1, b0, b1); break;
            case NAND: cycle_nand(a0, a1, b0, b1); break;
            case NOR : cycle_nor (a0, a1, b0, b1); break;
            case XNOR: cycle_xnor(a0, a1, b0, b1); break;
            case MUX : cycle_mux (a0, a1, b0, b1);
        }
        counter++;
    }
    return double(elapsed) / counter / cycleSize;
}

template<class U, class B>
void validateGates(U zero, U unit)
{
    const bool PR = false;
    ///U xs0;

    U s0 = zero, s1 = unit, s, pass, passt;
    vector<B> b = { s0[0], s1[0] }, bo;
    passt = s1;

    cout << zero << ' ' << unit << " NOT";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        s[0] = B::gate_not(b[i]);
        if (PR) cout << " - ~" << i << " = " << s << ' ' << flush;

        s[0] = i ? B::gate_not(s[0]) : s[0];
        pass[0] = B::gate_and(pass[0], s[0]);
    }
    cout << ": " << pass << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "AND";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_and(b[i], b[j]);
            if (PR) cout << " - " << i << '&' << j << " = " << s << ' ' << flush;

            s[0] = i & j ? s[0] : B::gate_not(s[0]);
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << pass << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "OR";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_or(b[i], b[j]);
            if (PR) cout << " - " << i << '|' << j << " = " << s << ' ' << flush;

            s[0] = i | j ? s[0] : B::gate_not(s[0]);
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << pass << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "XOR";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_xor(b[i], b[j]);
            if (PR) cout << " - " << i << '^' << j << " = " << s << ' ' << flush;

            s[0] = i ^ j ? s[0] : B::gate_not(s[0]);
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << pass << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "NAND";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_nand(b[i], b[j]);
            if (PR) cout << " - " << i << "!&" << j << " = " << s << ' ' << flush;

            s[0] = i & j ? B::gate_not(s[0]) : s[0];
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << pass << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "NOR";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_nor(b[i], b[j]);
            if (PR) cout << " - " << i << "!|" << j << " = " << s << ' ' << flush;

            s[0] = i | j ? B::gate_not(s[0]) : s[0];
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << pass << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "XNOR";
    pass = s1;
    for ( size_t i = 0; i < b.size(); i++ )
    {
        for ( size_t j = 0; j < b.size(); j++ )
        {
            s[0] = B::gate_xnor(b[i], b[j]);
            if (PR) cout << " - " << i << "!^" << j << " = " << s << ' ' << flush;

            s[0] = i ^ j ? B::gate_not(s[0]) : s[0];
            pass[0] = B::gate_and(pass[0], s[0]);
        }
    }
    cout << ": " << pass << ' ' << std::flush;
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
                if (PR) cout << " - " << i << '?' << j << ':' << k << " = " << s << ' ' << flush;

                s[0] = (i ? j : k) ? s[0] : B::gate_not(s[0]);
                pass[0] = B::gate_and(pass[0], s[0]);
            }
        }
    }
    cout << ": " << pass << ' ' << std::flush;
    passt[0] = B::gate_and(passt[0], pass[0]);

    cout << "ALL: " << passt << '\n';
}

/*
int main(int ac, char * av[])
try
{
    unsigned tim = 0; // ms
    if ( ac > 1 ) tim = std::stoi(av[1]);

    if (tim)
    {

        cout << "\nbddN\n";
        {
            BNUint<2> t = _2_En;
            for ( auto g : gates )
                cout << names[g] << " " << test<BNBit>( g, t[0], t[1], tim ) << '\n';
        }

        cout << "\nbddA\n";
        {
            BAUint<2> t = _2_Ea;
            for ( auto g : gates )
                cout << names[g] << " " << test<BABit>( g, t[0], t[1], tim ) << '\n';
        }

        cout << "\nbddAZ\n";
        {
            BZUint<2> t = _2_Ez;
            for ( auto g : gates )
                cout << names[g] << " " << test<BZBit>( g, t[0], t[1], tim ) << '\n';
        }

        cout << "\nbddF\n";
        {
            BFUint<2> t = _2_Ef;
            for ( auto g : gates )
                cout << names[g] << " " << test<BFBit>( g, t[0], t[1], tim ) << '\n';
        }

        cout << "\nbddFM\n";
        {
            BMUint<2> t = _2_Em;
            for ( auto g : gates )
                cout << names[g] << " " << test<BMBit>( g, t[0], t[1], tim ) << '\n';
        }


        cout << "\n";
    }

    cout << "N... "; validateGates<BNUint<1>, BNBit>(_0_En, _1_En);
    cout << "A... "; validateGates<BAUint<1>, BABit>(_0_Ea, _1_Ea);
    cout << "AZ.. "; validateGates<BZUint<1>, BZBit>(_0_Ez, _1_Ez);
    cout << "F... "; validateGates<BFUint<1>, BFBit>(_0_Ef, _1_Ef);
    cout << "FM.. "; validateGates<BMUint<1>, BMBit>(_0_Em, _1_Em);
}
catch (string e)
{
    cout << "Error: " << e << "\n";
}
catch (...)
{
    cout << "exception\n";
}
*/
