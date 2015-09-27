/*
*    Author: Sahle "Nomad" Alturaigi
*    Date:    Jan. 4th, 2013
*
*         This is a reference on how to use or handle C++ exceptions. In essence
*    exception handlers are used to test certain areas in the program quickly to
*    see if the correct or valid values are being processed. If an invalid value
*    is caught, then THROW gets passed as a parameter to CATCH and
*    CATCH handles the program from there.
*
*    Keywords to understand:
*         try
*              If a throw is never called in this statement, then catch will never execute.
*         throw
*              The throw value is the parameter passed to the catch statement and also
*              the variable that tells the program to run the catch statement.
*         catch
*              The catch statement is a handler that come directly after the try
*              block of code. If a throw happens in try, then catch runs.
*              Note that catchs only except 1 parameter only.
*
*/

#include <iostream>
#include <stdio.h>
using namespace std;


//-----------------------------------------------------------------------------
// Prototypes:

// This function tests a case for a mother and her daughter ages'
// If the daughter's age is greater than mother's, then the exception
// handler will run. The parameter is only used to indicate at the
// end of the program in int main if this was a good or bad run.
void basic_exceptions(bool& is_good);

// This function will simulate a simple calulator that divides 2 numbers.
// In this function, we will also test cases with multiple catches and
// see how it works.
void advanced_exceptions(bool& is_good);

// Prompts the user if they want to use the basic or advanced funciton.
bool pick_basic_or_advanced();

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
int main()
{
     bool is_good =pick_basic_or_advanced();

     // Check to see if the bool returned TRUE or FALSE.
     if(!is_good)
     {
          cout << "Bad run" << endl;
          return 0;
     }
     else
          cout << "Good run"  << endl;

     return 0;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void basic_exceptions(bool& is_good)
{
     int moms_age, daughters_age;

     cout << "Input Mother's and Daughter's age respectively: ";
     cin >> moms_age >> daughters_age;

     try
     {
          if(daughters_age >= moms_age)
               throw 0x8D75;
     }
     catch(int x)
     {
          printf("Daughter cannot be older than Mother. \nAn exception error has just occured: 0x%x\n", x);
          is_good = false;
          return;
     }

     // These 2 statements will never be reached.
     cout << "A perfectly healthy family. Gratz!" << endl;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

void advanced_exceptions(bool& is_good)
{
     double num1 = 1;
     double num2 = 1;

     printf("Please enter the numerator and denominator respectively: ");
     scanf("%lf %lf", &num1, &num2);

     // Comment out the top and put the code below back in to test the
     // ellipsis catch case (...).
     /*int num1 = 1;
     int num2 = 1;

     printf("Please enter the numerator and denominator respectively: ");
     scanf("%d %d", &num1, &num2);*/

     //cout << "Numbers input are: " << num1 << ", " << num2 << endl;

     try
     {
          if(num2 == 0.0)
               throw num2;
     }
     catch(double num2)
     {
          printf("You cannot divide by %lf! The Gods of Math will not allow such heresy!\n", num2);
          is_good = false;
          return;
     }
     // This right here is the default case (with the ...) if num2 is not a double, then it will go
     // to this catch instead.
     // This won't run since we have explicit double variables.
     catch(...)
     {
          printf("What in the world did you give me...?\n");
          is_good = false;
          return;
     }

     num1 = num1/num2;
     // The .2 is for only 2 decimals to appear.
     printf("Answer = %.2lf\n", num1);
}

bool pick_basic_or_advanced()
{
     bool is_good = true;
     bool done_picking = false;
     char ctrl_pick;

     while(!done_picking)
     {
          printf("A = advanced     B = basic: ");
          scanf("%c", &ctrl_pick);
          // Or you can remove fflush(stdin) and put the code below.
          // Notice the explicit space between " and %.
          //scanf(" %c", &ctrl_pick);

          // A good example for multiple case values in switch statement.
          switch(ctrl_pick)
          {
               case 'a':
               case 'A':
                    advanced_exceptions(is_good);
                    done_picking = true;
                    break;
               case 'b':
               case 'B':
                    basic_exceptions(is_good);
                    done_picking = true;
                    break;
               default:
                    printf("That is an invalid input.\n\n");
                    fflush(stdin);
                    break;
          }
     }

     return is_good;
}
