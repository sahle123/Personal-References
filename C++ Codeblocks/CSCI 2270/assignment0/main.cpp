//***************************************************************************//
// Description
//
// Written by: Sahle A Alturaigi
//
// This is HW 0 for CSCI 2270: Data structures.
//
// The program will take in floating point number inputs of student IDs
// with their 5 quiz scores and their averages. The user also has the
// option to sort the grades in descending order.
//
//***************************************************************************//
// Directives:
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Global Constants:
const unsigned int ROW = 7; // Maximum number of rows user can input.
                            // I'm doing this so I can change my program
                            // easily in the future without much effort.
const unsigned int ST = 51; // This is the maximum amount students allowed in
                            // the program.

//------------------------------------------------------------------------------
// Prototypes:

// This function  will print out all the grades on the command prompt
// and wait for the user's "key_press" inputs.
void display(unsigned int students, double array[][ROW]);

// This will calculate the average of a students grades and the average
// of all the students grades in a single quiz.
void get_averages(unsigned int students, double array[][ROW]);

// This will check if the user has input a command. The following are
// S, A, B, C, D, E, F, T. The functions of each command is explained
// within the function.
void key_press(unsigned int students, double array[][ROW]);

// This function will take in all the inputs
void inputs(unsigned int& students, double array[][ROW]);

