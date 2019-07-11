#include <fstream>
#include <iostream>
#include <vector>

#include "e3int.h"
#include "timer.h"

using namespace std;

#define TEST_AND 1
#define TEST_NOR 1

const string queryfile = "user/snp/query.db";
const string dbfile = "user/snp/individuals.db";

template <class T1, class T2>
vector<T1> sumParts(const vector<T2> & vin)
{
    CarryAdd dummy;
    vector<T1> vout;
    size_t nElements = ((1 << T1::size()) - 1) / ((1 << T2::size()) - 1);
    size_t j = -1;
    cout << T2::size() << "->" << T1::size() << flush;
    for ( size_t i = 0 ; i < vin.size(); i++ )
    {
        cout << "." << flush;
        if (i % nElements == 0)
        {
            vout.push_back(T1(vin[i]));
            j++;
        }
        else vout[j] += T1(vin[i]);
    }
    cout << "\n";
    return vout;
}

SecureUint<20> sum(const vector<SecureUint<63>> & v)
{
    cout << "bitsum" << flush;
    vector<SecureUint<8>> v8;
    for ( auto si : v )
    {
        v8.push_back( SecureUint<8>( si.bitsum() ) );
        cout << '.' << flush;
    }
    cout << "\ncarryadd" << '\n';
    auto v9 = sumParts<SecureUint<9>, SecureUint<8>>(v8);
    auto v10 = sumParts<SecureUint<10>, SecureUint<9>>(v9);
    auto v11 = sumParts<SecureUint<11>, SecureUint<10>>(v10);
    auto v12 = sumParts<SecureUint<12>, SecureUint<11>>(v11);
    auto v13 = sumParts<SecureUint<13>, SecureUint<12>>(v12);
    auto v14 = sumParts<SecureUint<14>, SecureUint<13>>(v13);
    auto v15 = sumParts<SecureUint<15>, SecureUint<14>>(v14);
    auto v16 = sumParts<SecureUint<16>, SecureUint<15>>(v15);
    auto v17 = sumParts<SecureUint<17>, SecureUint<16>>(v16);
    auto v18 = sumParts<SecureUint<18>, SecureUint<17>>(v17);
    auto v19 = sumParts<SecureUint<19>, SecureUint<18>>(v18);
    return sumParts<SecureUint<20>, SecureUint<19>>(v19)[0];
}

