// === BEGIN  ring.pila.cpp Name=$Name

e3::PilaEvalKey * g_pek_$Name = nullptr;
e3::PilaEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

// public encryption
$Name::$Name(unsigned long long z) : $Name()
{
    /*///
        std::string e = pek->encrypt(std::to_string(z), 0);
        if ( !e.empty() )
        {
            x = decltype(x)( (pek->decor(e, false)) );
            return;
        }

        if ( !z )
        {
            *this = *zero;
            return;
        }

        *this = *unit;

        // this does not (must not) call indirectly this ctor
        *this = e3::multiply_by_ull < $Name > (*this, z);
    */
    e3::init_by_ull < $Name, e3::PilQuad, e3::PilaEvalKey >
    (*this, x, z, *zero, *unit, pek);
}


$Name $Name::operator+(const $Name & a) const
{
    e3::PilArith pa(pek);
    $Name r;
    r.x = x + a.x;
    return r;
}

$Name $Name::operator-(const $Name & a) const
{
    e3::PilArith pa(pek);
    $Name r;
    r.x = x - a.x;
    return r;
}

$Name $Name::operator*(const $Name & a) const
{
    e3::PilArith pa(pek);
    $Name r;
    r.x = x * a.x;
    return r;
}


// === END  ring.pila.cpp Name=$Name
