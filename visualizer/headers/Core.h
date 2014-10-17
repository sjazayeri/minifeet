#ifndef CORE_
#define CORE_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "Player.h"
#include "Ball.h"


//Starts up SDL and creates window

//Loads media
bool loadMedia();
//Frees media and shuts down SDL
void close();
// //The window we'll be rendering to
// SDL_Window* gWindow = NULL;

// //The window renderer
// SDL_Renderer* gRenderer = NULL;

#endif