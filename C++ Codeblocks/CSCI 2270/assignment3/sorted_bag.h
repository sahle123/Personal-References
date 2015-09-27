/*
 Assignment 3 homework for CSCI 2270.

     Author: Sahle A. Alturaigi
     Data: 03-27-12

     CONDITIONS.

• Constructor
     No conditions.
• Copy constructor
     Pre: Must the input must be of type sorted_bag.
     post: A new sorted_bag with all the inputs of the inputed sorted_bag is created.
• Destructor
     No conditions.
• insert_item(const Item& item)
     Pre: The item must be of the same datatype of the sorted_bag.
     post: the value inputed is stored in the bag.
• remove_item(const Item& item)
     Pre: The item must be of the same datatype of the sorted_bag.
     post: The value inputed is completely removed from the bag.
• find_copies(const Item& item)
     Pre: The item must be of the same datatype of the sorted_bag.
     post: Outputs the number of occureneces the inputed item was found in the sorted_bag.

• Function overloads = and += operators
• Friend function overloads == and << operators
*/

#ifndef SORTED_BAG_H_INCLUDED //<--- This is known as a macro guard
#define SORTED_BAG_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<list>
using namespace std;

// For overloading friend function operand: <<
//-----
template<class Item>
class sorted_bag;

template<class Item>
std::ostream& operator << (std::ostream& outs, const sorted_bag<Item>& item);
//-----

template<class Item>
class sorted_bag {
    public:
        typedef Item value_type;

        // Constructor
        sorted_bag();

        // Copy Constructor
        sorted_bag(const sorted_bag<Item>& cSource);
        // Destructor
        ~sorted_bag() {};

        // Mod Functions
        void insert_item(const Item& item);
        void remove_item(const Item& item);
        void find_copies(const Item& item);

        // Overloaded operands: = and +=.
        sorted_bag<Item>& operator = (const sorted_bag<Item> &cSource);
        sorted_bag<Item>& operator += (const sorted_bag<Item> &cSource);

        // Overloaded friend functions: == and << (check << and == remains)
        friend bool operator == (const sorted_bag<Item>& obj1, const sorted_bag<Item>& obj2)
        {
            typename std::list<Item>::const_iterator j;
            typename std::list<Item>::const_iterator i;

            if(obj1.bag.size() == obj2.bag.size())
            {
                for(i = obj1.bag.begin(), j = obj2.bag.begin(); i != obj1.bag.end(), j != obj2.bag.end(); ++i, ++j)
                {
                    if(*i != *j)
                    {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        friend std::ostream& operator << (std::ostream& outs, const sorted_bag<Item> & item)
        {
            typename std::list<Item>::const_iterator i;
            for(i = item.bag.begin(); i != item.bag.end(); ++i)
            {
                outs << *i << " ";
            }
            return outs;
        }

    private:
        list<Item> bag;
};  // END of sorted_bag

//-----------------------------------------------------------------------------
// Constructor
template<class Item>
sorted_bag<Item>::sorted_bag() {}
//-----------------------------------------------------------------------------
// Copy Constructor
template<class Item>
sorted_bag<Item>::sorted_bag(const sorted_bag<Item>& cSource)
{
     typename list<Item>::const_iterator i;

     for(i = cSource.bag.begin(); i !=cSource.bag.end(); ++i)
     {
          bag.push_back(*i); // Check this
     }
}

//-----------------------------------------------------------------------------
// Mod Functions:
template<class Item>
void sorted_bag<Item>::insert_item(const Item& item)
{
     typename std::list<Item>::iterator i;

     if(bag.size() == 0)
     {
          bag.push_back(item);
          return;
     }
     for(i = bag.begin(); i !=bag.end(); ++i)
     {
          if(*i > item) // This will dereference to the object being pointed to by i. The ith object will be given.
          {
               bag.insert(i, item);
               return;
          }
     }

     bag.push_back(item);
}

template<class Item>
void sorted_bag<Item>::remove_item(const Item& item)
{
     bool check = false;
     typename std::list<Item>::iterator i;
     for(i = bag.begin(); i != bag.end(); ++i)
     {
          if(*i  == item)
          {
               bag.remove(item);
               check = true;
               return;
          }
     }
     if(check != true)
     {
          cout << "The specified item was not found in the list."
	     << " Nothing has been removed..." << endl;
     }
}

template<class Item>
void sorted_bag<Item>::find_copies(const Item& item)
{
     int counter = 0;
     typename std::list<Item>::iterator i;
     for(i = bag.begin(); i != bag.end(); ++i)
     {
          if(*i == item)
          {
               ++counter;
          }
     }
     cout << counter << endl;
}

//-----------------------------------------------------------------------------
// Overloaded operands:

template<class Item>
sorted_bag<Item>& sorted_bag<Item>::operator = (const sorted_bag<Item>& cSource)
{
          typename std::list<Item>::const_iterator i;
          bag.clear();

          if(cSource.bag.size() == 0)
          {
               bag.push_back(0);
          }
          else
          {
               for(i = cSource.bag.begin(); i != cSource.bag.end(); ++i)
               {
                    bag.push_back(*i);
               }
          }
          return *this;
}

template<class Item>
sorted_bag<Item>& sorted_bag<Item>::operator += (const sorted_bag<Item> &cSource)
{
     list<Item>temp;
     if(cSource.bag.size() == 0)
     {
          return *this;
     }

     temp = cSource.bag;
     bag.merge(temp);
     return *this;
}

#endif // SORTED_BAG_H_INCLUDED
