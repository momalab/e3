// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN atop.inc

template <class T, class N>
void e3::initEvalKey(e3::KeyName name, T *& pek, T *& gpek)
{
    if ( !gpek )
    {
        try { gpek = new N(T::User::Bob, name); }
        catch (...)
        {
            std::cerr << "Cannot load evaluation key of ("
                      << name.typ << "," << name.fil << ")\n";
            throw;
        }
    }

    pek = gpek;
}

template <class T> T e3::multiply_by_ull(const T & x, unsigned long long u, const T * zero)
{
    if ( u == 0 ) return zero ? *zero : x - x;
    if ( u == 1 ) return x;

    T y(x); y <<= 1ull;
    auto q = u / 2;
    y = multiply_by_ull(y, q, zero);

    if ( u == 2 * q ) return y;
    return y + x;
}

template <class T> T e3::shiftL_by_ull(const T & x, unsigned long long u)
{
    T r = x;
    while (u--) r += r;
    return r;
}

template <class T, class U, class K>
void e3::init_by_ull(T & r, U & x, unsigned long long y,
                     const T & z, const T & u, const K * pek)
{
    std::string e = pek->encrypt(std::to_string(y), 0);
    if ( !e.empty() )
    {
        x = U( (pek->decor(e, false)) );
        return;
    }

    if ( !y )
    {
        r = z;
        return;
    }

    // this does not (must not) call indirectly this ctor
    r = e3::multiply_by_ull < T > (u, y);
}


// === END atop.inc

