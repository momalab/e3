// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.seal_ckks.h Name=$Name

extern e3::SealCkksEvalKey * g_pek_$Name;

class $Name
{
        struct Init { Init() { init0(); } } init_object;
        template<typename T> T init(const T & s) { init0(); return s; }

    protected:
        e3::SealCkksNativeCiphertext x;

        static e3::SealCkksEvalKey * pek;
        static const $Name * zero, * unit;

    public:
        static const bool is_signed = false;
        static const int size = 0;
        static const bool is_circuit = false;

        static const char * typname() { return "$Name"; }
        static const char * filname() { return "$Filencname"; }
        static const char * clsname() { return "$Clsencname"; }

        // Constructors
        static void init0()
        {
            if ( !pek )
            {
                initEvalKey(e3::KeyName {typname(), filname()}, pek, g_pek_$Name);
                if ( !unit ) unit = new $Name("$ArithUnit");
                if ( !zero ) zero = new $Name("$ArithZero");
            }
        }

        $Name(): x() {}
        $Name(const char * c) : $Name(std::string(c)) {}
        $Name(e3::SealCkksNativeCiphertext a) : x(a) {}
        $Name(const $Name & a) : x(a.x) {}
        $Name(const std::string & s) : x( pek->decor(s, false), pek->key ) {}

        // public encryption
        explicit $Name(int a) : $Name( (unsigned long long)(a) ) {}
        explicit $Name(unsigned long long a) : $Name( init(pek)->encrypt( std::to_string(a), 0 ) ) {}
        explicit $Name(double             a) : $Name( init(pek)->encrypt( std::to_string(a), 0 ) ) {}
        explicit $Name(const std::vector<unsigned long long> & a) : $Name( init(pek)->encrypt( e3::util::merge(a, "_"), 0 ) ) {}
        explicit $Name(const std::vector<double>       &       a) : $Name( init(pek)->encrypt( e3::util::merge(a, "_"), 0 ) ) {}

        // Operators
        $Name & operator=(const $Name & a) { $Name r(a); x = r.x; return *this; }
        $Name & operator+=(const $Name & a);
        $Name & operator-=(const $Name & a);
        $Name & operator*=(const $Name & a);
        $Name operator+(const $Name & a) const;
        $Name operator-(const $Name & a) const;
        $Name operator*(const $Name & a) const;
        $Name & operator++() { return *this += *unit; }
        $Name & operator--() { return *this -= *unit; }
        $Name operator++(int) { $Name r(*this); ++*this; return r; }
        $Name operator--(int) { $Name r(*this); --*this; return r; }
        $Name operator+() const { return *this; }
        $Name operator-() const { return *zero - *this; }

        $Name operator*(unsigned long long u) const { return e3::multiply_by_ull(*this, u, zero); }
        friend $Name operator*(unsigned long long u, const $Name & a) { return a * u; }
        // $Name & operator++() { return *this += *unit; }
        // $Name & operator--() { return *this -= *unit; }
        // $Name operator++(int) { $Name r(*this); ++*this; return r; }
        // $Name operator--(int) { $Name r(*this); --*this; return r; }

        // $Name operator+(const $Name & a) const;
        // $Name operator-(const $Name & a) const; // { return *this + (-a); }
        // $Name operator-() const;

        // $Name operator*(unsigned long long u) const { return multiply_by_ull(u, *this); }
        // friend $Name operator*(unsigned long long u, const $Name & a) { return a * u; }
        //
        // $Name operator+(unsigned long long u) const { return *this + (*unit * u); }
        // friend $Name operator+(unsigned long long u, const $Name & a) { return a + u; }
        //
        // $Name operator-(unsigned long long u) const { return *this - (*unit * u); }
        // friend $Name operator-(unsigned long long u, const $Name & a) { return a - u; }

        $Name operator<<(unsigned long long u) const { $Name t(*this); t <<= u; return t; }
        $Name & operator<<=(unsigned long long u) { return *this = e3::shiftL_by_ull(*this, u); }

        // Functions
        std::string str() const { return pek->decor(x.str(), true); }

        // $Name & operator*=(const $Name & a) = delete;
        // $Name operator*(const $Name & a) const = delete;

        static size_t slots() { init0(); return pek->slots(); }
};

inline std::ostream & operator<<(std::ostream & os, const $Name & x) { return os << x.str(); }

$PostfixDefines

// === END  ring.seal_ckks.h Name=$Name
