// === BEGIN atop.inc

template <class T, class N>
void initEvalKey(e3::KeyName name, T *& pek, T *& gpek)
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

template <class T> T multiply_by_ull(unsigned long long u, const T & x)
{
    if ( u == 0 ) return x - x;
    if ( u == 1 ) return x;

    T y = x + x;
    auto q = u / 2;
    y = multiply_by_ull(q, y);

    if ( u == 2 * q ) return y;
    return y + x;
}

// === END atop.inc
