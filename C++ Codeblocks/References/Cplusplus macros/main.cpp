/*
*    Author: Sahle "Nomad" Alturaigi
*    Date:    Jan. 11th, 2013
*
*         This will serve as a basic run-down on how Preprocessor directives and macros work
*         Some useful macros to remember:
*
*              #define   Defining a macro
*              #undef    Undefining a marco (remove its value and name)
*              #ifdef      If defined. If the macro in #ifdef exists, then the code will be compiled.
*              #ifndef    If not defined. Like #ifdef, only negated.
*              #endif     End if. Marks the end of the ifdef macro.
*              #if          Just like an if statement for the macro
*              #else      Just like an else statement
*              #elif        Just like an else if statement.
*/

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/* Example 1 */
//
// Definitions are only valid until the #undef macro is called.
// So this code here is equivalent to:
//   int table1[100];
//   int table2[200];
#define TABLE_SIZE 100
int table1[TABLE_SIZE];
#undef

#define TABLE_SIZE 200
int table2[TABLE_SIZE];
#undef
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/* Example 2 */
//
// If the TABLE_SIZE macro was defined, then continue in the body
// all the way up to #endif. If not, then don't compile this.
// That is basically what this part does.
//
#ifdef TABLE_SIZE
int table[TABLE_SIZE];
#endif

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/* Example 3 */
//
// This will achieve the same thing in example 2 as long as
// the TABLE_SIZE macro was not defined.
//
#ifndef TABLE_SIZE
#define TABLE_SIZE 100
int table[TABLE_SIZE];
#endif
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/* Example 4 */
//
// This may be incorret, but the chunk of code blocked with the respective
// if statement is what is compiled if the statement is true. Do note that
// at the end of this entire macro, an #endif macro is needed.
//
#if TABLE_SIZE>200
#undef TABLE_SIZE
#define TABLE_SIZE 200

#elif TABLE_SIZE<50
#undef TABLE_SIZE
#define TABLE_SIZE 50

#else
#undef TABLE_SIZE
#define TABLE_SIZE 100
#endif
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

int main()
{
    return 0;
}
