/*
*    Written By: Sahle A. Alturaigi (Nomad)
*    Date:          Jan. 2nd, 2013
*    Descript:    This will be my first programmed game with the SDL library. This program will be
*                      a remake of pong.
*
*/

#include "SDL/SDL.h"
#include <iostream>

using namespace std;

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_DEPTH  =  32;

int main(int argc, char *argv[])
{
     /// Stop here
     SDL_Surface *screen;
     Uint8       *p;
     int         x = 10; // x coordinate of our pixel
     int         y = 20; // y coordinate of our pixel

     // Initialize SDL
     SDL_Init(SDL_INIT_VIDEO);

     // Initialize the screen / window
     screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, SDL_SWSURFACE);

     // Make p point to the place we want to draw the pixel
     p = (Uint8 *)screen->pixels + y * screen->pitch + x * screen->format->BytesPerPixel;

     // Draw the pixel!
     *p=0xff;

     // update the screen (aka double buffering)
     SDL_Flip(screen);

     while(true);
     /// Please delete all of the top when done. The above code is just for testing
}

