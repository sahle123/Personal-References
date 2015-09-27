/*
*
*    Written By: Sahle A. Alturaigi
*    Date:          July 11th, 2012
*    Desript:      Example program of how int main arguments are used.
*
*/

#include <iostream>
#include <fstream>

using namespace std;

// argc represents ARGument Count. This is the number of arguments to be passed
// to the Command line--including the name of the program.

// argv[] represents ARGument Vector. This is an array of character pointers to
// the listing of all the arguments. Every element number greater than argc is
// a command line argument. Everything less than argc is part of the title of
// the command prompt.

int main(int argc, char* argv[])
{
     // argc should be 2 for correect execution.
     if (argc != 2)
          // We print argv[0] assuming it is the program name.
          cout <<"Usage: " << argv[0] << " <filename>" << cout;

     else
     {
          // We assume argv[1] is a filename to open.
          ifstream the_file (argv[1]);
          // Always check to see if the file opened successfully!!!
          if( !the_file.is_open())
               cout << "Could not open file" << cout;

          else
          {
               char x;
               // the_file.get(x) returns false if the end of the file is
               // reached or an error occurs.
               while (the_file.get(x))
                    cout << x << cout;
          }
          // the_file is closed implicitly here.
     }
     return 0;
}
