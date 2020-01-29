// === BEGIN  ring.pila.cpp Name=$Name

e3::PilaEvalKey * g_pek_$Name = nullptr;
e3::PilaEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

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
