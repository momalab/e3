// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <fstream>
#include <iostream>

#include "ek_circ_fhew.h"
#include "def_fhew1.h"

using std::cout;

bool e3::CircuitEvalKey_fhew::load()
{
    init_properties_fhew();

    if ( !NOCOUT ) cout << "Loading evaluation key .. " << std::flush;

    //bool r = load_oleg();
    bool r = load_fhew();

    if ( !NOCOUT ) cout << "ok\n";
    return r;
}

bool e3::CircuitEvalKey_fhew::load_fhew()
{
    FILE * fp = fopen(filename().c_str(), "r");
    key = FHEW::fread_ek(fp);
    fclose(fp);
    return true;
}

bool e3::CircuitEvalKey_fhew::load_oleg()
{
    std::ifstream in(filename(), std::ios::binary);
    if ( !in ) return false;

    static FHEW::EvalKey k;
    key = &k;

    // 1 check type sizes
    // 2 check constants
    // 3 load BSkey
    // 4 load KSkey
    // 5 check marker

    // utilities: read constant
    auto rdt = [&in](int cnst)
    {
        int i;
        in.read(reinterpret_cast<char *>(&i), sizeof(i));
        if ( i != cnst ) throw "File corrupted";
    };

    auto rdc = [&in]() -> char
    {
        char c;
        in.read(&c, 1);
        return c;
    };

    auto rdd = [&in]() -> double
    {
        double d;
        in.read(reinterpret_cast<char *>(&d), sizeof(d));
        return d;
    };

    auto rdq = [&in]() -> ZmodQ
    {
        ZmodQ q;
        in.read(reinterpret_cast<char *>(&q), sizeof(q));
        return q;
    };


    try
    {

        // 1 check type sizes
        char c;
        in.read(&c, 1); if ( c != (char)sizeof(int) ) throw "Bad int size";
        in.read(&c, 1); if ( c != (char)sizeof(double) ) throw "Bad double size";
        in.read(&c, 1); if ( c != (char)sizeof(ZmodQ) ) throw "Bad ZmodQ size";

        // 2 check constants
        rdt(n); rdt(BS_base); rdt(BS_exp);
        rdt(N); rdt(KS_base); rdt(KS_exp);
        rdt(K2); rdt(N2);

        // 3 load BSkey
        FHEW::EvalKey k;
        for ( int i1 = 0; i1 < n; i1++ )
            for ( int i2 = 0; i2 < BS_base; i2++ )
                for ( int i3 = 0; i3 < BS_exp; i3++ )
                {
                    using FHEW::ct_FFT;
                    ct_FFT *& c = k.BSkey[i1][i2][i3];
                    char c0 = rdc();
                    if ( c0 == '\0' ) { c = nullptr; continue; }
                    if ( c0 != '\1' ) { throw "Bad selector"; }
                    c = (ct_FFT *) fftw_malloc(sizeof(ct_FFT));
                    for ( int i4 = 0; i4 < K2; i4++ )
                        for ( int i5 = 0; i5 < 2; i5++ )
                            for ( int i6 = 0; i6 < N2; i6++ )
                                for ( int i7 = 0; i7 < 2; i7++ )
                                {
                                    double & fc = (*c)[i4][i5][i6][i7];
                                    fc = rdd();
                                }
                }

        // 4 load KSkey
        for ( int i1 = 0; i1 < N; i1++ )
            for ( int i2 = 0; i2 < KS_base; i2++ )
                for ( int i3 = 0; i3 < KS_exp; i3++ )
                {
                    LWE::CipherTextQ *& ct = k.KSkey[i1][i2][i3];
                    ct = new LWE::CipherTextQ;
                    for ( int i4 = 0; i4 < n; i4++ ) ct->a[i4] = rdq();
                    ct->b = rdq();
                }

        // 5 check marker
        char mrkr[5] = "abcd";
        in.read(mrkr, 4);
        char m1 = '1';
        for ( int i = 0; i < 4; i++ ) if ( mrkr[i] != m1++ ) throw "Bad marker";

    }
    /*catch (const char * e)
    {
        std::cout << "ERROR (while loading ev key): " << e << '\n';
        return false;
    }*/
    catch (...) { throw "Bad " + filename() + " eval key"; }
    return true;
}

std::string e3::CircuitEvalKey_fhew::filename() const { return EvalKey::filename(); }
