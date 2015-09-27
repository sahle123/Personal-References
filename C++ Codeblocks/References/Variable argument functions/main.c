/*
*   Author: Sahle A. Alturaigi
*   Date:   Oct. 28th, 2013
*
*   Example code on how to make and work with a Variable argument
*   function in C. (I am sure there is a better implementation for
*   for C++ but this works fine with it.) Generally, if you can
*   avoid using a variable argument function, then avoid it.
*
*   Reference: http://www.cprogramming.com/tutorial/c/lesson17.html
*
*   Thank you Alex Allain
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> // This library is needed in order for this to work.

// This will average all the passed in parameters.
// Note the ellipsis '...' This tells the compiler it should accept
// however many arguments the programmer passes in as long as at
// least one parameter is passed in.
double average(int num, ...);

int main()
{
    printf("%f\n", average(3, 12.2, 72.3, 4.5));
    printf("%f\n", average(5, 3.3, 2.2, 1.1, 5.5, 3.3));
    return 0;
}

double average(int num, ...)
{
    // va_list will store variable amount of arguments.
    va_list arguments;
    double sum = 0;
    int x;

    // This will initialize arguments to store all the values after num.
    va_start(arguments, num);

    for (x = 0; x < num; ++x)
    {
        // va_arg function caller tells us how many arguments there
        // are left. The first parameter is the va_list and the second
        // is the data type to be returned. va_arg is usually called
        // inside of a for loop.
        sum += va_arg(arguments, double);
    }
    va_end(arguments); // Clean up the list.

    return (sum/num);
}
