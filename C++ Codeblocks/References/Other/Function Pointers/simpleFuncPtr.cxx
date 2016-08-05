/* simpleFuncPtr.cxx
*
* A straight forward example on how to declare a function pointer, assign it,
* and call it.
*
* Nomadic_09
* LU: 05/29/16
*/

#include<iostream>

// Prototypes
void myPrint (int x);

// Implementation
int main(int argc, char **argv)
{
  // Function pointer
  void (*myFuncPtr) (int);

  // Assgin it to a function
  myFuncPtr = myPrint; // 'myFuncPtr = &myPrint' is equivalent

  // Call the function via the function pointer
  myFuncPtr(5);

  // You may also dereference it which is equivalent to the above code
  (*myFuncPtr)(5);

  return 0;
}

void myPrint (int x)
{
  printf("[+] You gave: %d\n", x);
}
