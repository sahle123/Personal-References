#ifndef DIRECTORY_MAKER_H_INCLUDED
#define DIRECTORY_MAKER_H_INCLUDED

// Preprocessor Directives
#include <iostream>
#include <string>
#include <cstring>
#include <direct.h> // Needed to make new folders

extern bool IS_FIRST_TIME;

//-----------------------------------------------------------------------------
// Prototypes:
//
// Checks if the user has a working directory. Does nothing if the user
// specified one in the past.
void check_directory(std::string& working_directory);
// Helper function for check_directory function.
void create_directory(std::string& working_directory, std::string& file_directory);
// Removes the "working_directory.txt" from the string.
void remove_hanging_file(std::string& working_directory);
// Fixes the stupid slashes problem with string files.
std::string resolve_slash_problem(std::string& working_directory);
//
//
// Refactored versions of the above functions
/*
std::string PromptForUserDirectory();
void EnsureUserDirectory(std::string& working_directory);
*/

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void check_directory(std::string& working_directory)
{
     std::fstream new_directory; // Needed for creating a new file.
     std::fstream file_directory;  // For opening the file.
     std::string default_directory;
     std::string temp;
     bool check = false;

     /* The value in working_directory is given to default. working_directory is set to "" */
     default_directory.assign(working_directory);
     working_directory.erase();

     file_directory.open(default_directory.c_str(), std::ios::in);

     /* If the file does not exist, this will create it */
     if(!file_directory.is_open())
     {
          file_directory.open(default_directory.c_str(), std::ios::out);
          file_directory.close();
          file_directory.open(default_directory.c_str(), std::ios::in);
          // File should be created now and this won't run again next time.
     }

     /* Check if file has directory saved */
     if(file_directory.is_open())
     {
          /* Move string in file_directory to working_directory */
          while(file_directory >> temp)
          {
               if(check)
                    working_directory.append(" ");

               working_directory.append(temp);
               check = true;
          }

          /* If the file was empty, create one */
          if(working_directory.length() == 0)
               create_directory(working_directory, default_directory);
     }
     else
          std::cout << "File did not open properly. Please quit the program.\n" << std::endl;

     file_directory.close();
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void create_directory(std::string& working_directory, std::string& default_directory)
{
     std::fstream file_directory;
     char ctrl_user_answer;

     IS_FIRST_TIME = true;

     std::cout << "You have not specified a working file directory yet.\n";
     std::cout << "Would you like to use to default? Y or N: ";
     std::cin >> ctrl_user_answer;

     /* Use default directory */
     if((ctrl_user_answer == 'Y') || (ctrl_user_answer == 'y'))
          working_directory.assign(default_directory);

     /* Use user specified directory */
     else
     {
          ClearScreen();
          std::cout << "Please type out the FULL filepath \n(Make sure to put double slashes in order for this to work): ";
          fflush(stdin);
          getline(std::cin, working_directory);
     }

     /* Save the input file directory onto a text file. */
     file_directory.open(working_directory.c_str(), std::ios::out);
     remove_hanging_file(working_directory);
     file_directory << working_directory;
     file_directory.close();
     ClearScreen();

     std::cout << "Working file directory information has been saved.\n" << std::endl;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

void remove_hanging_file(std::string& working_directory)
{
     /* Do nothing if the work_dir is empty */
     if(working_directory.empty())
          return;

     /// Name of the file I use to store the working directory.
     std::string str_temp = "work_directive.txt";

     int length_working_dir; // Number of characters in the working_directory folder.
     int length_str_temp;     // Number of chars in str_temp.
     int length_delete;         // The size of how much I want to delete in the file.


     /* Getting the length of both working_directory and str_temp */
     length_working_dir = working_directory.length();
     length_str_temp = str_temp.length();

     /* Calculating number of strings to delete. */
     length_delete = (length_working_dir - length_str_temp);

     /* Here the syntax: .replace(How many characters to move, how many
                                  to delete after move, what string to replace) */
     // The +1 and -1 are just for balancing where I want to delete the string.
     working_directory.replace(length_delete - 1, length_str_temp + 1, "");

     /* Appending the text "text_files_folder" to the working_directory
     string */
     working_directory.append("\\text_files_folder");

     /* Create new folder */
     mkdir(working_directory.c_str());
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
std::string resolve_slash_problem(std::string& working_directory)
{
     unsigned int i, temp2_offset;
     char* temp1;
     char* temp2;
     temp1 = new char[working_directory.size() + 1];
     temp2 = new char[working_directory.size() + 11];

     strcpy(temp1, working_directory.c_str());
     strcpy(temp2, working_directory.c_str());
     temp2_offset = 0;

     for(i = 0; i < working_directory.size() + 1; ++i)
     {
          temp2[i + temp2_offset] = temp1[i];

          if((temp1[i+1] == '\\'))
          {
               temp2[i+ temp2_offset + 1] = temp1[i+1];
               temp2[i + temp2_offset + 2] = '\\';
               ++temp2_offset;
          }
     }

     working_directory.erase();
     for(i = 0; temp2[i] != 0; ++i)
          working_directory += temp2[i];

     /*std::cout << "\nArray:\n";
     for(i = 0; temp2[i] != 0; ++i)
     {
          std::cout << temp2[i];
     }*/

     //std::cout <<"\nString:\n";
     //std::cout << working_directory << std::endl;
     delete [] temp2;
     delete [] temp1;

     return working_directory;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/*
std::string PromptForUserDirectory()
{
     std::string dirName = "";

     std::cout << "Please type the FULL path of where you want your files to be stored."
                     << std::endl;
     getline(std::cin, dirName);

     return dirName;

}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void EnsureUserDirectory(std::string& working_directory)
{
     std::fstream dirFile;
     dirFile.open(working_directory.c_str(), std::ios::in);

     if(dirFile)
     {
          dirFile >> working_directory;

          if(working_directory.length() == 0)
               dirFile << PromptForUserDirectory();
     }
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
*/
#endif // DIRECTORY_MAKER_H_INCLUDED