int main()
{
    SecureBool b0 = _0_E;
    SecureBool b1 = _1_E;

    // private query encryption (trusted environment)
    cout << "Encrypting query .. " << flush;
    vector<SecureBool> query;
    char c;
    fstream fin(queryfile, fstream::in);
    while (fin >> noskipws >> c)
    {
        if (c == '0' || c == '1') query.push_back(c - '0' ? b1 : b0);
        else if (c == '\n') break;
    }
    cout << "ok\n";



    // server side (untrusted environment)
    vector<SecureBool> nquery;
    for ( auto q : query ) nquery.push_back(~q);

    cout << "Comparing to the database (AND: " << TEST_AND << ", NOR: " << TEST_NOR << ")\n" << flush;
    const size_t sz = 63;
    SecureUint<sz> zero = _0_E;

#if TEST_AND
    vector<SecureUint<sz>> ANDs;
    vector<SecureUint<20>> sumAND;
    size_t posAi = -1, posAj = 0;
#endif
#if TEST_NOR
    vector<SecureUint<sz>> NORs;
    vector<SecureUint<20>> sumNOR;
    size_t posNi = -1, posNj = 0;
#endif
    fstream findb(dbfile, fstream::in);
    size_t posQ = 0, i = 0;

    Timer t; // start timer

    cout << "Individual " << i << " .. " << flush;
    while (findb >> noskipws >> c)
    {
        if (c == '0' || c == '1')
        {
            c -= '0';
            if ( c )
            {
#if TEST_AND
                if ( !posAj )
                {
                    auto init = zero;
                    ANDs.push_back( init );
                    posAi++;
                }
                ANDs[posAi][posAj] = query[posQ][0];
                posAj = (posAj + 1) % sz;
#endif
            }
            else
            {
#if TEST_NOR
                if ( !posNj )
                {
                    auto init = zero;
                    NORs.push_back( init );
                    posNi++;
                }
                NORs[posNi][posNj] = nquery[posQ][0];
                posNj = (posNj + 1) % sz;
#endif
            }
            posQ++;
        }
        else if (c == '\n')
        {
            cout << "ok\n";
#if TEST_AND
            cout << "Summing ANDs (" << ANDs.size() << ") \n";
            sumAND.push_back( sum(ANDs) );
            ANDs.clear();
            posAi = posAj = 0;
#endif
#if TEST_NOR
            cout << "Summing NORs (" << NORs.size() << ") \n";
            sumNOR.push_back( sum(NORs) );
            NORs.clear();
            posNi = posNj = 0;
#endif
            posQ = 0;
            i++;

            auto r = t.get(); // end timer
            cout << "Time (ms): " << r << '\n';
            return 0;

            cout << "Individual " << i << " .. " << flush;
        }
    }
    cout << "skip\n";

    // show results
    cout << "Analyzing the results " << flush;
    size_t size;
#if TEST_AND
    SecureUint<20> smallestAND, greatestAND;
    SecureUint<20> posSmallestAND, posGreatestAND;
    smallestAND = _1_EN;
    greatestAND = _0_E;
    posSmallestAND = posGreatestAND = greatestAND;
    size = sumAND.size();
#endif
#if TEST_NOR
    SecureUint<20> smallestNOR, greatestNOR;
    SecureUint<20> posSmallestNOR, posGreatestNOR;
    smallestNOR = _1_EN;
    greatestNOR = _0_E;
    posSmallestNOR = posGreatestNOR = greatestNOR;
    size = sumNOR.size();
#endif
    SecureUint<20> ei;
    for ( i = 0; i < size; i++, ei++ )
    {
#if TEST_AND
        SecureBool condSmallestAND = sumAND[i] < smallestAND;
        SecureBool condGreatestAND = sumAND[i] > greatestAND;
        SecureBool ncondSmallestAND = !condSmallestAND;
        SecureBool ncondGreatestAND = !condGreatestAND;
        smallestAND = condSmallestAND * sumAND[i] + ncondSmallestAND * smallestAND;
        greatestAND = condGreatestAND * sumAND[i] + ncondGreatestAND * greatestAND;
        posSmallestAND = condSmallestAND * ei + ncondSmallestAND * posSmallestAND;
        posGreatestAND = condGreatestAND * ei + ncondGreatestAND * posGreatestAND;
#endif
#if TEST_NOR
        SecureBool condSmallestNOR = sumNOR[i] < smallestNOR;
        SecureBool condGreatestNOR = sumNOR[i] > greatestNOR;
        SecureBool ncondSmallestNOR = !condSmallestNOR;
        SecureBool ncondGreatestNOR = !condGreatestNOR;
        smallestNOR = condSmallestNOR * sumNOR[i] + ncondSmallestNOR * smallestNOR;
        greatestNOR = condGreatestNOR * sumNOR[i] + ncondGreatestNOR * greatestNOR;
        posSmallestNOR = condSmallestNOR * ei + ncondSmallestNOR * posSmallestNOR;
        posGreatestNOR = condGreatestNOR * ei + ncondGreatestNOR * posGreatestNOR;
#endif
        cout << "." << flush;
    }
    cout << "\n";

    char s = ' ';
    cout << s << "Individual" << s << "Value\n";
#if TEST_AND
    cout << "SmallestAND" << s << posSmallestAND << s << smallestAND << '\n';
    cout << "GreatestAND" << s << posGreatestAND << s << greatestAND << '\n';
#endif
#if TEST_NOR
    cout << "SmallestNOR" << s << posSmallestNOR << s << smallestNOR << '\n';
    cout << "GreatestNOR" << s << posGreatestNOR << s << greatestNOR << '\n';
#endif

    cout << "\n";

    cout << "Individual";
#if TEST_AND
    cout << s << "AND";
#endif
#if TEST_NOR
    cout << s << "NOR";
#endif
    cout << '\n';
    for ( i = 0; i < size; i++ )
    {
        cout << i;
#if TEST_AND
        cout << s << sumAND[i];
#endif
#if TEST_NOR
        cout << s << sumNOR[i];
#endif
        cout << '\n';
    }
}
