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

        // <N> <N> <N>
        static void d_add   (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitand(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitor (std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
        static void d_bitxor(std::vector<Bit> & y, const std::vector<Bit> & a, const std::vector<Bit> & b) noexcept;
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

    public:
        static const char * name() { return "$Name"; }
        static const int size() { return SZ; };

        // Constructors
        $NameUint() { bits.resize(SZ); }
        $NameUint(const std::string & s): $NameUint() { load(s); }
        $NameUint(const char * c) : $NameUint(std::string(c)) {}

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
        $NameUint<SZ> operator++();
        $NameUint<SZ> operator++(int);
        $NameUint<SZ> operator--();
        $NameUint<SZ> operator--(int);

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

        $NameUint<SZ> mux(const $NameUint<SZ> & a, const $NameUint<SZ> & b) const;

        $NameUint<SZ> operator*(unsigned long long u) const;
        friend $NameUint<SZ> operator*(unsigned long long u, const $NameUint<SZ> & a) { return a * u; }

        // Functions
        std::string str() const;

    private:
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
        { return Bit::gate_mux(c, b, a); } // the operators are switched because the netlist is FTS, while our MUX is STF
};

template<int SZ> class $NameInt : public $NameUint<SZ>
{
        using base = $NameUint<SZ>;
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
        // Constructors
        $NameInt() {}
        $NameInt(const std::string & s): $NameUint<SZ>(s) {}
        $NameInt(const char * c): $NameUint<SZ>(c) {}

        $NameInt(const $NameUint<SZ> & y): $NameUint<SZ>(y) {}
        explicit $NameInt(const $NameBool & y): $NameUint<SZ>(y) {}

        // Casting
        template <int Z> explicit operator $NameInt<Z> () const;

        // Operators
        $NameInt<SZ> & operator/=(const $NameInt<SZ> & a);
        $NameInt<SZ> & operator%=(const $NameInt<SZ> & a);
        $NameInt<SZ> & operator>>=(const $NameInt<SZ> & a);
        $NameInt<SZ> operator/(const $NameInt<SZ> & a) const;
        $NameInt<SZ> operator%(const $NameInt<SZ> & a) const;
        $NameInt<SZ> operator>>(const $NameInt<SZ> & a) const;
        $NameBool operator<(const $NameInt<SZ> & a) const;
        $NameBool operator<=(const $NameInt<SZ> & a) const;
        $NameBool operator>(const $NameInt<SZ> & a) const;
        $NameBool operator>=(const $NameInt<SZ> & a) const;

        // Functions
};

class $NameBool : public $NameUint<1>
{
    public:
        // Constructors
        $NameBool() = default;
        template <int SZ> $NameBool(const $NameUint<SZ> &);
        $NameBool(const std::string & s): $NameUint<1>(s) {}
        $NameBool(const char * c) : $NameBool(std::string(c)) {}

        // Operators
        $NameBool & operator+=(const $NameBool & a);
        $NameBool & operator-=(const $NameBool & a);
        $NameBool & operator*=(const $NameBool & a);
        $NameBool & operator/=(const $NameBool & a);
        $NameBool & operator%=(const $NameBool & a);
        $NameBool operator+(const $NameBool & a) const;
        $NameBool operator-(const $NameBool & a) const;
        $NameBool operator*(const $NameBool & a) const;
        $NameBool operator/(const $NameBool & a) const;
        $NameBool operator%(const $NameBool & a) const;
        template <int SZ> $NameUint<SZ> operator*(const $NameUint<SZ> & x) const;

        template <int SZ>
        $NameUint<SZ> mux(const $NameUint<SZ> & x, const $NameUint<SZ> & y) const;
};

template <int SZ> std::ostream &
operator<<(std::ostream & os, const $NameUint<SZ> & x) { return os << x.str(); }
template <int SZ> std::ostream &
operator<<(std::ostream & os, const $NameInt<SZ> & x) { return os << x.str(); }

extern CircuitEvalKey * g_pek_$Name;

$PostfixDefines

// === END circuit.h Name=$Name
