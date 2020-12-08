// === BEGIN circuit.seal.h Name=$Name

class $NameBit : public $NameBaseBit
{
    protected:

        e3::SealNativeCiphertext nb;

        static const SealCiphertext * op(const std::shared_ptr<SealCiphertext> & p)
        {
            if ( !p.get() ) throw "Operation on uninitialized bit in $Name";
            return p.get();
        }

    public:
        $NameBit() : $NameBaseBit(), nb() {}
        $NameBit(e3::SealNativeCiphertext ax) : $NameBaseBit(), nb(ax) {}
        $NameBit(const $NameBit & b): $NameBaseBit(), nb(b.nb) {}
        // NameBit(e3::SealNativeCiphertext ax) : $NameBaseBit(), nb(ax, k()->native()) {}
        // $NameBit(const $NameBit & b): $NameBaseBit(), nb(b.nb, k()->native()) {}
        $NameBit(const std::string & s): $NameBaseBit(), nb(fs(s), k()->native()) {}
        $NameBit(const char * s): $NameBit(std::string(s)) {}

        e3::SealNativeCiphertext native() const { return nb; }

        $NameBit & rotate_columns();
        $NameBit & rotate_rows(size_t s);
        std::string str() const { return nb.str(); }

        static e3::CircuitEvalKey_seal * k() { return static_cast<e3::CircuitEvalKey_seal *>(pek); }

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

// === END circuit.seal.h Name=$Name
