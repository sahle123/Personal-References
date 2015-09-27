/*  String_reference.cxx
*
*   Sahle "Nomad" Alturaigi
*
*       Simple reference to use C++ strings.
*
*   4/21/14
*
*/

#include <iostream>
#include <stdlib.h> /* atoi */
#include <string>

using namespace std;

void bad_way();     // Can only get one word. Any strings after first whitespace will not be taken.
void better_way();  // Gets whole line--even with whitespaces.

int main(int argc, char* argv[])
{
    string input_s = "";
    int input_int = -1;

    cout << "1 = bad way, 2 = better way. Choose: ";

    // Convert string to int.
    cin >> input_s;
    input_int = atoi(input_s.c_str());

    switch(input_int)
    {
    case 1:
        bad_way();
        break;
    case 2:
        better_way();
        break;
    default:
        cout << "\nInvalid input. Terminating..." << endl;
    }

    return 0;
}

void bad_way()
{
    string input = "";
    cout << "Type in something: " << endl;
    cin >> input;
    cout << "You typed in: " << input << endl;
    return;
}

void better_way()
{
    string input = "";
    cout << "Type in something: " << endl;
    cin.ignore();   // Need to call this to ignore leading whitespace characters
    getline(cin, input);
    cout <<"You typed in: " << input << endl;
    return;
}
