/*  Dereferencing.c
*
*   Sahle "Nomad" Alturaigi
*
*	Feb. 21st, 2014
*	Dereferencing test
*
*/

#include <stdlib.h>
#include <stdio.h>

void foo(int* input);

int main()
{
	int five = 5;
	foo(&five);
	return 0;
}

void foo (int* input)
{
	printf("Pointer address: %p\n", input);
	printf("Pointer value:   %d", *input);
}
