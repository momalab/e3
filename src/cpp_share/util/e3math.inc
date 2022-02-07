// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include "def_mpir.h"


template <class T>
void e3::math::Meuclid<T>::checkRec(
    const Rec & v0, const Rec & v,
    const Rec & vb, T et, T ft)
{
    T x = add( mul(v0.a, v.e) , mul(v0.b, v.f) );
    T y = add( mul(vb.a, et) , mul(vb.b, ft) );

    if ( x != y )
        throw "Error: [pej+qfj!=aet+bft] " + x.str() + ":" + y.str();
}


template <class T>
void e3::math::Meuclid<T>::fillAB(T x, T y)
{
    if (x < y) x.swap(y);
    v.clear();
    Rec r;
    r.a = x;
    r.b = y;
    v.push_back(r);

    size_t i = 0;
    if ( v[i].b != 0 )
        while ( 1 )
        {
            //v[i].c = v[i].a%v[i].b;
            //v[i].d = v[i].a/v[i].b;
            T::divABRQ(v[i].a, v[i].b, &v[i].c, &v[i].d);
            if ( v[i].c == 0 ) break;
            v.push_back(Rec()); i++;

            v[i].a = v[i - 1].b;
            v[i].b = v[i - 1].c;
        }
}

template <class T>
void e3::math::Meuclid<T>::fillEF()
{
    int n = int(v.size()) - 1;

    for ( int i = n; i >= 0; i-- )
    {
        v[i].e = et;
        v[i].f = ft;
        for ( int j = i - 1; j >= 0; j-- )
        {
            v[j].e = v[size_t(j) + 1].f;
            v[j].f = sub( v[size_t(j) + 1].e, mul( v[j].d, v[j].e ) );
        }

        v[i].e = v[0].e;
        v[i].f = v[0].f;
    }
}

template <class T>
string e3::math::Meuclid<T>::str() const
{
    string r;
    for ( int i = 0; i < (int)v.size(); i++ )
    {
        r += v[i].a.str() + ' ' + v[i].b.str() + ' ' + v[i].c.str()
             + ' ' + v[i].d.str() + ' ' + v[i].e.str() + ' '
             + v[i].f.str() + ' ' + v[i].g.str() + '\n';
    }
    return r;
}

template <class T>
void e3::math::Meuclid<T>::fillG()
{
    int n = int(v.size()) - 1;

    for ( int i = n; i >= 0; i-- )
    {
        checkRec(v[0], v[i], v[i], et, ft);

        v[i].g = add( add( mul(v[i].a, et), mul(v[i].b, ft) ), mul(v[i].e, v[i].f) );

        if (0)if ( v[i].g < 0 )
            {
                T y = add( v[i].e, v[0].b );
                if ( y > 0 )
                {
                    //T x = (-v[i].g)/y + 1;
                    T x = add( divq( (neg(v[i].g)), y) , 1 );
                    //v[i].f += x;
                    v[i].f.addMod(x, mod);
                    v[i].g = add( add( mul(v[0].a, v[i].e),
                                       mul(v[0].b, v[i].f) ), mul(v[i].e, v[i].f) );
                }
            }

        if ( v[i].g > 0 )
        {
            if ( gsmall == 0  || gsmall > v[i].g ) gsmall = v[i].g;
        }
    }
}

template<typename T> bool e3::math::invert(const T & x, const T & mod, T * xm1)
{
    using UC = UnumberContractor<T>;

    UC ucx(x);
    UC ucmod(mod);

    Invertor<UC> iuc(ucx, ucmod);

    if ( !iuc.isOk() ) return false;

    if (xm1) *xm1 = iuc.get().x;

    return true;
}

