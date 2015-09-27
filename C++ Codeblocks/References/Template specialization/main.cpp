/*
*    Author: Sahle "Nomad" Alturaigi
*    Date:    Jan. 4th, 2013
*
*         This program will serve as a reference for how to use template specialization in
*    a rudimentary way. Only for C++. Not sure how it works for other languages.
*
*/

// C preprocessor directives
#include <iostream>

// We create our class. This will work for any data type except chars
// and this is only because I am going to create a class afterwards
// that handles char as a special case. Hence, template specialization.
template <class T>
class roflcopter {
     public:
          // Constructor for our class.
          // T is the data type and x is our variable.
          roflcopter(T x)
          {
               std::cout << x << " is NOT a character!" << std::endl;
               /*
               if (x == 1.618)
               {
                    std::cout << "Hey! turns out " << x << " is also a golden number :p"
                                    << std:: endl;
               }*/
          }
};

// Our specialized class to handle chars.
// The template function must be blank.
template<>
// We must explicitly state that Spunky will be a char using the
// syntax below.
class roflcopter<char> {
     public:
          // Constructor for our class.
          // Notice that we explicitly put char in here as well.
          // This is because we know it will be a char.
          roflcopter(char x)
          {
               std::cout << x << " is indubitably a character!" << std::endl;
          }
};

int main()
{
     roflcopter<int> obj_1(7);
     roflcopter<float> obj_2(1.618);
     roflcopter<char> obj_3('T');

     return 0;
}
