#include<iostream>
#include<cstdlib>
using namespace std;

template<class Item, class Item2>
Item function(Item a, Item2 b);

int main ()
{
     int a = 2;
     double b = 10;
     double c;

     c = function(a, b);
     cin.get();
     cout << c;

     return 0;
}

template<class Item, class Item2>
Item function(Item a, Item2 b)
{
     return (a + b);
}
