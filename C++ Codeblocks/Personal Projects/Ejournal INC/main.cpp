/*
*
*    Written By: Sahle A. Alturaigi
*    Date:         June 25th, 2012
*
*    Description:  The program will prompt the user if he/she would like to edit, input or review any journal entries.
*
*                        INPUT: This program will ask the user for the current date, then the
*                        title of today's journal and then store the story the user wishes to input.
*
*                        EDIT: The program will ask for the date and then which of the follow titles.
*
*                        REVIEW: The program will ask for the date and then the title then display on the screen.
*
*/

/// THIS CODE NEEDS A LOT OF WORK!!!

#include <iostream>
// ofstream: Stream class to write on files.
// ifstream: Stream class to read from files.
// fstream: Stream class to both read and write from/to files.
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

// Structs
struct e_journal {
     int month;
     int day;
     int year;
     string topic;
     string main_file;

     void initialize()
     {
          month = 0;
          day = 0;
          year = 0;
          topic = "";
          main_file = "";
     }
};

// Prototypes:

// Prompts the user asking which file he/she would like to open then the function
// proceeds to read the file and display it on the command prompt.
// (Mostly done; needs stress testing).
void read_file();

// Prompts the user to input the date (Month, day, year), the topic and then
// the actual text can be written on. A delimiter will be announced to the user
// so that the text file can be ended. (Code needs more work. Perhaps text file
// should be with MS word).
/// No data
void write_file();

// The user will be asked for a certain date or topic the user wishes to write about.
// If wanted, the directory of all files can be opened and the user can select
// from it. Afterwards, the main text file can be modified and then closed
// and saved once completed.
/// No data
void edit_file();

int main()
{
     char ctrl_alpha;
     bool ctrl_quiter = false;

     cout << "Welcome to the E-journal program (:\n";

     while(!ctrl_quiter)
     {
          cout << setw(40) << "\n\nHere are all your available choices:\n" << endl;
          cout << "R: This command will allow you to Read files." << endl;
          cout << "W: This command will allow you to Write a new file and save it" << endl;
          cout << "E: This command will allow you to edit a file and save it with" << endl
                  << setw(28) << "the changes applied to it" << endl;
          cout << "Q: This will quit the program." << endl;
          cin >> ctrl_alpha;

          switch(ctrl_alpha)
          {
               // --- For case R ---
               case 'R':
               read_it:
                    read_file();
                    break;
               case 'r':
                    goto read_it;
                    break;
               // --- End case R ---

               // --- For case W ---
               case 'W':
               write_it:
                    write_file();
                    break;
               case 'w':
                    goto write_it;
                    break;
               // --- End case W ---

               // --- For case E ---
               case'E':
               edit_it:
                    edit_file();
                    break;
               case'e':
                    goto edit_it;
                    break;
               // --- End case E ---

               // --- For case Q ---
               case'Q':
               quit_it:
                    ctrl_quiter = true;
                    break;
               case'q':
                    goto quit_it;
                    break;
               // --- End case Q ---

               default:
                    cout << "Invalid input..." << endl;
                    break;
          }
     }
     return EXIT_SUCCESS;
}

void edit_file()
{
     return;
}

void read_file()
{
     e_journal entry;
     ifstream infile;
     string get_lines;
     string folder_path = "C:\\Users\\admin\\Documents\\Code_blocks_projects\\E_journal\\entries\\";
     string temp = "dir ";

     // Set all values to 0
     entry.initialize();
     temp = temp + folder_path;
     system(temp.c_str());

     cout << "Please enter the file you wish to open" << endl;
     cin >> entry.topic;
     cout << "You entered: " << entry.topic << endl;

     folder_path = folder_path + entry.topic + ".txt";

     // The member function for infile, open requires the first parameter to be a const char*
     // to do that, I convertered my string to a c-style string with the member function
     // .c_str().
     infile.open(folder_path.c_str(), ios::in);
     // Checks if the file is open. Constantly checks if it's good and then proceeds to
     // to extract all the characters in the file and print it out on the command prompt.
     // ELSE, the an error message is printed and the program terminates.
     if(infile.is_open())
     {
          system("cls"); /// Change it later
          while(infile.good())
          {
               while(!infile.eof())
               {
                    // I've noticed that when you put a delimiter, the program recognizes broken lines.
                    getline(infile, get_lines, '`');
                    cout << get_lines;
               }
          }
          infile.close();
     }
     else
     {
          cout << "Error in opening the file." << endl;
          return;
     }

     // Waits for the user to input a keystroke.
     cout << "\n\nPress enter to continue..." << endl;
     cin.get();
     cin.ignore();
}

void write_file()
{
     return;
}

/*
     // Examples taken from cplusplus.com. Courtesy of Volatile Pulse.

#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
     // Used to send command to system
     std::string command = "mkdir C:\\";
     // Used to store user's foldername
     std::string folderName;

     // Print instructions to user
     std::cout << "Please enter a name for the new folder located at C:\\";
     // Get's user's foldername
     getline(std::cin, folderName, '\n');

     // Puts the strings together
     std::string commandString = command + folderName;

     // Show the file being created
     system("echo on");
     // Making directory
     system(commandString.c_str());
     // Shows files/folders
     system("dir");

     // Exits main
     return 0;
}
*/
/*
     // Example how to read code from a file.

     ifstream infile;
     string get_lines;

     infile.open("example.txt");
     while(!infile.eof())
     {
          getline(infile, get_lines);
          cout << get_lines;
     }
     infile.close();
*/
/*
int main()
{
     // A lot of garbage code that provides some reference as to how to work with
     // input/output files.

     e_journal entry;
     entry.initialize();
     char ins_alpha;

     ofstream myfile;

     cout << "topic, entry" << endl;
     //cin >> entry.month >> entry.day >> entry.year
     cin >> entry.topic;

     myfile.open("example.txt");
     getline(cin, entry.main_file, '}');
     cout << entry.topic << endl;
     cout << entry.main_file << endl;
     myfile << entry.main_file;
     myfile.close();

     cout << "Press 'O' to open the file. Press any other key to close the program" << endl;
     cin >> ins_alpha;

     if((ins_alpha == 'o') || (ins_alpha == 'O'))
     {
          ifstream _myfile_open;
          _myfile_open.open("example.txt");
          _myfile_open.close();
     }
     else
          return EXIT_SUCCESS;
}*/
