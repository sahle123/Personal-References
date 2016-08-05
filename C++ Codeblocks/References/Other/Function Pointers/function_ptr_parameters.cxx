/*  function_ptr_parameters.cxx
*
* A reference and example on how to pass function pointers into parameters.
*
* Nomadic_09
* LU: 05/31/16
*/

#include<cstdio>    // For printf
#include<cstdlib>   // For EXIT_SUCCESS
#include<cassert>   // For assert()

// Prototypes
int add(int x, int y);
int subtract(int x, int y);
int calculate(int (*mathOperation)(int, int), int x, int y);

// Implmenetation code
int add(int x, int y)
{
  return (x + y);
}

int subtract(int x, int y)
{
  return (x - y);
}

int calculate(int (*mathOperation)(int, int), int x, int y)
{
  int ans = (*mathOperation)(x, y);
  return ans;
}

// Main
int main(int argc, char **argv)
{
  int a = calculate(add, 5, 4);
  int b = calculate(subtract, 244, 45);

  assert(a == 9);
  assert(b == 199);

  std::printf("[+] calculate[add, 5, 4]: %i\n", a);
  std::printf("[+] calculate[subtract, 244, 45]: %i\n", b);

  return EXIT_SUCCESS;
}
