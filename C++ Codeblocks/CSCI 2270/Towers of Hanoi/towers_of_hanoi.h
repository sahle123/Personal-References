#ifndef TOWERS_OF_HANOI_H_INCLUDED
#define TOWERS_OF_HANOI_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <stack>

using namespace std;

class disk
{
public:
     disk(size_t init_size = 1) {size = init_size;} // Constructor
     size_t get_size( ) const {return size;}
private:
     size_t size;
};

class pin
{
public:
     pin(size_t init_disks = 0)    // Constructor
     {
          for (size_t i = init_disks; i > 0; --i)
          {
               disk *d = new disk(i);
               disks.push(d);
          }
     }
     void move(pin *p) // Moves top disk to the pin pointed to by p
     {
          assert(!disks.empty());
          if (!(p->disks).empty())
          {
               assert((disks.top())->get_size( ) < ((p->disks).top())->get_size());
          }
          (p->disks).push(disks.top());
          disks.pop();
     }
private:
    stack<disk *> disks;
};

#endif // TOWERS_OF_HANOI_H_INCLUDED
