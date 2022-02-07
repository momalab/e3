// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.pail.h Name=$Name

/*
struct Cell
{
    e3::Bigun x, y;
    Cell(e3::Bigun a, const e3::PailEvalKey * p)
        : x(a), y(a.invmod(p->getN2())) {}
    Cell() {}
    Cell(std::string s, const e3::PailEvalKey * p)
        : Cell(e3::Bigun(s), p) {}
} xix;
*/

extern e3::PailEvalKey * g_pek_$Name;

class $Name
{
    protected:
        e3::Bigun x;

        static e3::PailEvalKey * pek;
        static const $Name * zero, * unit;

    public:
        static const bool is_signed = false;
        static const int size = 0;
        static const bool is_circuit = false;

        static const char * typname() { return "$Name"; }
        static const char * filname() { return "$Filencname"; }
        static const char * clsname() { return "$Clsencname"; }

        // Constructors
        void init0()
        {
            if ( !pek )
            {
                initEvalKey(e3::KeyName {typname(), filname()}, pek, g_pek_$Name);
                if ( !unit ) unit = new $Name("$ArithUnit");
                if ( !zero ) zero = new $Name("$ArithZero");
            }
        }

        template<typename T> T init(const T & s) { init0(); return s; }

        $Name() { init0(); }
        $Name(const std::string & s) : x(init(pek)->decor(init(s), false)) {}
        $Name(const char * c) : $Name(std::string(c)) {}
        $Name(e3::Bigun a) : x(init(a)) {}

        // start ring test requirements
        explicit $Name(unsigned long long); // public encryption
        $Name operator+() const { return *this; }
        // end ring test requirements

        // Operators
        $Name & operator+=(const $Name & a) { return *this = *this + a; }
        $Name & operator-=(const $Name & a) { return *this = *this - a; }
        $Name & operator++() { return *this += *unit; }
        $Name & operator--() { return *this -= *unit; }
        $Name operator++(int) { $Name r(*this); ++*this; return r; }
        $Name operator--(int) { $Name r(*this); --*this; return r; }

        $Name operator+(const $Name & a) const;
        $Name operator-(const $Name & a) const { return *this + (-a); }
        $Name operator-() const;

        $Name operator*(unsigned long long u) const { return e3::multiply_by_ull(*this, u); }
        friend $Name operator*(unsigned long long u, const $Name & a) { return a * u; }

        $Name operator+(unsigned long long u) const { return *this + (*unit * u); }
        friend $Name operator+(unsigned long long u, const $Name & a) { return a + u; }

        $Name operator-(unsigned long long u) const { return *this - (*unit * u); }
        friend $Name operator-(unsigned long long u, const $Name & a) { return a - u; }

        $Name & operator+=(unsigned long long u) { return *this = *this + u; }
        $Name & operator-=(unsigned long long u) { return *this = *this - u; }

        $Name operator<<(unsigned long long u) const { $Name t(*this); t <<= u; return t; }
        $Name & operator<<=(unsigned long long u) { return *this = e3::shiftL_by_ull(*this, u); }

        // Functions
        std::string str() const { return pek->decor(x.str(), true); }

        $Name & operator*=(const $Name & a) = delete;
        $Name operator*(const $Name & a) const = delete;
};

inline std::ostream & operator<<(std::ostream & os, const $Name & x) { return os << x.str(); }

$PostfixDefines

// === END  ring.pail.h Name=$Name
