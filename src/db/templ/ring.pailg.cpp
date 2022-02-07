// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.pailg.cpp Name=$Name

@ring.pail.cpp

// ATTENTION: This implementation of $Name is not thread safe
// To make it thread safe, do mutex stuff around static vars

$NameUint::$NameUint(unsigned long long z) : $NameUint()
{
    e3::init_by_ull < $NameUint, e3::Bigun, e3::PailEvalKey >
    (*this, x, z, *zero, *unit, pek);
}

$NameUint $NameUint::operator*($NameUint y) const
{
    $NameUint u = *this;
    $NameUint sum = *zero;
    auto beta1 = pek->getBeta() + 1;
    for ( int i = 0; i < beta1; i++ )
    {
        $NameUint z = u.G_d2(false);
        $NameUint b = u - (z + z);
        sum += b.G(y);
        y += y;
        u = z;
    }

    return sum;
}

$NameUint $NameUint::G_d2(bool recalc) const
{
    static $NameUint p20 {pek->getB2()};
    static std::vector < $NameUint > d2table;

    auto beta = pek->getBeta();

    if ( d2table.empty() || recalc )
    {
        $NameUint p2 = *unit;
        int b1 = beta - 1;

        d2table.resize(beta);
        for ( int i = 0; i < beta; i++ )
        {
            d2table[b1 - i] = p2;
            p2 += p2;
        }
    }

    $NameUint p2;
    $NameUint sum = *zero;

    for ( int i = 0; i < beta; i++ )
    {
        $NameUint pk;
        p2 = d2table[i];

        $NameUint y = sum + p2;
        y += y;
        y -= x;
        sum += (get1() - y).G(p2);
    }

    return sum;
}

$NameUint $NameUint::G(const $NameUint & a) const
{
    auto version = e3::mpir_impl();
    if ( (version == 2) || (version == 3) ) // cophee
    {
        if ( !cophee.is_params_set() )
        {
            std::cout << "INITIALIZATION\n";
            static e3::Bigun phph1 {"$Pailgfkf"};
            auto fkf = phph1.data();
            auto n = e3::Bigun(pek->getN()).data();
            auto n2 = e3::Bigun(pek->getN2()).data();
            cophee.set_params(n, n2, fkf);
        }
        auto x_arr = x.data();
        auto y_arr = a.x.data();
        std::cout << "GFUN .. " << std::flush;
        auto r_arr = cophee.gfunc(x_arr, y_arr);
        std::cout << "ok\n";
        $NameUint r;
        r.x.data(r_arr);
        return r;
    }
    else
    {
        static e3::Bigun phph1 {"$Pailgfkf"};

        const e3::Bigun & N2 = pek->getN2();
        auto y = x.powmod(phph1, N2); // 1+Nm
        auto b = pek->leq(y);

        static e3::Bigun rzN = get1().x.powmod(pek->getN(), N2);
        rzN = rzN.mulmod(rzN, N2);

        if ( b ) return rzN;
        return rzN.mulmod(a.x, N2);
    }
    throw "Wrong MPIR implementation";
}

int $NameUint::beta(int b)
{
    if ( b )
    {
        pek->setBeta(b);
        get0().G_d2(true); // recalc table
    }

    return pek->getBeta();
}


// === END  ring.pailg.cpp Name=$Name