// This function sorts the array. The function takes a column and sorts
// the arrays from their.
void sort_it(unsigned int students, unsigned int column, double array[][ROW]);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int main( )
{
    // This will be the initial value of the array. I'm assuming their are 50
    // students until the user assigns a value to n. (Which represents initial
    // students).
    unsigned int n = 50;

    // The array (grades) will only have up to 7 indicies in each row.
    // I am following the format of homework assignment criteria.
    // The format of the grades array is grades[y][x]. y = y-axis, x = x-axis.
    double grades[ST][ROW];

    inputs(n, grades);              // Post-condition: n should equal the user's input.
    get_averages(n, grades); // Post-condition: averages should be computed.
    display(n, grades);

    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void display(unsigned int students, double array[][ROW])
{
    unsigned int x, y; // Control variables.

     cout << setprecision(0) << fixed;
     cout << "\nHere are the values: \n";
     cout << "Student ID"
     << setw(11) << "Quiz 1"
     << setw(11) << "Quiz 2"
     << setw(11) << "Quiz 3"
     << setw(11) << "Quiz 4"
     << setw(11) << "Quiz 5"
     << setw(11) << "Averages" << endl;

    // Print out quiz grades
    for(y = 0; y < students; ++y)
    {
          for(x = 0; x < ROW; ++x)
          {
               if(x == ROW - 1)
               {
                    cout << setprecision(1) << fixed;
                    cout << setw(10) << array[y][x] << " ";
               }
               else
               {
                    cout << setprecision(0) << fixed;
                    cout << setw(10) << array[y][x] << " ";
               }
          }
          cout << "\n";
     }

    // Print out quiz averages
    cout << "Quiz Averages";

    // First iteration (for alligning the grid).
    cout << setprecision(2) << fixed;
    //cout << setw(8) << array[students][1] << " ";
    for(x = 1; x < ROW - 1; ++x)
    {
          cout << setw(10) << array[students][x] << " ";
    }

    key_press(students, array);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void get_averages(unsigned int students, double array[][ROW])
{
    unsigned int x, y; // Control variables.
    double temp;       // Temporary variable.

    // Quiz averages for one student.
    for(y = 0; y < students; ++y) // Y
    {
          for(x = 1; x < ROW - 1; ++x) // X
          {
               temp += array[y][x];
          }
          array[y][ROW - 1] = temp/(ROW - 2);
          temp = 0;
    }

    // Aggregate quiz averages for all students.
    for(x = 1; x < ROW - 1; ++x) // X
    {
          for(y = 0; y < students; ++y) // Y
          {
               temp += array[y][x];
          }
          array[students][x] = (temp/students);
          temp = 0;
    }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void key_press(unsigned int students, double array[][ROW])
{
    char c;
    static bool check = true;

    if(check)
    {
          cout << endl;
          cout << "S: Prints out the grade list sorted by student IDs." << endl;
          cout << "A: Prints out the grade list sorted by Quiz 1 grades." << endl;
          cout << "B: Prints out the grade list sorted by Quiz 2 grades." << endl;
          cout << "C: Prints out the grade list sorted by Quiz 3 grades." << endl;
          cout << "D: Prints out the grade list sorted by Quiz 4 grades." << endl;
          cout << "E: Prints out the grade list sorted by Quiz 5 grades" << endl;
          cout << "F: Prints out the grade list sorted by student averages."
	     << endl;
          cout << "T: Terminates the program." << endl;

          check = false;
    }

back:
    cin >> c;

    switch(c)
    {
          case 'S': sort_it(students, 0, array); break;
          case 'A': sort_it(students, 1, array); break;
          case 'B': sort_it(students, 2, array); break;
          case 'C': sort_it(students, 3, array); break;
          case 'D': sort_it(students, 4, array); break;
          case 'E': sort_it(students, 5, array); break;
          case 'F': sort_it(students, 6, array); break;
          case 'T': cout << "Thank you for using this program. Bye! ";
          exit(0);  break;
          default:  cout <<"Please enter a legal value." << endl;
          goto back; break;
    }

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void inputs(unsigned int& students, double array[][ROW])
{
    unsigned int x, y; // Control variable.

    cout << "\nASSIGNMENT ZERO FOR CSCI 2270." << endl;

start_here:
    cout << "Please enter how many students that you are going to input: ";
    cin >> students;  // This is the new Y - 1 size of the array.

    // Test if user entered a legal value.
    if(students > 0 && students <= 50)
    {

          // Takes in users values.
          cout << "\nEnter the students info, please put spaces inbetween."
          << "\nCharacter values are strictly NOT allowed."
	     <<"\nMake sure the format is: ID, quiz 1, 2, 3, 4, 5." <<endl;
          for(y = 0; y < students; ++y) // Y
          {
               cin >> array[y][0] >> array[y][1] >> array[y][2] >> array[y][3]
               >> array[y][4] >> array[y][5];
          }

          cout <<"\n \nThe values have been stored. Now processing...";

          // Check if their is an illegal value.
          for(y = 0; y < students; ++y) // Y
          {
               for(x = 1; x < ROW - 1; ++x)   // X
               {
                    if(array[y][x] > 100 || array[y][x] < 0)
                    {
                         cout << " Error! Illegal value was inputed. Restarting..."
                         << endl;
                         goto start_here;
                    }
               }
          }
    }

    /*
      else if(students > 50)
      {
      cout << "\nSorry. You're not allowed to put over 50 students." << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      goto start_here;
      }
      else if(students <= 0)
      {
      cout << "\nHow do you have negative students? 0_o" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      goto start_here;
      }
    */

    else
    {
          cout << "\nInvalid varible, please re-enter legal value."
	     << " You must enter a value under 51." <<endl;
          cin.clear();
          cin.ignore(1000, '\n');
          goto start_here;
    }

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void sort_it(unsigned int students, unsigned int column, double array[][ROW])
{
    unsigned int x, y, i, k; // Control variables
    bool done;                   // Control variable
    double temp;              // Temporary storage.

    if(students == 1)
          done = true;

    while(!done)
    {
          for(x = 0; x < students - 1; ++x)
          {
               for(y = 0; y < students - 1; ++y)
               {
                    if(array[y][column] > array[y+1][column])
                    {
                         for(i = y; i < y + 1; ++i)
                         {
                              for(k = 0; k < ROW; ++k)
                              {
                                   temp = array[i][k];
                                   array[i][k] = array[i + 1][k];
                                   array[i + 1][k] = temp;
                                   done = false;
                              }
                         }
                    }
               }
          }
	done = true;
    }

    display(students, array);
}
//------------------------------------------------------------------------------
