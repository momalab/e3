// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.pailg.h Name=$Name

// === INCLUDE arith.pail.h Name=$Name
@ring.pail.h
// === END INCLUDE arith.pail.h Name=$Name

class $NameBool;

class $NameUint : public $Name
{
    private:
        static const int baud = $Cophee_baudRate; // Cophee::baudRate
        static const bool ardu = $Cophee_isUsingArduino; // Cophee::isUsingArduino
        e3::cophee::Cophee cophee;

    protected:
        $NameUint G_d2(bool forceTable) const;

    public:
        $NameUint() : $Name(), cophee(baud, ardu) {}
        $NameUint(const std::string & s) : $Name(s), cophee(baud, ardu) {}
        $NameUint(const char * c) : $Name(c), cophee(baud, ardu) {}
        $NameUint(e3::Bigun a) : $Name(a), cophee(baud, ardu) {}
        $NameUint(const $Name & a) : $Name(a), cophee(baud, ardu) {}

        // start ring test requirements
        explicit $NameUint(unsigned long long); // public encryption
        explicit $NameUint(int a) : $NameUint((unsigned long long) a) {}
        $Name operator+() const { return *this; }
        // end ring test requirements

        // Operators
        $NameUint & operator+=(const $NameUint & a) { return *this = *this + a; }
        $NameUint & operator-=(const $NameUint & a) { return *this = *this - a; }
        $NameUint & operator++() { return *this += *unit; }
        $NameUint & operator--() { return *this -= *unit; }
        $NameUint operator++(int) { $NameUint r(*this); ++*this; return r; }
        $NameUint operator--(int) { $NameUint r(*this); --*this; return r; }

        $NameUint operator+(const $NameUint & a) const { return this->$Name::operator+(a); }
        $NameUint operator-() const { return this->$Name::operator-(); }

        $NameUint operator-(const $NameUint & a) const { return *this + (-a); }

        $NameUint operator*(unsigned long long u) const { return e3::multiply_by_ull(*this, u); }
        friend $NameUint operator*(unsigned long long u, const $NameUint & a) { return a * u; }

        $NameUint operator+(unsigned long long u) const { return *this + (*unit * u); }
        friend $NameUint operator+(unsigned long long u, const $NameUint & a) { return a + u; }

        $NameUint operator-(unsigned long long u) const { return *this - (*unit * u); }
        friend $NameUint operator-(unsigned long long u, const $NameUint & a) { return a - u; }

        friend $NameUint operator*(const $Name & n, const $NameUint & a) { return a * n; }
        friend $NameUint operator+(const $Name & n, const $NameUint & a) { return a + n; }
        friend $NameUint operator-(const $Name & n, const $NameUint & a) { return $NameUint(n) - a; }

        $NameUint & operator+=(unsigned long long u) { return *this = *this + u; }
        $NameUint & operator-=(unsigned long long u) { return *this = *this - u; }

        $NameBool operator==(const $NameUint & a) const;
        $NameBool operator<(const $NameUint & a) const;

        $NameBool operator>(const $NameUint & a) const;
        $NameBool operator!=(const $NameUint & a) const;
        $NameBool operator<=(const $NameUint & a) const;
        $NameBool operator>=(const $NameUint & a) const;

        $Name operator<<(unsigned long long u) const { $Name t(*this); t <<= u; return t; }
        $Name & operator<<=(unsigned long long u) { return *this = e3::shiftL_by_ull(*this, u); }


        // Functions

        static int beta(int b = 0);
        $NameUint G(const $NameUint & a) const;
        $NameUint & operator*=(const $NameUint & a) { return *this = *this * a; }
        $NameUint operator*($NameUint a) const;
        static std::string showProcessor() { return pek->show(); }
        $NameUint operator*($NameBool a) const;

        static $NameUint get1() { return *$Name::unit; }
        static $NameUint get0() { return *$Name::zero; }
};

inline std::ostream & operator<<(std::ostream & os, const $NameUint & x) { return os << x.str(); }


class $NameBool
{
    public:
        $NameBool operator!() const;
};

inline $NameBool $NameUint::operator>(const $NameUint & a) const { return a < *this; }
inline $NameBool $NameUint::operator!=(const $NameUint & a) const { return !(a == *this); }
inline $NameBool $NameUint::operator<=(const $NameUint & a) const { return !(a < *this); }
inline $NameBool $NameUint::operator>=(const $NameUint & a) const { return !(a > *this); }
inline $NameUint operator*(const $NameBool & u, const $NameUint & a) { return a * u; }

// === END  ring.pailg.h Name=$Name
