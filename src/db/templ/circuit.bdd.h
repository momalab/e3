// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.bdd.h Name=$Name


class $NameBit : public $NameBaseBit
{
        static std::string vc2s(const std::vector<char> &);
        static void s2vc(const std::string &, std::vector<char> &);

    protected:

        //std::vector<bool> v;
        std::vector<char> vc;

    public:

        $NameBit() : $NameBaseBit(), vc($CtSize) {}
        $NameBit(const $NameBit & b) = default;

        $NameBit(const char * s): $NameBit(std::string(s)) {}
        $NameBit(const std::string & s);

        // access to SecureInt classes
        static e3::CircuitEvalKey_bddn * k() { return static_cast<e3::CircuitEvalKey_bddn *>(pek); }

        std::string str() const { return vc2s(vc); }

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

// === END circuit.bdd.h Name=$Name
