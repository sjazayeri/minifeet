// AMiGH & MehDiThreeM Copyright(c)2013-2014

#include "./headers/Core.h"
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

int main( int argc, char* args[] )
{
	SharedData globData;

	//Init Graphics: Start up SDL and create window
	if(!init(&globData))
	{
		printf( "Failed to initialize!\n" );
		return -1;
	}

	//Load media
	if( !loadMedia(&globData) )
	{
		printf( "Failed to load media!\n" );
		return -1;
	}

	if(!initGame(&globData))
	{
		printf( "Failed to initialize Game!\n" );
		return -1;
	}

	// ---> set zero cycle data
	// 		getting initial pos from logic
	
	//For X Button
	SDL_Event e;

	// For calculating loop duration
	Uint32 loopStartTime, loopEndTime, loopLen;
	
	//Setting start time for further use
	globData.startTime = SDL_GetTicks();

	//Main Loop
	while( !globData.quitFlag )
	{
		// starting timer
		loopStartTime = SDL_GetTicks();

		//Handle X Button event
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				globData.quitFlag = true;
			}
		}

		if ( globData.cycleNum % (globData.logicCycleLen/globData.cycleLen) == 0 ) 
		{
			// ---> get data from logic
			//		only get them, DO NOT parse them to players, ball, etc
			if( !getInputs(&globData))
			{
				printf( "Failed to get postions or state!\n" );
				return -1;
			}

			// ---> check for state
				// ---> handle status events
				//		if needed, terminate program
				//		or render goal screen
			handleState(globData.gameState);
			
			// Sending new data to players and ball
			setNewData(&globData);
		}

		// ---> calling move methods for all movingObjs

		// ---> Clear screen and setting render color
		//		probably this way:
		SDL_SetRenderDrawColor( globData.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear(globData.gRenderer);

		// ---> render field
		
		// ---> render players and balls in this order
		//		priority1: less Y renders first
		//		priority2: less X renders first
		//		(optional)priority3: ball
		//		(optional)priority4: player whom is his face is NOT shown
		//		(optional)priority5: Red team

		//Update screen
		// globData.field->render(0,0);
		SDL_RenderPresent( globData.gRenderer );

		// stoping timer
		loopEndTime = SDL_GetTicks();

		// calculating delay
		loopLen = loopEndTime - loopStartTime;
		if (loopLen < 0) {
			// if hardware can not handle programm
			cerr << "FATAL ERROR" << endl;
			globData.quitFlag = true;
		}
		else {
			SDL_Delay( globData.cycleLen - loopLen );
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}