/*
*    Written By: Sahle A. Alturaigi (Nomad)
*    Date:          July 26th, 2012
*    Descript:     How to setup new SDL extension libraries.
*                      All extension libraries have the following: Header files; lib files and *.dll files.
*                      Basically, you just need to extract these to respective folders in the SDL folder.
*
*                      If you check the compiler settings, in other linker options, I added the SDL library and SDL image library.
*                      If a new extended library is added, simply type in -l followed by the name of the library (header?) next to it.
*
*                      DOES NOT WORK. NEED TO LEARN HOW TO MAKE ANOTHER I/O WINDOW.
*
*/

#include <iostream>
#include <string>
#include "SDL/SDL.h"
#include "SDL_image.h"

// Global Constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// Surfaces that will be used.
SDL_Surface* message = NULL;
SDL_Surface* background = NULL;
SDL_Surface* screen = NULL;

// Prototypes:
SDL_Surface* load_image(std::string filename);
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);
std::string get_file_info();

int main(int argc, char* args[])
{
     std::string bg_pic;
     std::string fg_pic;

      // Load the images
     std::cout << "For background pic... ";
     bg_pic = get_file_info();
     std::cout << "For other pic... ";
     fg_pic = get_file_info();

     if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
          return 1;

     // Set up the screen
     screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

     // If there was an error in setting up the screen
     if(screen == NULL)
          return 1;

     // Set the window caption.
     SDL_WM_SetCaption("Extension Libraries.", NULL);

     // Setting images to screen.
     message = load_image(fg_pic);
     background = load_image(bg_pic);

     // Apply the background to the screen
     apply_surface(0, 0, background, screen);
     apply_surface(320, 0, background, screen);
     apply_surface(0, 240, background, screen);
     apply_surface(320, 240, background, screen);
     apply_surface(180, 140, message, screen);

     // Update screen
     if(SDL_Flip(screen) == -1)
          return 1;

     SDL_Delay(2000);

     // Free the surface
     SDL_FreeSurface(message);
     SDL_FreeSurface(background);

     SDL_Quit();

     return 0;
}

SDL_Surface* load_image(std::string filename)
{
     // The image that will be loaded.
     SDL_Surface* loadedImage = NULL;

     // The optimized image that will be used in the program.
     SDL_Surface* optimizedImage = NULL;

     // Load the image using SDL_image.
     loadedImage = IMG_Load(filename.c_str());

     if(loadedImage != NULL)
     {
          // Create the optimized image.
          optimizedImage = SDL_DisplayFormat(loadedImage);

          // Free old image space.
          SDL_FreeSurface(loadedImage);
     }

     return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
     // Make a temporary rectangle to hold the offsets.
     SDL_Rect offset;

     // Gives the offsets to the rectangle
     offset.x = x;
     offset.y = y;

     // Blit the surface
     SDL_BlitSurface(source, NULL, destination, &offset);
}

std::string get_file_info()
{
     std::string pic;
     std::string file_extension = ".bmp";
     int i, j;

     std::cout << "Please input your picture" << std::endl;
     std::cin >> pic;

     i = strlen(pic.c_str());
     j = 0;

     // Check if the file inputed ends with .bmp. If not, it will add it.
     for(i = i - 4; i < strlen(pic.c_str()); ++i)
     {
          if(pic[i] != file_extension[j])
          {
               pic = pic + file_extension;
               i = strlen(pic.c_str());
          }
          j++;
     }

     /*
     std::cout << "Now for a regular picture :)" << std::endl;
     std::cin >> fg_pic;

     i = strlen(fg_pic.c_str());
     j = 0;

     for(i = i - 4; i < strlen(fg_pic.c_str()); ++i)
     {
          if(fg_pic[i] != file_extension[j])
          {
               fg_pic = fg_pic + file_extension;
               i = strlen(fg_pic.c_str());
          }
          j++;
     }*/
}
