/*
*    Date: 09/06/12
*    Author: Sahle A. "Nomad" Alturaigi
*    Description: (Poorly programmed) Doing tests with left and right shifts. Sort of simulating a 4 bit style word.
*                      Of course I'm still using 4 bytes for my intergers...
*
*/

#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

// Global variables:
const unsigned int WID = 30;

int l_shift(int n);
int r_shift(int n);
void switch_case();

int main()
{
    switch_case();
    return 0;
}

int l_shift(int n)
{
    return (0xFu << (4 - n));
}

int r_shift(int n)
{
    return (0xFu >> (4 - n));
}

void switch_case()
{
    int amount;
    string shifted_prompt;
    char a;

    cout << "   Value of 15 (0xF) will be shifted left or right by specified amount."
            <<"\nAssume word size is equal to 4 bits for this program."
            << "\nAny value over 4 will be modded to work with the functions." << endl;
    cout << "\nEnter amount and case letter ('l' for left or 'r' for right): ";
    cin >> amount >> a;

    // Will use modular arithmetic to make sure amount is no greater than 4.
    amount = amount % 5;

    cout << "\nPrecalculation (after moding by 5):\n" << endl;
    cout << setw(WID) << "Decimal value: " << amount << endl;
    cout << setw(WID) <<"Hexidecimal value: ";
    printf("0x%x\n\n", amount);

    switch(a)
    {
        case 'l':
            amount = l_shift(amount);
            shifted_prompt = "SHIFTED LEFT";
            break;
        case 'r':
            amount = r_shift(amount);
            shifted_prompt = "SHIFTED RIGHT";
            break;
        default:
            return;
    }

    cout << "Postcalculations:\n" << endl;
    cout << setw(WID) << shifted_prompt << endl;
    cout << setw(WID) << "Decimal value: " << amount << endl;
    cout << setw(WID) << "Hexidecimal value: ";
    printf("0x%x\n", amount);
}
