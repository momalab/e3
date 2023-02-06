// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.h Name=$Name
class $NameBool;

template<int SZ> class $NameUint
{
        template <int Z> friend class $NameUint;
        template <int Z> friend class $NameInt;
        friend class $NameBool;

    protected:
        using Bit = $NameBit;

        std::vector<Bit> bits;

        // ATTENTION 'y' must be different to 'a' and 'b'! No checks are done

        // <1> <N>
        static void d_lognot (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redand (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_rednand(std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_rednor (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redor  (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redxnor(std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_redxor (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;

        // <1> <N> <N>
        static void d_eq    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ge    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gesig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gt    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_gtsig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ineq  (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_le    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_lesig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_logand(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_logor (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_lt    (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_ltsig (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <1> <N>
        static void d_boolmul(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <1> <N> <N>
        static void d_boolmux(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b, const std::vector<Bit> & c) noexcept;

        // <N> <N>
        static void d_bitnot   (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_dec      (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_uminus   (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;
        static void d_inc      (std::vector<Bit> & y, const std::vector<Bit> & a) noexcept;

        // <N> <N> 1
        static void d_bitsum   (std::vector<Bit> & y, const std::vector<Bit> & a, const Bit & zero) noexcept;

        // <N> <N> <N>
        static void d_add   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitand(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitor (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitxor(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_carryadd(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_div   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_divsig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_mod   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_modsig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_mul   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_sll   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_slr   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_srasig(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_sub   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        // static void d_xnor(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;

        // <N> <N> <N> <N>
        static void d_intmux(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b, const std::vector<Bit> & c) noexcept;

        void load(const std::string & s);

        void shiftLR(int n, int lr); // shift left-0, right-1

    public:
        static const bool is_signed = false;
        static const int size = SZ;
        static const bool is_circuit = true;

        static const char * typname() { return $NameBit::typname(); }
        static const char * filname() { return $NameBit::filname(); }
        static const char * clsname() { return $NameBit::clsname(); }

        // Constructors
        $NameUint() { bits.resize(SZ); }
        $NameUint(const std::string & s): $NameUint() { load(s); }
        $NameUint(const char * c) : $NameUint(std::string(c)) {}

        // public encryption
        // explicit $NameUint(bool a) : $NameUint( (unsigned long long)(a) ) {}
        // explicit $NameUint(int  a) : $NameUint( (unsigned long long)(a) ) {}
        explicit $NameUint(unsigned long long);
        explicit $NameUint(const std::vector<unsigned long long> &);

        // Casting
        template <int Z> explicit operator $NameUint<Z> () const;
        explicit operator $NameBool () const;

        // Operators
        $NameUint<SZ> & operator+=(const $NameUint<SZ> & a);
        $NameUint<SZ> & operator-=(const $NameUint<SZ> & a);
        $NameUint<SZ> & operator*=(const $NameUint<SZ> & a);
        $NameUint<SZ> & operator/=(const $NameUint<SZ> & a);
        $NameUint<SZ> & operator%=(const $NameUint<SZ> & a);
        $NameUint<SZ> & operator&=(const $NameUint<SZ> & a);
        $NameUint<SZ> & operator|=(const $NameUint<SZ> & a);
        $NameUint<SZ> & operator^=(const $NameUint<SZ> & a);
        $NameUint<SZ> & operator<<=(const $NameUint<SZ> & a);
        $NameUint<SZ> & operator>>=(const $NameUint<SZ> & a);
        $NameUint<SZ> & operator++();
        $NameUint<SZ> & operator--();
        $NameUint<SZ> operator++(int);
        $NameUint<SZ> operator--(int);

        $NameUint<SZ> operator+() const { return *this; }
        $NameUint<SZ> operator-() const { return ++~(*this); }

        $NameUint<SZ> operator+(const $NameUint<SZ> & a) const;
        $NameUint<SZ> operator-(const $NameUint<SZ> & a) const;
        $NameUint<SZ> operator*(const $NameUint<SZ> & a) const;
        $NameUint<SZ> operator/(const $NameUint<SZ> & a) const;
        $NameUint<SZ> operator%(const $NameUint<SZ> & a) const;
        $NameUint<SZ> operator&(const $NameUint<SZ> & a) const;
        $NameUint<SZ> operator|(const $NameUint<SZ> & a) const;
        $NameUint<SZ> operator^(const $NameUint<SZ> & a) const;
        $NameUint<SZ> operator<<(const $NameUint<SZ> & a) const;
        $NameUint<SZ> operator>>(const $NameUint<SZ> & a) const;
        $NameUint<SZ> operator*(const $NameBool & a) const;
        $NameUint<SZ> operator~() const;
        $NameBool operator!() const;
        $NameBool operator==(const $NameUint<SZ> & a) const;
        $NameBool operator!=(const $NameUint<SZ> & a) const;
        $NameBool operator<(const $NameUint<SZ> & a) const;
        $NameBool operator<=(const $NameUint<SZ> & a) const;
        $NameBool operator>(const $NameUint<SZ> & a) const;
        $NameBool operator>=(const $NameUint<SZ> & a) const;
        $NameBool operator&&(const $NameUint<SZ> & a) const;
        $NameBool operator||(const $NameUint<SZ> & a) const;

        Bit operator[](int i) const { return bits[i]; }
        Bit & operator[](int i) { return bits[i]; }
        $NameUint<SZ> bitsum() const;

        $NameUint<SZ> mux(const $NameUint<SZ> & a, const $NameUint<SZ> & b) const;

        $NameUint<SZ> operator*(unsigned long long u) const;
        friend $NameUint<SZ>
        operator*(unsigned long long u, const $NameUint<SZ> & a)
        { return a * u; }

        template <class T> $NameUint<SZ> operator<<(T u) const
        { $NameUint<SZ> r(*this); return r <<= u; }

        template <class T> $NameUint<SZ> operator>>(T u) const
        { $NameUint<SZ> r(*this); return r >>= u; }

        template <class T> $NameUint<SZ> & operator<<=(T u)
        { int k = static_cast<int>(u); shiftLR(k, 0); return *this; }

        template <class T> $NameUint<SZ> & operator>>=(T u)
        { int k = static_cast<int>(u); shiftLR(k, 1); return *this; }

        // Functions
        $NameUint<SZ> & rotate_columns();
        $NameUint<SZ> & rotate_rows(int s);

        static $NameUint<SZ> rotate_columns(const $NameUint<SZ> & a) { $NameUint<SZ> r(a); return r.rotate_columns(); }
        static $NameUint<SZ> rotate_rows(const $NameUint<SZ> & a, int s) { $NameUint<SZ> r(a); return r.rotate_rows(s); }

        std::string str() const;
        static size_t slots() { return $NameBit::k()->slots(); }

    protected:
        // Gates
        static Bit gate_buf(const Bit & a) { return Bit::gate_buf(a); }
        static Bit gate_not(const Bit & a) { return Bit::gate_not(a); }
        static Bit gate_and(const Bit & a, const Bit & b) { return Bit::gate_and(a, b); }
        static Bit gate_or(const Bit & a, const Bit & b) { return Bit::gate_or(a, b); }
        static Bit gate_nand(const Bit & a, const Bit & b) { return Bit::gate_nand(a, b); }
        static Bit gate_nor(const Bit & a, const Bit & b) { return Bit::gate_nor(a, b); }
        static Bit gate_xnor(const Bit & a, const Bit & b) { return Bit::gate_xnor(a, b); }
        static Bit gate_xor(const Bit & a, const Bit & b) { return Bit::gate_xor(a, b); }

        static Bit gate_mux(const Bit & a, const Bit & b, const Bit & c)
        { return Bit::gate_mux(c, b, a); }
        // the operators are switched because the netlist is FTS, while our MUX is STF
};

template<int SZ> class $NameInt : public $NameUint<SZ>
{
        using base = $NameUint<SZ>;
        friend class $NameBool;
        signed long long sll() const { return base::x; }

    protected:
        using $NameUint<SZ>::bits;
        using $NameUint<SZ>::d_divsig;
        using $NameUint<SZ>::d_modsig;
        using $NameUint<SZ>::d_srasig;
        using $NameUint<SZ>::d_gesig;
        using $NameUint<SZ>::d_gtsig;
        using $NameUint<SZ>::d_lesig;
        using $NameUint<SZ>::d_ltsig;

    public:
        static const bool is_signed = true;

        // Constructors
        $NameInt() {}
        $NameInt(const std::string & s): $NameUint<SZ>(s) {}
        $NameInt(const char * c): $NameUint<SZ>(c) {}

        $NameInt(const $NameUint<SZ> & y): $NameUint<SZ>(y) {}
        explicit $NameInt(const $NameBool & y): $NameUint<SZ>(y) {}
        explicit $NameInt(bool a) : $NameInt( (long long)(a) ) {}
        explicit $NameInt(int  a) : $NameInt( (long long)(a) ) {}
        explicit $NameInt(long long x) : $NameUint<SZ>(x) {}
        explicit $NameInt(const std::vector<long long> & x)
            : $NameUint<SZ>( std::vector<unsigned long long>(x.begin(), x.end()) ) {}

        // Casting
        template <int Z> explicit operator $NameInt<Z> () const;

        // Operators
        $NameInt<SZ> & operator/=(const $NameInt<SZ> & a);
        $NameInt<SZ> & operator%=(const $NameInt<SZ> & a);
        $NameInt<SZ> & operator>>=(const $NameInt<SZ> & a);

        $NameInt<SZ> operator>>(const $NameInt<SZ> & a) const;
        $NameInt<SZ> operator<<(const $NameInt<SZ> & a) const;
        $NameInt<SZ> operator+(const $NameInt<SZ> & a) const;
        $NameInt<SZ> operator-(const $NameInt<SZ> & a) const;
        $NameInt<SZ> operator*(const $NameInt<SZ> & a) const;
        $NameInt<SZ> operator/(const $NameInt<SZ> & a) const;
        $NameInt<SZ> operator%(const $NameInt<SZ> & a) const;

        $NameBool operator<(const $NameInt<SZ> & a) const;
        $NameBool operator<=(const $NameInt<SZ> & a) const;
        $NameBool operator>(const $NameInt<SZ> & a) const;
        $NameBool operator>=(const $NameInt<SZ> & a) const;

        $NameInt<SZ> operator*(const $NameBool & a) const;

        template <class T> $NameInt<SZ> operator<<(T u) const
        { $NameInt<SZ> r(*this); return r <<= u; }

        template <class T> $NameInt<SZ> operator>>(T u) const
        { $NameInt<SZ> r(*this); return r >>= u; }

        template <class T> $NameInt<SZ> & operator<<=(T u)
        { int k = int(u); $NameUint<SZ>::shiftLR(k, 0); return *this; }

        template <class T> $NameInt<SZ> & operator>>=(T u)
        { int k = int(u); $NameUint<SZ>::shiftLR(k, 1); return *this; }

        // Functions
};


class $NameBool : public $NameUint<1>
{
    public:
        // Constructors
        $NameBool() = default;
        template <int SZ> explicit $NameBool(const $NameUint<SZ> &);
        explicit $NameBool(const std::string & s): $NameUint<1>(s) {}
        explicit $NameBool(const char * c) : $NameBool(std::string(c)) {}
        // explicit $NameBool(bool x) : $NameUint<1>(x) {}
        explicit $NameBool(const std::vector<bool> & x) : $NameUint<1>( std::vector<unsigned long long>(x.begin(), x.end()) ) {}
        explicit $NameBool(const std::vector<unsigned long long> & x) : $NameUint<1>(x) {}
        explicit $NameBool(Bit x) { (*this)[0] = x; }
        // explicit $NameBool(int x) : $NameUint<1>(x) {}

        $NameBool(const $NameBool &) = default;
        $NameBool & operator=(const $NameBool & x) = default;

        Bit bit() const { return (*this)[0]; }
        Bit & bit() { return (*this)[0]; }

        // Operators
        $NameBool & operator+=(const $NameBool & a);
        $NameBool & operator-=(const $NameBool & a);
        $NameBool & operator*=(const $NameBool & a);
        $NameBool & operator/=(const $NameBool & a);
        $NameBool & operator%=(const $NameBool & a);
        $NameBool & operator&=(const $NameBool & a);
        $NameBool & operator^=(const $NameBool & a);
        $NameBool & operator|=(const $NameBool & a);
        $NameBool operator+(const $NameBool & a) const;
        $NameBool operator-(const $NameBool & a) const;
        $NameBool operator*(const $NameBool & a) const;
        $NameBool operator/(const $NameBool & a) const;
        $NameBool operator%(const $NameBool & a) const;
        $NameBool operator&(const $NameBool & a) const;
        $NameBool operator|(const $NameBool & a) const;
        $NameBool operator^(const $NameBool & a) const;
        template <int SZ> $NameUint<SZ> operator*(const $NameUint<SZ> & x) const;
        template <int SZ> $NameInt<SZ> operator*(const $NameInt<SZ> & x) const;

        template <int SZ>
        $NameUint<SZ> mux(const $NameUint<SZ> & x, const $NameUint<SZ> & y) const;

        $NameBool g_buf() const { return $NameBool {gate_buf(bit())}; }
        $NameBool g_not() const { return $NameBool {gate_not(bit())}; }
        $NameBool g_xor(const $NameBool & b) const { return $NameBool {gate_xor(bit(), b[0])}; }
        $NameBool g_and(const $NameBool & b) const { return $NameBool {gate_and(bit(), b[0])}; }
        $NameBool g_or (const $NameBool & b) const { return $NameBool {gate_or (bit(), b[0])}; }
        $NameBool g_nand(const $NameBool & b) const { return $NameBool {gate_nand(bit(), b[0])}; }
        $NameBool g_xnor(const $NameBool & b) const { return $NameBool {gate_xnor(bit(), b[0])}; }
        $NameBool g_nor(const $NameBool & b) const { return $NameBool {gate_nor(bit(), b[0])}; }

        // this is unusual order because the generated circuits are using
        // order cba, therefore gate_mux is in that weird form
        $NameBool g_mux(const $NameBool & b, const $NameBool & c) const
        { return $NameBool {gate_mux(c[0], b[0], bit())}; }

};

template <int SZ> std::ostream &
operator<<(std::ostream & os, const $NameUint<SZ> & x) { return os << x.str(); }
template <int SZ> std::ostream &
operator<<(std::ostream & os, const $NameInt<SZ> & x) { return os << x.str(); }

namespace e3
{

template <int SZ>
inline $NameUint<SZ> mux(const $NameBool & b,
                         const $NameUint<SZ> & x, const $NameUint<SZ> & y)
{
    return b.mux(x, y);
}

template <int SZ>
inline $NameInt<SZ> mux(const $NameBool & b,
                        const $NameInt<SZ> & x, const $NameInt<SZ> & y)
{
    return $NameInt<SZ>(b.mux(x, y));
}

} // e3

extern e3::CircuitEvalKey * g_pek_$Name;

$PostfixDefines

// === END circuit.h Name=$Name
