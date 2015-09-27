/*
 * recursion_prac.cxx
 *
 *	Example code for use of recursion.
 *
 *  Created on: Apr 17, 2012
 *      Author: Sahle A. Alturaigi
 */

#include <iostream>
#include <cstdlib>
using namespace std;


int sum(int a[], int i, int end);
void print_array(int a[], int i, int end);
int golden_ratio(int n);

int main()
{
	int array[5] = {1, 2, 3, 4, 5};
	int tot;

	/*tot = sum(array, 0, 4);
	cout << tot << endl; // Output: 15
	print_array(array, 0, 4); // Output: 1 2 3 4 5*/

	cout << golden_ratio(10);

	return EXIT_SUCCESS;
}

//---------

//---------
int sum(int a[], int i, int end)
{
	if(i == end) // This if statement is known as the terminating or base condition.
	{
		return a[i];
	}
	return (a[i] + sum(a, i+1, end));
}

//---------

//---------
void print_array(int a[], int i, int end)
{
	if(i == end) // Base condition
	{
		cout << a[i] << endl;
		return;
	}
	cout << a[i] << " ";
	print_array(a, i + 1, end);
}

//---------

//---------
int golden_ratio(int n)
{
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}

	return (golden_ratio(n-1) + golden_ratio(n-2));
}
