// === BEGIN circuit.heli.h Name=$Name

#include "def_heli.h"

class $NameBit
{
    protected:
        struct PekInitializer
        {
            PekInitializer( void(*f)() ) { f(); }
        } pekInitializer;

        HeliNativeBit nb;
        static CircuitEvalKey * pek;

        static void init_pek();
        static const char * name() { return "$Name"; }

        // this function may not needed (??? see tfhe)
        static const HeliCtxt * op(const std::shared_ptr<HeliCtxt> & p)
        {
            if ( !p.get() ) throw "Operation on uninitialized bit in $Name";
            return p.get();
        }

    public:
        static const $NameBit * zero;

        $NameBit() : pekInitializer(init_pek), nb(k()->native()) {}
        $NameBit(HeliNativeBit ax) : pekInitializer(init_pek), nb(ax, k()->native()) {}
        $NameBit(const $NameBit & b): pekInitializer(init_pek), nb(b.nb, k()->native()) {}

        $NameBit(const std::string & s): pekInitializer(init_pek), nb(s, k()->native()) {}
        $NameBit(const char * s): $NameBit(std::string(s)) {}
        std::string str() const { return nb.str(k()->native()); }

        static CircuitEvalKey_heli * k() { return static_cast<CircuitEvalKey_heli *>(pek); }

        static $NameBit gate_buf(const $NameBit & a);
        static $NameBit gate_not(const $NameBit & a);
        static $NameBit gate_and(const $NameBit & a, const $NameBit & b);
        static $NameBit gate_or(const $NameBit & a, const $NameBit & b);
        static $NameBit gate_nand(const $NameBit & a, const $NameBit & b);
        static $NameBit gate_nor(const $NameBit & a, const $NameBit & b);
        static $NameBit gate_xnor(const $NameBit & a, const $NameBit & b);
        static $NameBit gate_xor(const $NameBit & a, const $NameBit & b);
        static $NameBit gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c);
};

// === END circuit.heli.h Name=$Name
