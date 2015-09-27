/*
 * dynamic_variables.cxx
 *
 * 	This is practice with Dynamic memory.
 *
 *  Created on: 3-9-12
 *      Author: Sahle A. Alturaigi
 */


#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

//Prototypes
void simple_dynamic();
void array_dynamic();

int main( )
{
    char c;

    cout << "Give character value. ";
    cin >> c;

    switch(c)
    {
        case 's': simple_dynamic(); break;
        case 'a': array_dynamic(); break;
        default : return 0;
    }

    return 0;
}

void simple_dynamic()
{
    typedef int latral; // all latral data types are type int.

    latral x;
    latral* y_ptr;
    // y is a pointer variable, regardless of where the asterisk is put.

    cout << "Please input x: ";
    cin >> x;

    y_ptr = new latral;
    *y_ptr = x;

    cout << "\ny_ptr is equal to: " << *y_ptr << endl;
    cout << "x is equal to:" << x << endl;

    delete y_ptr; // Deallocate y_ptr.

}

void array_dynamic()
{
	typedef int latral;

	latral *students;
	latral std_num;
	latral i;
	latral stored;

	cout << "please enter how many students you wish to enter: ";
	cin >> std_num;

	cout << "\nAn array of " << std_num << " indices has been specified." << endl;
	students = new latral[std_num];

	for (i = 0; i < std_num; ++i)
	{
		students[i] = 0;
	}

	do
	{
        cout << "Please specify an index you wish to input information. ";
        cin >> i;
	} while(i > std_num - 1 || i < 0);

	cout << "\nPlease input integer value, please.";
	cin >> stored;
	students[i] = stored;

	cout <<"\n Printing out values of the array... " << endl;
	for(i = 0; i < std_num; ++i)
	{
		cout << students[i] << endl;
	}

	/// To delete pointers properly
	delete[] student;
	student = NULL;
}
