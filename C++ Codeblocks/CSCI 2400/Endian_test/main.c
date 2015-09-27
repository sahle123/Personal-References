/*
     Little Endian laptop.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned char *pointer;
void show_bytes(pointer start, int len);

// x = the 4 byte interger. n = which byte from the 4 is wanted.
int get_byte(int x, int n);

int main()
{
     int a = INT_MAX;
     int b;

     printf("Max int value: %d", a);
     printf("\n");

     a = 0;
     printf("Please enter an int value for a: ");
     scanf("%d", &a);
     printf("int a = %d;\n", a);
     show_bytes((pointer) &a, sizeof(int));

    /// For get_byte test.
    b = a;
    b = get_byte(a, 2);
    printf("\nFirst byte of a equals: 0x%x", b);
    /// END get_byte test.

    /*
    // For testing shifts.
    a = (a << 14);
    printf("%d", a);
    puts("");

    show_bytes((pointer) &a, sizeof(int));*/

    return 0;
}

void show_bytes(pointer start, int len)
{
     int ctrl_i;
     for(ctrl_i = 0; ctrl_i < len; ++ctrl_i)
     {
          // Pointer arithmetic to move from one memory location to the
          // very next. (Memory address)
          printf("0x%p\t", start + ctrl_i);

          // Prints out the hexadecimal value for each index in the array.
          printf("0x%x\n", start[ctrl_i] );
     }

     printf("\n");
}

int get_byte(int x, int n)
{
    // For testing get_byte function. This one was a killa...
    int result;

	result = (x << (24 - (n*8)));
	result = (result >> 24);
	return result;
}
