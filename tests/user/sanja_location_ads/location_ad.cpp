/* Location based advertising
   This is a real world application of E3 and fully homomorphic encryption (FHE).
   The user receives ads to events which are close to his location, while the information about the user's location stays encrypted.
   This example is based on the FHE application described in the paper of the FHE framework Marble:
   Reference:   Viand, A., & Shafagh, H. (2018, October).
                Marble: Making fully homomorphic encryption accessible to all.
                In Proceedings of the 6th Workshop on Encrypted Computing & Applied Homomorphic Cryptography (pp. 49-60). ACM.
*/

#include <iostream>
#include <utility>
#include <stdlib.h>

#include "../../e3int.h"
#include "../alice.h"

using namespace std;
using SecureInt = TypeUint<8>;
using SecureBool = TypeBool;

int main()
{
    int no_ads = 5; // number of advertisements

    // Maximum distance between the user and the advertised event. //
    SecureInt distance = _5_Eu; //In degrees of latitude. 1 degree = 110 - 111 km
    SecureInt distance_squared = distance * distance;

    // User's location in latitude (N) and longitude (E). // As an example, user is at NYUAD. //
    SecureInt user [2] = {_25_Eu, _54_Eu};

    /* In real life, the locations of advertised events would be in plaintext in a data base. They would be read
     into given arrays and encrypted.
    For simplicity, it is fine to store coordinates in an array immediately.
    */
    //Advertised events locations: Abu Dhabi, Dubai, Istanbul, Shanghai, New York. //

    // Advertised events' latitude (N). //
    SecureInt ad_N [no_ads] = {_24_Eu, _25_Eu, _41_Eu, _31_Eu, _41_Eu}; //latitude
    // Advertised events' longitude (E). //
    SecureInt ad_E [no_ads] = {_54_Eu, _55_Eu, _29_Eu, _121_Eu, _74_Eu}; //longitude

    // Which advertisements are relevant to the user's location and which are not. //
    SecureBool show_ad [no_ads];

    /* Make sure the Euclidian distance between the user and the advertised event is smalled than the predefined distance.
     Euclidian distance between the user and the advertised event:
     sqrt((user_N - ad_N)^2 + (user_E - ad_E)^2)
     If the distance is squared, the entire Euclidian distance can be squared as well, as the comparison which once
     is bigger will not fail nonetheless.
    */
    for (int i = 0; i < no_ads; i++)
    {
        show_ad[i] = ((user[0] - ad_N[i]) * (user[0] - ad_N[i]) + (user[1] - ad_E[i]) * (user[1] - ad_E[i])) < (distance_squared);
    }

    // Print out which advertised events are within the distance from the user. //
    cout << "Advertisements relevant to the user's location:\n";
    for (int i = 0; i < no_ads; i++)
    {
        cout << show_ad[i] << " ";
    }
}
