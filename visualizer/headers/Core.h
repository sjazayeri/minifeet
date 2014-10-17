#ifndef CORE_
#define CORE_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"
#include "Ball.h"

typedef struct _SharedData
{
	// main window of game
	SDL_Window* gWindow = NULL;

	//The gWindow renderer
	SDL_Renderer* gRenderer = NULL;

	// When first cycle runs
	time_t startTime;

	// Storages the number of next cycle
	// use this to calculate when you have to change moods
	unsigned int cycleNum = 1;
	// AMiGH: Remmember we should reset it, When? i don't know
	// ps: i do NOT go to any english class :))

	const unsigned int cycleLen = 20; //miliseconds
	const unsigned int logicCycleLen = 100; // miliseconds
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