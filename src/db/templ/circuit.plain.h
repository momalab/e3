// === BEGIN circuit.Plain.h Name=$Name

class $NameBit
{
    protected:
        e3util::usi x;
        static CircuitEvalKey * pek;

        static void init_pek();
        static const char * name() { return "$Name"; }

    public:
        static const $NameBit * zero;
        $NameBit(e3util::usi ax = 0) : x(ax) { init_pek(); }
        $NameBit(const std::string & s);

        // access to SecureInt classes
        static CircuitEvalKey_plain * k() { return static_cast<CircuitEvalKey_plain *>(pek); }

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

// === END circuit.Plain.h Name=$Name
