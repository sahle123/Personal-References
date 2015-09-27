/*
*   Author: Sahle "Nomad" Alturaigi
*   Date: Nov. 27th, 2012
*
*   Implementation file for Mastermind header file.
*/

#include "Mastermind_class.h"
#include "peg_class.h"
#include "ClearScreen.h"
#include <stdio.h>
#include <cstdlib> // For rand function.

// Constructors
// By default the game has 4 positions
MM_game::MM_game()
{
    handler = new _peg[4];
    places = 4;
    is_good = true;
    guesses_remaining = 12;
}

MM_game::MM_game(short int _places)
{
    places = _places;
    handler = new _peg[places];
    is_good = true;
    guesses_remaining = 12;
}

MM_game::~MM_game()
{
    delete[]handler;
    handler = NULL;
}

int MM_game::no_of_places()
{
    return places;
}

int MM_game::get_color(int index)
{
    return handler[index].color;
}

int MM_game::get_position(int index)
{
    return handler[index].position;
}
int MM_game::get_guesses_remaining()
{
    return guesses_remaining;
}

bool MM_game::get_is_good()
{
    return is_good;
}
void MM_game::players_guess()
{
      char temp_position[4];
    std::cout << "Make your guess!\nPlease enter 4 colors of the following 6"
                    << " colors (R, B, G, Y, W, O):\n";
    std::cin >> temp_position[0] >> temp_position[1] >> temp_position[2]
                 >> temp_position[3];
    for(int i = 0; i < places; ++i)
    {
        switch(temp_position[i])
        {
            case 'R':
                handler[i].color = 0;
                break;
            case 'r':
                handler[i].color = 0;
                break;
            case 'B':
                handler[i].color = 1;
                break;
            case 'b':
                handler[i].color = 1;
                break;
            case 'G':
                handler[i].color = 2;
                break;
            case 'g':
                handler[i].color = 2;
                break;
            case 'Y':
                handler[i].color = 3;
                break;
            case 'y':
                handler[i].color = 3;
                break;
            case 'W':
                handler[i].color = 4;
                break;
            case 'w':
                handler[i].color = 4;
                break;
            case 'O':
                handler[i].color = 5;
                break;
            case 'o':
                handler[i].color = 5;
                break;
            default:
            std::cout << "Program did not initialize correctly. Incorrect input.\n";
            i = places; // To quit for loop.
            is_good = false;
            continue;
        }
        handler[i].position = (i + 1);
    }
}

void MM_game::set_all()
{
    for(int i = 0; i < places; ++i)
    {
        handler[i].color = (rand() % 6);
        handler[i].position = (i + 1);
    }
     std::cout << "I made my code. Think you can crack it? >;)\n" << std::endl;
}

void MM_game::set_by_user()
{
    /// Key: R = 0; B = 1; G = 2;  Y = 3; W = 4; O = 5.
    char temp_position[4];
    std::cout << "Please enter 4 colors of the following 6 "
                    << "colors (R, B, G, Y, W, O):\n";
    std::cin >> temp_position[0] >> temp_position[1] >> temp_position[2]
                 >> temp_position[3];
    for(int i = 0; i < places; ++i)
    {
        switch(temp_position[i])
        {
            case 'R':
                handler[i].color = 0;
                break;
            case 'r':
                handler[i].color = 0;
                break;
            case 'B':
                handler[i].color = 1;
                break;
            case 'b':
                handler[i].color = 1;
                break;
            case 'G':
                handler[i].color = 2;
                break;
            case 'g':
                handler[i].color = 2;
                break;
            case 'Y':
                handler[i].color = 3;
                break;
            case 'y':
                handler[i].color = 3;
                break;
            case 'W':
                handler[i].color = 4;
                break;
            case 'w':
                handler[i].color = 4;
                break;
            case 'O':
                handler[i].color = 5;
                break;
            case 'o':
                handler[i].color = 5;
                break;
            default:
            std::cout << "Program did not initialize correctly. Incorrect input.\n";
            i = places; // To quit for loop.
            is_good = false;
            continue;
        }
        handler[i].position = (i + 1);
    }
    if(is_good != false)
        ClearScreen();
        std::cout << "Program initialized properly." << std::endl;
}

void MM_game::print_code()
{
        /// Key: R = 0; B = 1; G = 2;  Y = 3; W = 4; O = 5.
        for(int i = 0; i < places; ++i)
        {
            switch(handler[i].color)
            {
                case 0:
                    std::cout << "R ";
                    //char_array[i] = 'R';
                    break;
                case 1:
                    std::cout << "B ";
                    //char_array[i] = 'B';
                    break;
                case 2:
                    std::cout << "G ";
                    //char_array[i] = 'G';
                    break;
                case 3:
                    std::cout << "Y ";
                    //char_array[i] = 'Y';
                    break;
                case 4:
                    std::cout << "W ";
                    //char_array[i] = 'W';
                    break;
                case 5:
                    std::cout << "O ";
                    //char_array[i] = 'O'
                    break;
            }
        }
        puts(""); // Break line.
}

// set_color()
void MM_game::set_color(int index, int color)
{
    handler[index].color = color;
}
/*
void MM_game::close_mastermind()
{
    delete[]handler;
    handler = NULL;
    // std::cout << "All dynamic variables deallocated." << std::endl;
}
*/
