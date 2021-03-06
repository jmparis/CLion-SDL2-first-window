/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//  Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <cstdio>

//  Screen dimension constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

int main( int, char* [] )
{
    //  The window we'll be rendering to
    SDL_Window*     window          =   nullptr;

    //  The surface contained by the window
    SDL_Surface*    screenSurface;

    //  Initialize SDL
    if  ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window =    SDL_CreateWindow(
                    "SDL Tutorial"        ,
                    SDL_WINDOWPOS_UNDEFINED ,
                    SDL_WINDOWPOS_UNDEFINED ,
                    SCREEN_WIDTH                ,
                    SCREEN_HEIGHT               ,
                    SDL_WINDOW_SHOWN
                    );

        if  ( window == nullptr )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //  Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //  Fill the surface white
            SDL_FillRect(
                    screenSurface   ,
                    nullptr        ,
                    SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF )
                    );

            //  Update the surface
            SDL_UpdateWindowSurface( window );

            //  Wait two seconds
            SDL_Delay( 2000 );
        }
    }

    //  Destroy window
    SDL_DestroyWindow( window );

    //  Quit SDL subsystems
    SDLNet_Quit();
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}