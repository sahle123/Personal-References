/*
*    Author: Sahle "Nomad" Alturaigi
*    Date:    Dec. 26th, 2012
*
*    Des:     This will serve as a reference for virtual functions in C++.
*
*    Note:    Whenever you make a function "virtual", you are telling the compiler
*                that you are using the said function polymorphicaly.
                  What that means is if a derived class has a the same function name as
                  its base class, then it will use the derived classes function.
*/
#include <iostream>

using namespace std;

class Enemy {
     public:
          void setAttackPower(int newAttackPower)
          {
               attackPower = newAttackPower;
          }
          virtual void attack()
          {
             cout << "You were attacked! -" << attackPower << " hp" << endl;
          }
          // virtual void attack () = 0; <--- this is known as a PURE virtual function.
          //                                              if a derived function does NOT have a function with the name attack
          //                                              the program will return an error during build time.
     protected:
          int attackPower;
};

class Pirate : public Enemy {
     public:
          void attack()
          {
               cout << "Yarrrggg! Take that pernacious caitiff!! -" << attackPower << " hp" << endl;
          }
};

class Critter : public Enemy {
     public:
          void interact()
          {
               cout << "I think the critter likes you!!! :3" << endl;
          }
};


int main()
{
     Pirate obj_enmy1;
     Critter obj_nhrm1;

     obj_enmy1.setAttackPower(34);
     obj_nhrm1.setAttackPower(1);

     obj_enmy1.attack();
     obj_nhrm1.interact();

     cout << "OH NO D: The critter had a change of heart!!" << endl;

     obj_nhrm1.attack();
     return 0;
}
