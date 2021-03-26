#ifndef _E3_EKX_CIRC_SEAL_H_
#define _E3_EKX_CIRC_SEAL_H_

#include "ek_circ_seal.h"
#include "olc.h"

namespace e3
{

class CircuitEvalKey_seal_X : public CircuitEvalKey_seal_bfv
{
    public:
        CircuitEvalKey_seal_X(KeyName name) : CircuitEvalKey_seal_bfv(User::Alice, name) {}

        void save() { never("call to e3::CircuitEvalKey_seal_X::save"); }
        using CircuitEvalKey_seal_bfv::bek;
};

} // e3
#endif // _E3_EKX_CIRC_SEAL_H_
