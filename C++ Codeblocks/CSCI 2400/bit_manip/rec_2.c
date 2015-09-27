/*
 * 	Date: 09/06/12
 *  Recitation 2
 * 	Sahle A. Alturaigi
 *
 * Logic Gates:
 * 	! - Logic Negation
 * 	~ - Bitwise Negation
 *  + - Addition
 * 	& - Bitwise AND (Zero and any other number including Zero will return 0 (False))
 *  | - Bitwise OR
 *  ^ - Bitwise XOR
 *
 */


#include <stdio.h>
#include <stdbool.h>

bool isZero(int x);
bool isNotEqual(int x, int y);

// Takes a 32-bit interger and reverses the bytes.
int ReverseBytes(int x);

int main()
{
	int a;

	printf("Please enter a value for a: ");
	scanf("%d", &a);

	bool check = isZero(a);
	printf("%d", check);
	return 0;
}

bool isZero(int x)
{
	return !x;
}

bool isNotEqual(int x, int y)
{
	// Double negations are used for intergers so that a non-negative number will be returned (0 or 1);
	return !!(x^y);
}

/// Masking: Methods to append certain values to certain bytes.
int ReverseBytes(int x)
{
	int result = (x & 0xFF) << 24;
	// Or you could write result |= ((x >> 8) & 0xFF) << 16; <--- Short handed version.
	result = (result | ((x >> 8) & 0xFF) << 16);
	result |= ((x >> 16) & 0xFF) << 8;
	result |= ((x >> 24) & 0xFF);

	return result;
}
