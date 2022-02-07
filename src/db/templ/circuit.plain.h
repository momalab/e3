// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.plain.h Name=$Name

class $NameBit : public $NameBaseBit
{
    protected:
        e3::util::usi x;

    public:
        $NameBit(e3::util::usi ax = 0) : x(ax) {}
        $NameBit(const std::string & s);

        // access to SecureInt classes
        static e3::CircuitEvalKey_plain * k() { return static_cast<e3::CircuitEvalKey_plain *>(pek); }

        std::string str() const { return std::to_string(x); }

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

// === END circuit.plain.h Name=$Name
