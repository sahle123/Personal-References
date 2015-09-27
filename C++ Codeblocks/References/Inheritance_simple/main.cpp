/*
*   Author: Sahle "Nomad" Alturaigi.
*   Date: Dec. 11th, 2012
*   Des: A somewhat extensive reference for how to use inheritance with classes.
*           There are a lot of examples of logic pitfalls one may fall into.
*/

#include <iostream>
#include <cstdlib>
#include "classes/Father.h"
#include "classes/Daughter.h"
using namespace std;

// Father = Base class.
// Daughter = Derived class.
// Inherited all public variables and functions of father base class.

int main()
{
    Father babbage(1);
    Daughter ada(2);

    // Both babbage and add say the same thing.
    babbage.sayStuff();
    ada.sayStuff();

    // Ada says something else.
    ada.otherStuff();

    // This will NOT work because the Father class does not
    // have any functions defined in daughter class.
    // babbage.otherStuff();

    // ada can access this because dad_number is public.
    ada.dad_number = 6;

    cout << babbage.dad_number << endl;
    cout << ada.dad_number << endl;

    // Setting protected variables.
    babbage.our_secret(3);
    ada.our_secret(4);

    // Print out protected number
    babbage.print_our_secret();
    ada.print_our_secret();

    // Print out secret number
    babbage.print_dad_secret();

    // This function works because when ada is constructed,
    // the Father constructor runs first since ada is a daughter class
    // and daughter is a derived class of Father. Note that daughter
    // does NOT inherit the constructors, rather, they only run on
    // initialization so that all the other variables in the Father
    // class will work properly for the daughter class. Since the
    // private variable dad_secret_number was initialized in the
    // Father constructor, ada will still return the same number
    // as babbage. (Somewhat confusing, eh?)
    ada.print_dad_secret();

    // More potentially confusing instances of private variables
    // and public functions.
    ada.set_secret(0);
    babbage.print_dad_secret();
    ada.print_dad_secret();

    return EXIT_SUCCESS; // For Prof. Main!
}
