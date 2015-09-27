/*
*
*    Written By: Sahle A. Alturaigi (Nomad)
*    Date:          July 13th, 2012
*    Descript:     Optimized surface loading and blitting
*
*/

#include "SDL/SDL.h"
#include <string>

// The atrributes of the screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
// How many bits per pixel. This indicates 32 bit.
const int SCREEN_BPP = 32;

// The surfaces that will be used.
SDL_Surface* message = NULL;
SDL_Surface* background = NULL;
SDL_Surface* screen = NULL;

// This function will load an image, then return a pointer to the
// optimized version of the loaded image.
// The argument "filename" is the path of the image to be loaded.
// "optimizedImage" is the surface that is going to be used.
SDL_Surface* load_image (std::string filename)
{
    // Temporary storage for the image that's loaded.
    SDL_Surface* loadedImage = NULL;

    // Placeholder for the optimized image.
    SDL_Surface* optimizedImage = NULL;

    // Load the image
    /*
         This should NOT be used immediately. The bitmap for this will
         be at 24-bit and our screen is at 32-bit. Having SDL convert on the fly
         will slow down the program significantly.
    */
    loadedImage = SDL_LoadBMP(filename.c_str());

    // If nothing went wrong in loading the image.
    if(loadedImage != NULL)
    {
        // Create an optimized image
        optimizedImage = SDL_DisplayFormat(loadedImage);

        // Frees the old image, but does not delete it.
        SDL_FreeSurface(loadedImage);

        return optimizedImage;
    }

    return NULL;
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    // Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    // Gives the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    // Blit the surface
    SDL_BlitSurface (source, NULL, destination, &offset);
}

int main(int argc, char* args[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return 1;

    //Set up the screen
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    // If there was an error in setting up the screen
    if(screen == NULL)
        return 1;

    // Set the window caption
    SDL_WM_SetCaption("Hello World", "Lalala");

    // Load the images
    message = load_image("pictures//purp.bmp");
    background = load_image("pictures//background.bmp");

    // Apply the background to the screen
    apply_surface(0, 0, background, screen);
    apply_surface(320, 0, background, screen);
    apply_surface(0, 240, background, screen);
    apply_surface(320, 240, background, screen);
    apply_surface(180, 140, message, screen);
    // A less efficient way to do the above apply_surface();
    //apply_surface(SCREEN_WIDTH/4, SCREEN_HEIGHT/4, message, screen);

    // Update screen
    if(SDL_Flip(screen) == -1)
        return 1;

    SDL_Delay(2000);

    // Free the surface
    SDL_FreeSurface(message);
    SDL_FreeSurface(background);

    // This apparently takes care of the screen surface and we don't need to free it manually.
    SDL_Quit();

    return 0;
}

