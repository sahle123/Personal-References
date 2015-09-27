#include<iostream>
#include<limits.h>

// Warning! Very inefficient function. CPU lags when n > 30
template<class fib_data>
unsigned int fib(fib_data n, int &steps);

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

int main()
{
     unsigned int ctrl_a;
     unsigned int counter_var = 0;
     unsigned int check;
     static int counter_steps = 0;

     std::cout << "The max unsigned int is: " << UINT_MAX << std::endl;
     std::cout << "Enter value for n:\a" << std::endl;
     std::cin >> ctrl_a;
     std::cout << "Computing" << std::endl;

     check = fib(ctrl_a, counter_steps);
     //++counter_steps;
     ctrl_a = 0;

     while(counter_var < check)
     {
          counter_var = fib(ctrl_a, counter_steps);
          ++ctrl_a;
          //counter_steps = counter_steps + 3;

          std::cout << "counter_var: " << counter_var << std::endl;
     }

     std::cout << "Number of calculations: " << counter_steps << std::endl;
     return 0;
}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
template<class fib_data>
unsigned int fib(fib_data n, int &steps)
{
     if(n == 0)
          return 0;
     if(n == 1)
          return 1;

     steps = steps + 2;

     return (fib(n - 1, steps) + fib(n - 2, steps));
}
