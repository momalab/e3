#include "e3int.h"

/*
    It is not possible to print SecureBit directly.
    Therefore, we create wrapper functions to convert the result
    of the gate functions from SecureBit to SecureBool,
    which is printable.
*/

SecureBool gate_not (const SecureBit & a);
SecureBool gate_and (const SecureBit & a, const SecureBit & b);
SecureBool gate_or  (const SecureBit & a, const SecureBit & b);
SecureBool gate_xor (const SecureBit & a, const SecureBit & b);
SecureBool gate_nand(const SecureBit & a, const SecureBit & b);
SecureBool gate_nor (const SecureBit & a, const SecureBit & b);
SecureBool gate_xnor(const SecureBit & a, const SecureBit & b);
SecureBool gate_mux (const SecureBit & a, const SecureBit & b, const SecureBit & c); //a?b:c;
