/*
*   Author: Sahle "Nomad" Alturaigi .
*   Date: Nov. 27th, 2012
*
*   Function of program: Program the emulates the game Mastermind. This program, overtime, will be updated.
*
*   Key: R = 0; B = 1; G = 2; Y = 3; W = 4; O = 5;
*
*/

/** Notes:
        -Randomizer needs to be improved.
        -Number of color needs to be set to color.
        -Improve interface
        -Clean up code
        -Make checkpegs use dynamic memory.
**/

#include <iostream>
#include <cstdlib>
#include <conio.h>
//#include "nomad_array.h"
#include "Mastermind_class.h"
using namespace std;

// This will operate the interface of the console.
void interface(MM_game &main_handler, MM_game &player);
void check_pegs(MM_game &main_handler, MM_game &player);
void choose_game();

int main()
{
    choose_game();
    getch();

    return EXIT_SUCCESS;
}

void interface(MM_game &main_handler, MM_game &player)
{
    int guesses_remaining = 12;
    int places = main_handler.no_of_places();
    bool is_right = false;

    while(!is_right)
    {
        // Check if user put valid inputs.
        if(!player.get_is_good())
        {
            std::cout <<"You must've put an invalid value somewhere. Closing program.\n";
            return;
        }
        is_right = true;

        // Checking if all pegs are correct.
        for(int i = 0; i < places; ++i)
        {
            if(player.get_color(i) != main_handler.get_color(i))
                is_right = false;
        }

        // Provide feedback to player.
        check_pegs(main_handler, player);

        if(guesses_remaining <= 0)
        {
            std::cout << "Out of guesses, better luck next time!\n";
            std::cout <<"My code was: ";
            main_handler.print_code();
            std::cout << "\n";
            return;
        }
        else if(!is_right)
        {
            std::cout << "Keep trying. You have " << guesses_remaining
                            <<" guesses left.\n" << std::endl;
            --guesses_remaining;
            player.players_guess();
        }
        else
            std::cout << "You did it!!!" << std::endl;
    }
}

void check_pegs(MM_game &main_handler, MM_game &player)
{
    int places = main_handler.no_of_places();
    int correct_pos_col = 0;
    int correct_col = 0;
    //int temp_array[4]; /// Make Dynamic later.
    int *temp_array;
    short int i = 0;
    short int j = 0;

    // Fill up temp array.
    temp_array = new int[places];
    for(i = 0; i < places; ++i)
    {
        temp_array[i] = main_handler.get_color(i);
    }

    for(i = 0; i < places; ++i)
    {
        if(temp_array[i] == player.get_color(i))
        {
            ++correct_pos_col;
            temp_array[i] = 7;
            player.set_color(i, 8);
        }
    }

    for(j = 0; j < places; ++j)
    {
        for(i = 0; i < places; ++i)
        {
            if(temp_array[j] == player.get_color(i))
            {
                ++correct_col;
                temp_array[j] = 7;
                player.set_color(i, 8);
            }
        }
    }

    delete[]temp_array;
    temp_array = NULL;
/*
    for(i = 0; i < places; ++i)
    {
        if(main_handler.get_color(i) == player.get_color(i))
        {
            ++correct_pos_col;
        }
    }
*/

    // Code does not work for doubles. Refactored code above.
    /*
    int correct_color_and_position = 0;
    int correct_color = 0;
    int places = main_handler.no_of_places();
    int i, j;

    for(i = 0; i < places; ++i)
    {
        if(main_handler.get_color(i) == player.get_color(i))
        {
            ++correct_color_and_position;
        }
    }

    for(i = 0; i < places; ++i)
    {
        for(j = 0; j < places; ++j)
        {
            if(main_handler.get_color(j) == player.get_color(i))
            {
                ++correct_color;
                j = places;
            }
        }
    }
    // Balance out correct_color from counting over colors in right positions.
    correct_col -= correct_pos_col;
    */


    std::cout << "          "<<correct_pos_col << " color(s) are/is in the right position"
                    << " and are/is the right color." << std::endl;
    std::cout << "          "<<correct_col <<" are/is the right color, wrong position.\n";
}

void choose_game()
{
    int ctrl_var;
    // Initialize the game.
    MM_game main_handler;
    MM_game player;
    // End initialization.

    // Prompt for 1 or 2 player game.
    std::cout <<"Hi! Is this going to be a 1 or 2 player game? ";
    std::cin >> ctrl_var;
    switch(ctrl_var)
    {
        case 1:
            main_handler.set_all();
            player.players_guess();
            break;
        case 2:
            main_handler.set_by_user();
            player.players_guess();
            break;
        default:
            std::cout << "Invalid input. Quiting program." << std::endl;
            return;
    }

    interface(main_handler, player);

    // Close game properly.
    //main_handler.close_mastermind();
    //player.close_mastermind();
}
