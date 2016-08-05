/*  FuncPtrArray.cxx
*
* Reference on how to user a function pointer as an array of funcPtrs.
*
* Nomadic_09
* LU: 05/31/16
*/

#include<cstdlib>
#include<cstdio>

// Prototypes
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

// Implemenation
int add(int x, int y)
{
  return (x + y);
}

int subtract(int x, int y)
{
  return (x - y);
}

int multiply(int x, int y)
{
  return (x * y);
}

int divide(int x, int y)
{
  if(y == 0)
    return 0;
  else
    return (x/y);
}


// Main
int main(int argc, char** argv)
{
  int choice = 0;
  int a, b = 0;
  // Initializing function pointer array with 4 indicies.
  int (*fp_array[]) (int, int) = { add, subtract, multiply, divide };


  printf("Enter a choice:\n[+] 0 for Addition\n[+] 1 for Subtraction"
  "\n[+] 2 for multiply\n[+] 3 for divide\n");
  scanf("%d", &choice);

  if(choice > 3)
    return 0;

  printf("Enter two numbers to operate on: ");
  scanf("%d%d", &a, &b);

  // Invoke appropriate function in function pointer array
  a = (*fp_array[choice])(a, b);

  printf("\n[+] Ans: %d\n", a);

  return EXIT_SUCCESS;
}
