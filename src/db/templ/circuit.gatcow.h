// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.gatcow.h Name=$Name

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
namespace gatcow
{
const int gNOT = 0, gAND = 1, gOR = 2, gNAND = 3, gNOR = 4, gXNOR = 5, gXOR = 6, gMUX = 7;
const int NGateTypes = gMUX + 1;
extern const char * const gateNames [NGateTypes];

struct Gcounter
{
    ///unsigned long not_, and_, or_, nand_, nor_, xnor_, xor_, mux_;
    unsigned long x[NGateTypes];
    Gcounter() { for ( auto & i : x ) i = 0; }
    unsigned long total() const
    {
        unsigned long r = 0;
        for ( auto i : x ) r += i;
        return r;
    }

    void operator+=(const Gcounter & c)
    { for (int i = 0; i < NGateTypes; i++) x[i] += c.x[i]; }
    void operator-=(const Gcounter & c)
    { for (int i = 0; i < NGateTypes; i++) x[i] -= c.x[i]; }

    bool operator==(const Gcounter & c) const
    {
        for (int i = 0; i < NGateTypes; i++)
            if ( x[i] != c.x[i]) return false;
        return true;
    }
    bool operator!=(const Gcounter & c) const { return !(*this == c); }

    Gcounter operator*(int b) const
    {
        Gcounter r;
        for (int i = 0; i < NGateTypes; i++) r.x[i] = b * x[i];
        return r;
    }

    inline bool canSubtract(const Gcounter & c) const
    {
        for (int i = 0; i < NGateTypes; i++)
            if ( x[i] < c.x[i] ) return false;
        return true;
    }
};

///enum class PathBlockType { Seq, Par };
///using PBT = PathBlockType;
const int SEQ = 0, PAR = 1;

struct Triplet { Gcounter ops, gts, crs; };
inline bool operator==(const Triplet & a, const Triplet & b)
{
    return a.ops == b.ops && a.gts == b.gts && a.crs == b.crs;
}
inline bool operator!=(const Triplet & a, const Triplet & b) { return !(a == b); }
inline void operator+=(Triplet & a, const Triplet & b)
{
    a.ops += b.ops; a.gts += b.gts; a.crs += b.crs;
}


struct Share;

struct PathBlock
{
        PathBlock * parent;
        Triplet tri;
        int pathBlockType;

        bool merged = false; // this is to prevent ~PathBlock call on ~Share

        static bool berr;
        static std::string err;
        static void seterr(std::string e) { berr = true; err = e; errsig(); }
        void swap_stack();

        // real estate
        struct RE { bool anon; Gcounter ng; int howmany; }; // net gates
        std::map<std::string, RE> re;

        struct ParData
        {
            Triplet shadow;
            Gcounter maxcrit;
        } pardata;

        void gate(int i) { ++tri.ops.x[i]; ++tri.gts.x[i]; ++tri.crs.x[i]; }
        PathBlock(int pathBlockType = SEQ);
        PathBlock(std::string cfgname);
        ~PathBlock();

        void merge();
        void debug(std::string name);

        PathBlock(const PathBlock &) = delete;
        void operator=(const PathBlock &) = delete;


        static void isvalid();
        void print(int w = 7);
        std::string sum(unsigned long coeff = 1, std::string delim = " ");

    private:
        friend struct Share;
        void join_share(const Share & s);
        void join_pb(const PathBlock & pb);
        void grab_real_estate(const PathBlock & pb);
        void grab_real_estate(std::string nm, const RE & ar);
        static void errsig();
        Gcounter net_gts() const;
};

struct Share : PathBlock
{
    std::string name;
    bool anon; // remove from RE after usage - not to clutter

    Share(std::string unique_name, bool anonymous = false); //use HERE macro
    ~Share();

    void debug();
};

std::string summary(Triplet tri, unsigned long coeff = 1, std::string delim = " ");


extern PathBlock g_rootPathBlock;
extern PathBlock * g_curPathBlock;


} // gatcow

} // e3

extern const char * const e3::gatcow::gateNames [e3::gatcow::NGateTypes];
extern e3::gatcow::PathBlock e3::gatcow::g_rootPathBlock;
extern e3::gatcow::PathBlock * e3::gatcow::g_curPathBlock;

#ifdef GC_USE_MACROS

#define GC_CONCAT(a,b) a##b
#define GC_CONCT(a,b) GC_CONCAT(gc_dummy_##a,b)

#define GC_HERE (std::string(__func__)+":"+std::to_string(__LINE__))
#define GC_share e3::gatcow::Share GC_CONCT(sh_,__LINE__)(GC_HERE,true)
#define GC_path(i) e3::gatcow::Share GC_CONCT(pt_,__LINE__)(GC_HERE+":"+std::to_string(i),true)
#define GC_PAR e3::gatcow::PathBlock GC_CONCT(pa_,__LINE__)(e3::gatcow::PAR)
#define GC_SEQ e3::gatcow::PathBlock GC_CONCT(se_,__LINE__)(e3::gatcow::SEQ)
#define GC_block e3::gatcow::PathBlock
#define GC_valid e3::gatcow::PathBlock::isvalid()
#define GC_func e3::gatcow::PathBlock gc_dummy_fu(__func__)
#endif



// === END circuit.gatcow.h Name=$Name
