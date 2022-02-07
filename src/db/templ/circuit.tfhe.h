// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.tfhe.h Name=$Name

class $NameBit : public $NameBaseBit
{
    protected:

        e3::TfheNativeBt nb;

        // this function may not needed since LweSample is always
        // initialized (see default Ctor of TfheNativeBt)
        static const LweSample * op(const std::shared_ptr<LweSample> & p)
        {
            if ( !p.get() ) throw "Operation on uninitialized bit in $Name";
            return p.get();
        }

    public:
        $NameBit() : $NameBaseBit(), nb(k()->native()) {}
        $NameBit(e3::TfheNativeBt ax) : $NameBaseBit(), nb(ax, k()->native()) {}
        $NameBit(const $NameBit & b): $NameBaseBit(), nb(b.nb, k()->native()) {}

        $NameBit(const std::string & s): $NameBaseBit(), nb(fs(s), k()->native()) {}
        $NameBit(const char * s): $NameBit(std::string(s)) {}
        std::string str() const { return nb.str(k()->native()); }

        static e3::CircuitEvalKey_tfhe * k() { return static_cast<e3::CircuitEvalKey_tfhe *>(pek); }

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

// === END circuit.tfhe.h Name=$Name
