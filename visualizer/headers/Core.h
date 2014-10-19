#ifndef CORE_
#define CORE_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"
#include "Ball.h"
#include <vector>
#include <utility>

class Ball;
class Player;

typedef struct _SharedData
{
	// main window of game
	SDL_Window* gWindow = NULL;

	//The gWindow renderer
	SDL_Renderer* gRenderer = NULL;

	// When first cycle runs
	Uint32 startTime;

	// Storages the number of next cycle
	// use this to calculate when you have to change moods
	unsigned int cycleNum = 1;
	unsigned int logicCycleNum = 1;
	// AMiGH: Remmember we should reset it, When? i don't know
	// ps: i do NOT go to any english class :))

	const unsigned int cycleLen = 20;       //miliseconds
	const unsigned int logicCycleLen = 100; // miliseconds

	//Main loop flag
	bool quitFlag = false;

	//vector of playerPositons in pair format
	vector< pair<int,int> > playersPos;
	//ball position in pair format
	pair<int,int> ballPos;
	//game state in int
	int gameState;

	vector<MovingObj*> movingObjs;
	vector<LTexture*> bolanYellow;
	vector<LTexture*> bolanRed;
	LTexture* field;

} SharedData;


//Starts up SDL and creates window
bool init(SharedData* gData);
//Loads media
bool loadMedia(SharedData* gData);
//Frees media and shuts down SDL
void close();

bool getInputs(SharedData* gData);

void handleState(int state);

void setNewData(SharedData* gData);

bool initGame(SharedData* gData);

#endif