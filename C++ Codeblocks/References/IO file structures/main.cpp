/*
*    Author: Sahle "Nomad" Alturaigi
*    Date:    Jan. 8th, 2013
*
*         Reference for Input/Output (I/O) of files and how to make and read file structures.
*         Ironically, most of the advanced examples can be found in the directory maker header
*
*              ofstream: Provides interface to WRITE data from files as OUTPUT streams.
*              ifstream: Provides interface to READ data from files as INPUT streams.
*              fstream: This will provide both the capabilities of ofstream and ifstream together.
*
*              You can use either / or \\ to indicate a single slash in string files.
*
*         This section is about the directory maker header.
*
*              The directory make header is a little bit messy, but it works.
*              I have found no way to use fstream to create folders. Only text files.
*              In order to create folders, I think system() MUST be used.
*              The aforementioned may hamper portability though...
*
*              Just found out that you can create folders using the direct.h header
*              The code for that will be in directory_maker.h
*/

/// 1. Advanced function NOT implemented.

#include <iostream>
#include <string>
#include <fstream>         /// <-- Necessary C preprocessor directive for managing files.
#include <conio.h>          // Needed for getch(). Irrelavent to learning file manipulation.
#include "ClearScreen.h" // Only for clearing the screen. Not Relevant to learning file manip.
#include "directory_maker.h" // Needed for making directives

using namespace std;

// Global variables:
// External variable needed to check if this is the programs first run.
// This variable is determined if any data is in the txt file that holds
// the working directory.
bool IS_FIRST_TIME = false;

//-----------------------------------------------------------------------------
// Prototypes
//
// Gets users input.
void users_choice(const string& working_directory);
// Evaluates users input.
int check_users_answer(const string& users_choice);

// Examples of using fstream below.
void simple_file_manipulation(const string& working_directory);
void advanced_file_manipulation(const string& working_directory);
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

int main()
{
     string working_directory;
     working_directory.assign("C:\\Users\\admin\\Documents\\Code_blocks_projects\\References\\IO file structures\\work_directive.txt");

     check_directory(working_directory);
     users_choice(working_directory);

     return 0;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

void users_choice(const string& working_directory)
{
     string users_choice = "";
     int ctrl_answer = 0;                // Needed for the switch statement
     bool done_yet = false;

     while(!done_yet)
     {
          cout << "Please type in one of the following from the list"<< endl;
          cout << "   -Simple\n   -Advanced\n   -Quit" << endl;
          cin >> users_choice;
          ctrl_answer = check_users_answer(users_choice);

          switch(ctrl_answer)
          {
               case 0:
                    return;

               case 1:
                    users_choice = "";
                    done_yet = true;
                    simple_file_manipulation(working_directory);
                    break;

               case 2:
                    users_choice = "";
                    done_yet = true;
                    advanced_file_manipulation(working_directory);
                    break;

               default:
                    cout << "\nThat is an invalid input..." << endl;
                    users_choice = "";
                    getch();
                    ClearScreen(); /// <-- Such an immensley awesome function!!
                    break;
          }
     }
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
int check_users_answer(const string& users_choice)
{
     // Case for user choosing to quit the program.
     if((users_choice == "Quit") || (users_choice == "quit"))
          return 0;

     // Case for user choosing "Simple"
     else if((users_choice == "Simple") || (users_choice == "simple"))
          return 1;

     // Case for the user choosing "Advanced"
     else if((users_choice == "Advanced") || (users_choice == "advanced"))
          return 2;

     else
          return -1;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void simple_file_manipulation(const string& working_directory)
{
     string file_path;

     file_path.assign(working_directory);
     file_path.append("\\file_test1.txt");

     if(!IS_FIRST_TIME)
          file_path = resolve_slash_problem(file_path);

     // This will allow us to create a file. I am going to use the constructor
     // of ofstream. There are different ways you can do this. It is also
     // important to understand that nomads_file can be associated with
     // anyother ofstream variable too. Think of it as an object--not as the
     // actual file itself.
     // Also, fstream nomads_file(\\file_path.c_str(), std::ios::out); works too.
     ofstream nomads_file;
    nomads_file.open(file_path.c_str());

     // The member function .is_open() is used to check if the object
     // (nomads_file) is correctly associated with any file. It will return
     // true if it is and false if it is not.
     if(nomads_file.is_open())
     {
          // There is where you do all your file stuffs.
          nomads_file << "The quick brown fox jumps over the lazy dog. HI HI HI HI\n";
     }
     else
     {
          cout << "File did NOT open correctly. D:";
          //cout << "\nworking_directory: \n" << working_directory;
          nomads_file.close();
          return;
     }

     // Make sure that when you are done with the object (nomads_file) that you
     // properly close it using the following function. This is a good practice.
     nomads_file.close();

     cout << "The Simple function has run and worked perfectly." << endl;
     return;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void advanced_file_manipulation(const string& working_directory)
{
     cout << "The Advanced function has run and worked perfectly. :D" << endl;
     return;
}
