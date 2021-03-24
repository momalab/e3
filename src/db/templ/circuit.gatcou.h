// === BEGIN circuit.gatcou.h Name=$Name

class $NameBit : public $NameBaseBit
{
    protected:
        bool x;

    public:
        $NameBit(bool ax = false) : x(ax) {}
        $NameBit(const std::string & s);
        $NameBit(const char * s): $NameBit(std::string(s)) {}

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

        explicit operator bool() const { return x; }
};

namespace e3
{

namespace gatcou
{

struct Gcounter
{
    unsigned long not_, and_, or_, nand_, nor_, xnor_, xor_, mux_;
    Gcounter() { not_ = and_ = or_ = nand_ = nor_ = xnor_ = xor_ = mux_ = 0; }
    unsigned long total() const { return not_ + and_ + or_ + nand_ + nor_ + xnor_ + xor_ + mux_; }
};

struct GcStat
{
    Gcounter ops, gates;
    bool gates_on = true;

    void not_() { ++ops.not_; if (gates_on) ++gates.not_; }
    void and_() { ++ops.and_; if (gates_on) ++gates.and_; }
    void nand_() { ++ops.nand_; if (gates_on) ++gates.nand_; }
    void or_() { ++ops.or_; if (gates_on) ++gates.or_; }
    void xor_() { ++ops.xor_; if (gates_on) ++gates.xor_; }
    void xnor_() { ++ops.xnor_; if (gates_on) ++gates.xnor_; }
    void mux_() { ++ops.mux_; if (gates_on) ++gates.mux_; }
    void nor_() { ++ops.nor_; if (gates_on) ++gates.nor_; }
};

extern GcStat gc_stat;

// this object saves the current state set by 'void gates(bool z)'
struct Saver { bool a; Saver() { a = gc_stat.gates_on; } ~Saver() { gc_stat.gates_on = a; } };

inline void reset() { gc_stat.ops = gc_stat.gates = Gcounter(); }
inline void gates(bool z, const Saver & s) { gc_stat.gates_on = (z && s.a); }
inline GcStat get() { return gc_stat; }

void print(int w = 7);
std::string sum(int t = 3);


} // gatcou

} // e3

extern e3::gatcou::GcStat gc_stat;

// === END circuit.gatcou.h Name=$Name
