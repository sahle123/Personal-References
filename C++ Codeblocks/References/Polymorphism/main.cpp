/*
*   Author: Sahle "Nomad" Alturaigi
*   Date:    Dec. 26th, 2012
*
*   Des:     This will serve as a reference for polymorphism in C++.
*
*/

#include <iostream>
#include <cstdlib>

using namespace std;

// Classes
class Enemy {
     public:
          void setAttackPower(int newAttackPower)
          {
               attackPower = newAttackPower;
          }

     protected:
          int attackPower;
};

class Pirate: public Enemy {
     public:
          void attack()
          {
               cout << "Argh!!! Ye be walkin' the plank! -" << attackPower
                       << " hp" <<endl;
          }
};

class Dominator: public Enemy{
     public:
          void attack()
          {
               cout <<"TARGET CONFIRMED. TERMINATING...  -" << attackPower
                       << " hp" << endl;
          }
};

// Prototypes

int main()
{
     // Create the objects
     Pirate obj_pirate_1;
     Dominator obj_domin_1;

     // Call an Enemy function within Pirate and Dominator
     obj_pirate_1.setAttackPower(25);
     obj_domin_1.setAttackPower(100000);

     // OR you could create 2 pointers of type Enemy to achieve the same thing
     // as above. 'Not sure which is more efficient.
     /*
     Enemy *enemy1 = &obj_pirate_1;
     Enemy *enemy2 = &obj_domin_1;

     enemy1->setAttackPower(25);
     (*enemy2).setAttackPower(100000);
     */

     // Call the attack functions.
     obj_pirate_1.attack();
     obj_domin_1.attack();


     return EXIT_SUCCESS; // For prof. Main!
}
