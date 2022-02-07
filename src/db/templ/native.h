// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN native.h Name=$Name
class $NameBool;

template<int SZ> class $NameUint
{
        template <int Z> friend class $NameUint;
        template <int Z> friend class $NameInt;
        friend class $NameBool;

    protected:
        e3::util::ull x;
        static e3::NativeEvalKey * pek;

    public:
        static const bool is_signed = false;
        static const int size = SZ;
        static const bool is_circuit = false;

        static const char * typname() { return "$Name"; }
        static const char * filname() { return "$Filencname"; }
        static const char * clsname() { return "$Clsencname"; }

        // Constructors
        $NameUint();
        $NameUint(const std::string &);
        $NameUint(const char * c) : $NameUint(std::string(c)) {}

        explicit $NameUint(unsigned long long); // public encryption

        // Casting
        template <int Z> explicit operator $NameUint<Z> () const;
        explicit operator $NameBool () const;
        //operator bool() const; // forbid in template // need to remove because of ambiguity on Int*Enc

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


        $NameUint<SZ> operator+() const { return *this; }
        $NameUint<SZ> operator-() const { return $NameUint(0ull - x); }

        template <class T> $NameUint<SZ> operator<<(T u) const
        { $NameUint<SZ> r(*this); return r <<= u; }

        template <class T> $NameUint<SZ> operator>>(T u) const
        { $NameUint<SZ> r(*this); return r >>= u; }

        template <class T> $NameUint<SZ> & operator<<=(T u)
        { int k = static_cast<int>(u); x <<= k; return *this; }

        template <class T> $NameUint<SZ> & operator>>=(T u)
        { int k = static_cast<int>(u); x >>= k; return *this; }


        $NameUint<SZ> mux(const $NameUint<SZ> & a, const $NameUint<SZ> & b) const;

        $NameUint<SZ> operator*(unsigned long long u) const;
        friend $NameUint<SZ> operator*(unsigned long long u, const $NameUint<SZ> & a) { return a * u; }

        // Functions
        std::string str() const;

        $NameUint<SZ> & operator<<=(e3::util::ull a) { return *this <<= $NameUint<SZ>(a); }
        $NameUint<SZ> & operator>>=(e3::util::ull a) { return *this >>= $NameUint<SZ>(a); }
};

template<int SZ> class $NameInt : public $NameUint<SZ>
{
        using base = $NameUint<SZ>;
        signed long long sll() const { return base::x; }

    protected:
        using $NameUint<SZ>::pek;
        using $NameUint<SZ>::x;

    public:
        static const bool is_signed = true;

        // Constructors
        $NameInt() {}
        $NameInt(const std::string & s): $NameUint<SZ>(s) {}
        $NameInt(const char * c): $NameUint<SZ>(c) {}
        $NameInt(const $NameUint<SZ> & y): $NameUint<SZ>(y) {}
        explicit $NameInt(long long x) : $NameUint<SZ>(x) {}

        explicit $NameInt(const $NameBool & y): $NameUint<SZ>(y) {}

        // Casting
        template <int Z> explicit operator $NameInt<Z> () const;

        // Operators
        $NameInt<SZ> & operator/=(const $NameInt<SZ> & a);
        $NameInt<SZ> & operator%=(const $NameInt<SZ> & a);
        $NameInt<SZ> operator/(const $NameInt<SZ> & a) const;
        $NameInt<SZ> operator%(const $NameInt<SZ> & a) const;

        $NameInt<SZ> & operator>>=(const $NameInt<SZ> & a);
        $NameInt<SZ> operator>>(const $NameInt<SZ> & a) const;

        $NameInt<SZ> & operator<<=(const $NameInt<SZ> & a)
        { $NameUint<SZ>::operator<<=($NameUint<SZ>(a)); return *this; }

        $NameInt<SZ> operator<<(const $NameInt<SZ> & a) const { auto r = *this; r <<= a; return r; }

        $NameBool operator<(const $NameInt<SZ> & a) const;
        $NameBool operator<=(const $NameInt<SZ> & a) const;
        $NameBool operator>(const $NameInt<SZ> & a) const;
        $NameBool operator>=(const $NameInt<SZ> & a) const;

        $NameInt<SZ> operator+(const $NameInt<SZ> & a) const { auto r = *this; r += a; return r; }
        $NameInt<SZ> operator-(const $NameInt<SZ> & a) const { auto r = *this; r -= a; return r; }


        $NameInt<SZ> operator+() const { return *this; }
        $NameInt<SZ> operator-() const { return $NameInt<SZ>(0ll) - *this; }

        template <class T> $NameInt<SZ> operator<<(T u) const
        { $NameInt<SZ> r(*this); return r <<= u; }

        template <class T> $NameInt<SZ> operator>>(T u) const
        { $NameInt<SZ> r(*this); return r >>= u; }

        template <class T> $NameInt<SZ> & operator<<=(T u)
        { $NameUint<SZ>::operator<<=(u); return *this; }
        template <class T> $NameInt<SZ> & operator>>=(T u)
        { $NameUint<SZ>::operator>>=(u); return *this; }

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

template <int SZ> std::ostream & operator<<(std::ostream & os, const $NameUint<SZ> & x);
template <int SZ> std::ostream & operator<<(std::ostream & os, const $NameInt<SZ> & x);

extern e3::NativeEvalKey * g_pek_$Name;

$PostfixDefines

// === END native.h Name=$Name
