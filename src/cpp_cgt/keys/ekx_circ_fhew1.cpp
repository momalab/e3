// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

#include "ekx_circ_fhew.h"
#include "def_fhew1.h"

using std::cout;

void e3::CircuitEvalKey_fhew_X::save()
{
    cout << "Saving evaluation key .. " << std::flush;
    save_oleg();
    cout << "ok\n";
}

void e3::CircuitEvalKey_fhew_X::save_fhew()
{
    FILE * fp = fopen(filename().c_str(), "w");
    FHEW::fwrite_ek(*e3fhew::toek(key), fp);
    fclose(fp);
}

void e3::CircuitEvalKey_fhew_X::save_oleg()
{
    const FHEW::EvalKey & k = *e3fhew::toek(key);

    std::ofstream of(filename(), std::ios::binary);

    char c0 = '\0';
    char c1 = '\1';
    char szi = char(sizeof(int));
    char szd = char(sizeof(double));
    char szq = char(sizeof(ZmodQ));

    auto wri = [&of](int i)
    {
        of.write(reinterpret_cast<const char *>(&i), sizeof(i));
    };

    auto wrd = [&of](double d)
    {
        of.write(reinterpret_cast<const char *>(&d), sizeof(d));
    };

    auto wrq = [&of](ZmodQ q)
    {
        of.write(reinterpret_cast<const char *>(&q), sizeof(q));
    };

    // 1 store type sizes
    of.write(&szi, 1);
    of.write(&szd, 1);
    of.write(&szq, 1);

    // 2 store constants
    wri(n); wri(BS_base); wri(BS_exp);
    wri(N); wri(KS_base); wri(KS_exp);
    wri(K2); wri(N2);

    // 3 save BSkey
    for ( int i1 = 0; i1 < n; i1++ )
        for ( int i2 = 0; i2 < BS_base; i2++ )
            for ( int i3 = 0; i3 < BS_exp; i3++ )
            {
                const FHEW::ct_FFT * c = k.BSkey[i1][i2][i3];
                if ( !c ) { of.write(&c0, 1); continue; }
                of.write(&c1, 1);
                for ( int i4 = 0; i4 < K2; i4++ )
                    for ( int i5 = 0; i5 < 2; i5++ )
                        for ( int i6 = 0; i6 < N2; i6++ )
                            for ( int i7 = 0; i7 < 2; i7++ )
                            {
                                double fc = (*c)[i4][i5][i6][i7];
                                wrd(fc);
                            }
            }

    // 4 save KSkey
    for ( int i1 = 0; i1 < N; i1++ )
        for ( int i2 = 0; i2 < KS_base; i2++ )
            for ( int i3 = 0; i3 < KS_exp; i3++ )
            {
                ZmodQ z;
                LWE::CipherTextQ * cqp = k.KSkey[i1][i2][i3];
                for ( int i4 = 0; i4 < n; i4++ )
                {
                    z = cqp->a[i4];
                    wrq(z);
                }
                z = cqp->b;
                wrq(z);
            }

    // 5 store marker
    of.write("1234", 4);
}
