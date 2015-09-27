#include <iostream>
#include "Father.h"
#include "Daughter.h"

// Base class


//---- Constructors ----//
Father::Father()
{
    dad_secret_number = 111;
}

Father::Father(int value)
:dad_number(value)
{
    dad_secret_number = 111;
}

//---- End Constructors ----//


//---- Mod functions Start----//
void Father::sayStuff()
{
    std::cout << "Why is time SO SHORT!!! >_>\n";
}

void Father::our_secret(int value)
{
    var_our_secret = value;
}

void Father::set_secret(int value)
{
    dad_secret_number = value;
}

void Father::print_our_secret()
{
    std::cout << "Our secret is: " << var_our_secret << std::endl;
}

void Father::print_dad_secret()
{
    std::cout<< "Dad's secret is: " << dad_secret_number << std:: endl;
    yell_loudly();
}

void Father::yell_loudly()
{
    if(dad_secret_number == 0)
        std::cout <<"AHHHHHHHHHHH I DISLIKE ZERO D:<\n";
}

//---- Mod functions End ----//
