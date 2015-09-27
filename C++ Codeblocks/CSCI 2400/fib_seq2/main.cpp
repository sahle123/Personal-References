/*
*   Date: Sept. 10, 2012
*    Author: Sahle "Nomad" Alturaigi
*
*   This program finds the number of the nth (specified by the user) Fibonacci sequence.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

typedef unsigned int uuint;

uuint fib_seq(uuint n, uuint *array);

int main()
{
    uuint n;
    uuint answer;
    uuint *array;
    bool done = false;

    while(!done)
    {
        cout << "Enter a value for n: ";
        cin >> n;

        array = new uuint [n];
        answer = fib_seq(n, array);
        cout <<"\nThe answer is... " << endl << answer << endl;

        delete[] array;
        array = NULL;

        if(n == 0)
            done = true;
    }
    return EXIT_SUCCESS;
}

uuint fib_seq(uuint n, uuint *array)
{
    if(n == 0)
        return 0;
    array[0] = 0;
    array[1] = 1;

    for(uuint i = 2; i < n; ++i)
    {
        array[i] = array[i - 1] + array[i - 2];
        cout << array[i] << endl;
    }
    return array[n];
}
