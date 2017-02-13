/*
  All these sizeof() values are architecture/compiler dependent.
*/

#include <stdio.h>
#include <limits.h>


int main()
{
  printf("CHAR_BIT is: %i\n", CHAR_BIT);
  if (sizeof(int*) == sizeof(int))
  {
    printf("Sizeof an int pointer and variable are the same\n");
  }
  else
  {
    printf("Sizeof an int pointer and variable are NOT the same\n");
    printf("Size of int: %ld bytes\n", sizeof(int));
    printf("Size of int*: %ld bytes\n", sizeof(int*));
  }

  printf("Pointer arithmetic\n");
  int x[5];
  int *y = x;
  for(int i = 0; i < 5; ++i)
  {
    x[i] = (i*i);
  }

  for(int i = 0; i < 5; ++i)
  {
    printf("Value of *y: %i\n", *(y+i));
    printf("Value of  x: %i\n", x[i]);
  }
  return 0;
}
