// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.palisade.ckks.h Name=$Name

extern e3::PalisadeCkksEvalKey * g_pek_$Name;

class $Name
{
    private:
        struct Init { Init() { init0(); } } io = Init();
        template<typename T> T init(const T & s) { init0(); return s; }

        template<class T> $Name add(const $Name &, const T &) const;
        template<class T> $Name sub(const $Name &, const T &) const;
        template<class T> $Name mul(const $Name &, const T &) const;

    protected:
        e3::PalisadeCkksNativeCiphertext x;

        static e3::PalisadeCkksEvalKey * pek;
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
        $Name(e3::PalisadeCkksNativeCiphertext a) : x(a) {}
        $Name(const $Name & a) : io(), x(a.x) {}
        $Name(const std::string & s) : x( pek->decor(s, false), pek ) {}

        explicit $Name(int a)    : $Name( init(pek)->encrypt( std::to_string(a), 0 ) ) {}
        explicit $Name(double a) : $Name( init(pek)->encrypt( std::to_string(a), 0 ) ) {}
        explicit $Name(const std::complex<double> & a) : $Name( init(pek)->encrypt( e3::util::to_string(a), 0 ) ) {}
        explicit $Name(const std::vector<int> & a)
            : $Name( init(pek)->encrypt(
                         e3::util::merge( e3::util::extend(a, slots(), 0), "_" ), 0
                     ) ) {}
        explicit $Name(const std::vector<double> & a)
            : $Name( init(pek)->encrypt(
                         e3::util::merge( e3::util::extend(a, slots(), double(0)), "_" ), 0
                     ) ) {}
        explicit $Name(const std::vector<std::complex<double>> & a)
            : $Name( init(pek)->encrypt(
                         e3::util::merge( e3::util::extend(a, slots(), std::complex<double>(0, 0)), "_" ), 0
                     ) ) {}

        // Ciphertext operators
        $Name & operator=(const $Name & a) { $Name r(a); x = r.x; return *this; }
        $Name & operator+=(const $Name & a) { return *this = *this + a; }
        $Name & operator-=(const $Name & a) { return *this = *this - a; }
        $Name & operator*=(const $Name & a) { return *this = *this * a; }
        $Name operator+(const $Name & a) const { return add(*this, a.x); }
        $Name operator-(const $Name & a) const { return sub(*this, a.x); }
        $Name operator*(const $Name & a) const { return mul(*this, a.x); }
        $Name operator+() const { return *this; }
        $Name operator-() const { return *zero - *this; }

        $Name & rotate(int s) { return *this = $Name::rotate(*this, s); }
        static $Name rotate(const $Name & a, int s);
        std::vector < $Name > rotate(const std::vector<int> & vs) { return $Name::rotate(*this, vs); }
        static std::vector < $Name > rotate(const $Name & a, const std::vector<int> & vs);

        // Ciphertext-Plaintext operators
        $Name & operator+=(int a) { return *this = *this + a; }
        $Name & operator+=(double a) { return *this = *this + a; }
        $Name & operator+=(const std::complex<double> & a) { return *this = *this + a; }
        $Name & operator+=(const std::vector<int> & a) { return *this = *this + a; }
        $Name & operator+=(const std::vector<double> & a) { return *this = *this + a; }
        $Name & operator+=(const std::vector<std::complex<double>> & a) { return *this = *this + a; }

        $Name & operator-=(int a) { return *this = *this - a; }
        $Name & operator-=(double a) { return *this = *this - a; }
        $Name & operator-=(const std::complex<double> & a) { return *this = *this - a; }
        $Name & operator-=(const std::vector<int> & a) { return *this = *this - a; }
        $Name & operator-=(const std::vector<double> & a) { return *this = *this - a; }
        $Name & operator-=(const std::vector<std::complex<double>> & a) { return *this = *this - a; }

        $Name & operator*=(int a) { return *this = *this * a; }
        $Name & operator*=(double a) { return *this = *this * a; }
        $Name & operator*=(const std::complex<double> & a) { return *this = *this * a; }
        $Name & operator*=(const std::vector<int> & a) { return *this = *this * a; }
        $Name & operator*=(const std::vector<double> & a) { return *this = *this * a; }
        $Name & operator*=(const std::vector<std::complex<double>> & a) { return *this = *this * a; }

        $Name operator+(int a) const { return add(*this, a); }
        $Name operator+(double a) const { return add(*this, a); }
        $Name operator+(const std::complex<double> & a) const { return add(*this, a); }
        $Name operator+(const std::vector<int> & a) const { return add(*this, a); }
        $Name operator+(const std::vector<double> & a) const { return add(*this, a); }
        $Name operator+(const std::vector<std::complex<double>> & a) const { return add(*this, a); }

        $Name operator-(int a) const { return sub(*this, a); }
        $Name operator-(double a) const { return sub(*this, a); }
        $Name operator-(const std::complex<double> & a) const { return sub(*this, a); }
        $Name operator-(const std::vector<int> & a) const { return sub(*this, a); }
        $Name operator-(const std::vector<double> & a) const { return sub(*this, a); }
        $Name operator-(const std::vector<std::complex<double>> & a) const { return sub(*this, a); }

        $Name operator*(int a) const { return mul(*this, a); }
        $Name operator*(double a) const { return mul(*this, a); }
        $Name operator*(const std::complex<double> & a) const { return mul(*this, a); }
        $Name operator*(const std::vector<int> & a) const { return mul(*this, a); }
        $Name operator*(const std::vector<double> & a) const { return mul(*this, a); }
        $Name operator*(const std::vector<std::complex<double>> & a) const { return mul(*this, a); }

        friend $Name operator+(int i, const $Name & a) { return a + i; };
        friend $Name operator+(double d, const $Name & a) { return a + d; }
        friend $Name operator+(const std::complex<double> & v, const $Name & a) { return a + v; }
        friend $Name operator+(const std::vector<int> & v, const $Name & a) { return a + v; }
        friend $Name operator+(const std::vector<double> & v, const $Name & a) { return a + v; }
        friend $Name operator+(const std::vector<std::complex<double>> & v, const $Name & a) { return a + v; }

        friend $Name operator-(int i, const $Name & a) { return -a + i; };
        friend $Name operator-(double d, const $Name & a) { return -a + d; }
        friend $Name operator-(const std::complex<double> & v, const $Name & a) { return -a + v; }
        friend $Name operator-(const std::vector<int> & v, const $Name & a) { return -a + v; }
        friend $Name operator-(const std::vector<double> & v, const $Name & a) { return -a + v; }
        friend $Name operator-(const std::vector<std::complex<double>> & v, const $Name & a) { return -a + v; }

        friend $Name operator*(int i, const $Name & a) { return a * i; };
        friend $Name operator*(double d, const $Name & a) { return a * d; }
        friend $Name operator*(const std::complex<double> & v, const $Name & a) { return a * v; }
        friend $Name operator*(const std::vector<int> & v, const $Name & a) { return a * v; }
        friend $Name operator*(const std::vector<double> & v, const $Name & a) { return a * v; }
        friend $Name operator*(const std::vector<std::complex<double>> & v, const $Name & a) { return a * v; }

        // Functions
        std::string str() const { return pek->decor(x.str(), true); }
        static size_t slots() { init0(); return pek->slots(); }
};

inline std::ostream & operator<<(std::ostream & os, const $Name & x) { return os << x.str(); }

$PostfixDefines

// === END  ring.palisade.ckks.h Name=$Name
