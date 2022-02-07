// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.pilc.h Name=$Name

class $NameBit : public $NameBaseBit
{
    protected:
        e3::PilQuad x;

    public:

        $NameBit() : $NameBaseBit() {}
        $NameBit(const $NameBit & b) = default;

        $NameBit(const char * s): $NameBit(std::string(s)) {}
        $NameBit(const std::string & s): $NameBaseBit(), x(fs(s)) {}
        e3::PilQuad native() const { return x; }

        static e3::CircuitEvalKey_pilc * k()
        { return static_cast<e3::CircuitEvalKey_pilc *>(pek); }
        static e3::PilBaseEvalKey * kb() { return &k()->bek; }

        std::string str() const { return x.str(); }

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

// === END circuit.pilc.h Name=$Name
