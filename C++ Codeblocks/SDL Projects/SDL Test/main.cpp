/*
*    Author: LazyFoo productions.
*
*    Description: This will serve as a reference for how to start up SDL. I will post and add vital and rudimentary info of SDL
*                       on this program.
*
*/

#include "SDL/SDL.h"
#include <iostream>

int main(int argc, char* args[])
{

     // The images
     SDL_Surface* hello = NULL;
     SDL_Surface* screen = NULL;

     // Start SDL
     SDL_Init(SDL_INIT_EVERYTHING);

     // Setup screen, much like initwindow from graphics.h
     screen = SDL_SetVideoMode(640, 448, 32, SDL_SWSURFACE);

     // Load Image. The functions returns NULL if the file is opened unsuccessfully.
     hello = SDL_LoadBMP("yellowhead field.bmp");

     // Apply image to screen. The first argument is the source surface
     // The second argument...
     // The third argument is the destination surface.
     // The fourth argument...
     SDL_BlitSurface(hello, NULL, screen, NULL);

     // Update Screen. Otherwise known as double buffering
     SDL_Flip(screen);

     // Pause. This will put the program to sleep for 2000 milliseconds.
     SDL_Delay(2000);

     // Free the loaded image. You must remove the image from the Heap memory
     // like this--not with the delete operand. As for the screen surface, SDL_quit takes
     // care of that.
     SDL_FreeSurface(hello);

     // Quit SDL
     SDL_Quit();

     return 0;
}

