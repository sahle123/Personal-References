#include <iostream>
#include "Father.h" // Still need to include Father class in Daughter implementation file.
#include "Daughter.h"

// Derived class.

Daughter::Daughter(int value)
:daughter_number(value)
{
}

void Daughter::otherStuff()
{
    std::cout << "Time is not THAT short...\n";
}

void Daughter::set_daughter_number(int value)
{
    daughter_number = value;
}
