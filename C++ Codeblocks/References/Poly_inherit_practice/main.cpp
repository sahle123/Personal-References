/*
*
*    Written by: Sahle A. Alturaigi
*    Date: May 31, 2012.
*    Simple test on inheritance and polymorphism
*    NOTE: some functions don't work and I implemented them for learning purposes.
*
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//-----------------
class superclass{

public:
     // Constructors
     superclass() {protect_check = 895;}
     superclass(string input_name);

     virtual ~superclass() {}

     // Mod Functions.
     virtual void print_name() {cout << "Name: " << name << endl;}
     virtual void print_score() {cout << "Score: " << score << endl;}
     virtual void insert_name(string new_name);
     virtual void insert_score(int new_score);
     virtual void get_protect_check() {print_check();}
protected:
     void print_check() {cout << "Value for protect check: "<< protect_check << endl;}

private:
     string name;
     int score;
     double protect_check; // Purely for checking if the protected functions work.
};

void superclass::insert_name(string new_name)
{
     name = new_name;
}

void superclass::insert_score(int new_score)
{
     score = new_score;
}

class subclass : public superclass {

public:
     // Constructor
     subclass()
     {
          fav_color = "None";
     }
     // Destructor
     virtual ~subclass() {}

     // Mod Functions.
     void print_color() {cout << "Color: " << fav_color << endl;}
     void insert_color(string new_color);

private:
     string fav_color;
};

void subclass::insert_color(string new_color)
{
     fav_color = new_color;
}

//-----------------
int main()
{
     string text =  "Happy";
     subclass val;

     val.insert_name(text);
     val.print_name();
     // This functions was intentionally created not to work to check a concept.
     // val.print_check();

     string color;
     char ctrl_var;
     val.print_color();

     cout << "Please type in your favorite color: ";
     cin >> color;

     val.insert_color(color);
     val.print_color();

     bool ctrl_barrier = false;
     while(!ctrl_barrier)
     {
          cout << "Would you like to check the protected integer? Type in Y for yes or N for no: ";
          cin >> ctrl_var;
          switch(ctrl_var)
          {
          case 'Y':
               val.get_protect_check();
               ctrl_barrier = true;
               break;
          case 'N':
               ctrl_barrier = true;
               break;
          default:
               cout << "Invaild input, please type in a legal character." << endl;
               break;
          }
     }

     cout << "Done." << endl;

     return EXIT_SUCCESS;
}
