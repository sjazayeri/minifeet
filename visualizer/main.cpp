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

	// initial game logic and read zero cycle data
	if(!initGame(&globData))
	{
		printf( "Failed to initialize Game!\n" );
		return -1;
	}

	
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
			// reading positions and states from logic
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
			clog << "handle state" << endl;
			
			// Sending new data to players and ball
			setNewData(&globData);
			clog << "setNewData" << endl;

		}

		// Moving movable objects!
		for (int i = 0; i < globData.movingObjs.size(); i++)
			globData.movingObjs[i]->move();
		clog << "move" << endl;

		// Clear Screen
		SDL_SetRenderDrawColor( globData.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear(globData.gRenderer);

		// Rendering Green Field
		globData.field->render(0,0);
		
		clog << "start renderAll" << endl;
		// Rendering all other elements on gRenderer
		renderAll(&globData);
		clog << "renderAll" << endl;

		// Setting graphical cycle number
		globData.cycleNum++;
		if (globData.cycleNum == 20000) {
			globData.cycleNum = 0;
			clog << "Graphical Cycle Counter Reset" << endl;
		}

		//Update screen
		SDL_RenderPresent( globData.gRenderer );

		// stoping timer
		loopEndTime = SDL_GetTicks();

		// calculating delay
		// loopLen = loopEndTime - loopStartTime;
		// if (loopLen < 0) {
		// 	// if hardware can not handle programm
		// 	cerr << "FATAL ERROR" << endl;
		// 	globData.quitFlag = true;
		// }
		// else {
			SDL_Delay( globData.cycleLen );
		// }
	}

	//Free resources and close SDL
	close(&globData);

	return 0;
}