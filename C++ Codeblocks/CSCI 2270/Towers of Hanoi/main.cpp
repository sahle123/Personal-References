/*
     Code written by: Shivakant Mishra

     Needs checking?

     This code solves how many moves must be completed before the Tower of hanoi moves from one side to the other.
     (With the added limitation that no smaller piece can be stacked by a larger piece). The formula for how many moves
     done is (2^n - 1) moves.
*/
#include <iostream>
#include <cstdlib>
#include "towers_of_hanoi.h"

void stack_ref();
void towers(std::size_t n, pin* A, pin* B, pin* C, std::size_t& count)
{
    count++;
    if (n == 1) A->move(C);
    if (n == 2) {                   // Base case
        A->move(B);
        A->move(C);
        B->move(C);
    }
    if (n > 2) {
        towers(n-1, A, C, B, count);
        A->move(C);
        towers(n-1, B, A, C, count);
    }
}

int main( )
{
    std::size_t count = 0;
    std::size_t n;
    cout << "Enter the number of disks initially on the source pin: " << endl;
    cout << "Or press '0' then the return key to look at the stacks mini ref output" << endl;
    cin >> n;
    if(n == 0)
    {
         stack_ref();
         return 0;
    }
    pin source(n), auxiliary, destination;
    towers(n, &source, &auxiliary, &destination, count);
    cout << "Number of time towers( ) is activated = " << count << endl;
    return(0);
}

void stack_ref()
{
     stack<int> int_stk;

     int_stk.push(2);
     int_stk.push(4);
     int_stk.push(6);

     while(!int_stk.empty())
     {
          cout << int_stk.top() << " ";
          int_stk.pop();
     }
     cout << "\n";
}
