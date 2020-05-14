#include "gate_functions.h"

// This functions simply call the SecureBit gate function and convert the result to SecureBool

SecureBool gate_not(const SecureBit & a)
{
    SecureBool r;
    r[0] = SecureBit::gate_not(a);
    return r;
}

SecureBool gate_and(const SecureBit & a, const SecureBit & b)
{
    SecureBool r;
    r[0] = SecureBit::gate_and(a, b);
    return r;
}

SecureBool gate_or(const SecureBit & a, const SecureBit & b)
{
    SecureBool r;
    r[0] = SecureBit::gate_or(a, b);
    return r;
}

SecureBool gate_xor(const SecureBit & a, const SecureBit & b)
{
    SecureBool r;
    r[0] = SecureBit::gate_xor(a, b);
    return r;
}

SecureBool gate_nand(const SecureBit & a, const SecureBit & b)
{
    SecureBool r;
    r[0] = SecureBit::gate_nand(a, b);
    return r;
}

SecureBool gate_nor(const SecureBit & a, const SecureBit & b)
{
    SecureBool r;
    r[0] = SecureBit::gate_nor(a, b);
    return r;
}

SecureBool gate_xnor(const SecureBit & a, const SecureBit & b)
{
    SecureBool r;
    r[0] = SecureBit::gate_xnor(a, b);
    return r;
}

SecureBool gate_mux(const SecureBit & a, const SecureBit & b, const SecureBit & c)
{
    SecureBool r;
    r[0] = SecureBit::gate_mux(a, b, c);
    return r;
}
