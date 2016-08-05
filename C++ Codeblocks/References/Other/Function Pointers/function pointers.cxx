/* function pointers.cxx
*
* Reference on how to use and work with function pointers.
* Some external references:
*   http://www.cprogramming.com/tutorial/function-pointers.html
*   http://c.learncodethehardway.org/book/ex18.html
*   http://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work
*   http://denniskubes.com/2013/03/22/basics-of-function-pointers-in-c/
*
* Nomadic_09
*
* LU: 05/29/16
*/

#include<iostream>
#include<cstdlib>
//using namespace std; // Causes scoping errors. Not exactly sure why...

// A typedef for function ptrs for returning values.
// There is another way of achieving this, but it's verbose and confusing
// to follow.
typedef int (*myFuncDef)(int, int);

/***  Prototypes  ***/
// Basic function
int plus (int p, int q);

// Passing a function ptr into a function.
int add2to3( int (*functionPtr)(int, int) );

// A function ptr that assigns the "plus" function as its return type
myFuncDef functionFactory(int n);

/***  Implementation  ***/
int main(int argc,char **argv)
{
  int sum;

  // Function pointers use the following syntax:
  // datatype (*pointer_name) (arguments);
  // e.g.
  // int (*hello) (int a, int b);
  int (*funcPtr) (int, int);

  // Assign function pointer
  funcPtr = &plus; // funcPtr = plus; is also equivalent

  // Or we can assign funcPtr with our factory function
  funcPtr = functionFactory(1337);

  // Call our function pointer and store result inside 'sum'
  sum = (*funcPtr)(5, 7);
  printf("[+] Sum = %i\n", sum);

  // Passing a function pointer (Callback) to a function
  printf("[+] Ans = %i\n", add2to3((*funcPtr)));

  return 0;
}

// plus
int plus(int p, int q) { return (p + q); }

// add2to3
int add2to3( int (*functionPtr)(int, int) )
{
  return (*functionPtr)(2,3);
}

// functionFactory
// n isn't used for anything except for showing that we can pass in parameters.
myFuncDef functionFactory(int n)
{
  printf("[+] Got parameter %i\n", n);
  myFuncDef leFuncPtr = plus;
  return leFuncPtr;
}
