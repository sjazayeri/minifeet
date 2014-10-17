#ifndef CORE_
#define CORE_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "Player.h"
#include "Ball.h"

typedef struct _SharedData
{
	// main window of game
	SDL_Window* gWindow = NULL;

	//The gWindow renderer
	SDL_Renderer* gRenderer = NULL;
} SharedData;


//Starts up SDL and creates window
bool init(SharedData* globalData);
//Loads media
bool loadMedia(SharedData* globalData);
//Frees media and shuts down SDL
void close();


// //The window we'll be rendering to
// SDL_Window* gWindow = NULL;

// //The window renderer
// SDL_Renderer* gRenderer = NULL;

#endif