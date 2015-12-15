/*
 * pointers.cxx
 *
 *       Created on: Feb 21, 2012
 *       Author: Sahle A. Alturaigi
 *
 *		& 	Reference operator. Similar to symbolic links; they can refer to a
 *			variable, but once allocated, it cannot be changed. Deleting a reference
 *			does NOT affect the original variable. Less powerful than pointers but
 *			often used in conjunction.
 *
 *		* 	Dereference operator. This will return the value stored inside of the 
 *			pointer. When declaring variables, using the * operator will declare 
 *			that said variable is a pointer of some type. When we call the variable
 *			again without the operator, we will get its address. When we use the *
 *			once more, this will give us the value that it has been assigned to.
 *
 *		http://stackoverflow.com/questions/2336230/difference-between-const-pointer-and-reference
 *		http://c-faq.com/decl/spiral.anderson.html
 *
 */

// Libraries
#include <iostream>
using namespace std;

void pointers_to_static();
void pointers_to_dynamic();
void pointers_to_arrays();
void pointers_to_2D_arrays();

int main( )
{
	pointers_to_static();
	cout <<"\nNext..." << endl;

	pointers_to_dynamic();
	cout << "\nNext..." << endl;

	pointers_to_arrays();
	cout <<"\nNext..." << endl;

	pointers_to_2D_arrays();
	cout <<"\nDone..." << endl;

	return 0;
}
//----------------------
void pointers_to_static()
{
	// Pointers to Static variables
	// Static memory

	int x;
	int *x_ptr;

	cin >> x;
	x_ptr = &x;

	cout << x;
	cout << *x_ptr; // Dereferenced which points to int x. Prints out value of int x.
	cout << x_ptr;  // Prints out the address of what x_ptr is pointing to --> int x.
}
//----------------------
void pointers_to_dynamic()
{
	// Pointers to dynamic variables
	// Dynamic memory

	int *y_ptr;

	// new creates a new variable type of the parameter in front of it.
	// This is known as a HEAP variable.
	y_ptr = new int;

	*y_ptr = 37; // Dereferenced y_ptr. Changes pointed value, not address.

	// The more dynamic memory you use, the larger your HEAP memory is. Use the delete function
	// to reduce the amount of memory used.
	// When one is done using the dynamic memory that your pointer variable is pointing to, use
	// the delete[] function.
	delete y_ptr;
}
//----------------------
void pointers_to_arrays()
{
	// Pointers to 1D arrays
	// Dynamic memory

	int *students;
	int numofstudents;

	cin >> numofstudents;

	// An array of integers contingent on the pointer variable: students
	// Note: The last block of memory is usually the address of the array.
	students = new int[numofstudents];

	for(int i = 0; i < numofstudents; ++i)
	{
		cin >> students[i];
	}

	cout << students[3];
	// Pointer arithmetic will take the last block of memory of the array it is pointing and move up 3 blocks of memory.
	// Pointer arithmetic is dependent on the compiler that is being used. Be sure to test this.
	cout << *(students + 3);

	delete[]students; // Freed up memory, the new int assigned to it is no longer taken into account.
}
//----------------------
void pointers_to_2D_arrays()
{
	// Pointers to 2D arrays.
	// Dynamic memory

	int **students; // The double asterisk allows this pointer to have 2 dimensions. Usually used for 2D arrays.
	int rows = 5;
	int columns = 6;

	// Look up new * arrays
	// This will allow the pointer variable: students, to have an array of pointers that point to another variable.
	students = new int *[rows];

	for(int i = 0; i < rows; ++i)
	{
		students[i] = new int [columns];
	}

	// Effectively, an array of students[i][j] has been created. So if one wishes to access or alter any data in the arrays, it can be done so normally like a typical
	// 2D array.

	for(int i = 0; i < rows; ++i)
	{
		delete[]students[i]; // To free up memory, one deletes the all the pointer indices in the array.
	}

	delete[]students; // To free up memory, one deletes the actual pointer variable.
	students = NULL;
}
