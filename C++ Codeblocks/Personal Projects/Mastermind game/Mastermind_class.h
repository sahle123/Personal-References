#ifndef MASTERMIND_CLASS_H_INCLUDED
#define MASTERMIND_CLASS_H_INCLUDED
/*
*   Author: Sahle "Nomad" Alturaigi
*   Date: Nov. 27th 2012
*
*   Header file for the Mastermind main file. This will hold all the functions and variables needed for the class.
*/

#include<iostream>
#include "peg_class.h"

class MM_game {
    private:
        short int places;
        _peg *handler;
        bool is_good; // If false, program should terminate.
        int guesses_remaining;

    public:
        // Constructors
        MM_game();
        MM_game(short int _places);

        // Destructor
        ~MM_game();
        /// Should NOT have a copy constructor.

        // Return values
        int no_of_places();
        int get_color(int index);
        int get_position(int index);
        int get_guesses_remaining();
        bool get_is_good();

        // Modifiers
        void players_guess();           // Function for player's guess
        void set_all();                 // Randomizer
        void set_by_user();             // User inputs his code.
        void print_code();              // Prints the answer code.
        void set_color(int index, int color);   // Manually sets the color.
        //void close_mastermind(); // Deallocate all dynamic variables.
};


/// Old code.
/*
struct correctness{
    bool correct_place;
    bool correct_color;
};
class cls_peg{
    private:
        int color;
        int position;
        correctness peg;

    public:
        // Constructors
        cls_peg();
        cls_peg(int color);
        cls_peg(int color, int position);

        // Modifiers
        int get_color(); // Returns color
        int get_pos();   // Returns position of peg.
        void set_color(int color_param);
        void set_pos(int position_param);
        void set_correctness(bool place, bool color);
};
*/

#endif // MASTERMIND_CLASS_H_INCLUDED
