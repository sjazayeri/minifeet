// AMiGH & mehdithreem Copyright(c)

#include "./headers/Core.h"
#include <ctime>
using namespace std;

int main( int argc, char* args[] )
{
	SharedData globData;

	// ---> init game

	// ---> set zero cycle data
	// 		getting initial pos from logic

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
	
	//For X Button
	SDL_Event e;
	
	//Setting start time for further use
	globData.startTime = time(NULL);
	//Main Loop
	while( !globData.quitFlag )
	{
		//Handle X Button event
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				globData.quitFlag = true;
			}
		}

		// if ( globData.cycleNum % (globData.cycle))
				// ---> get data from logic
				//		only get them, DO NOT parse them to players, ball, etc

				// ---> check for status
				// ---> handle status events
				//		if needed, terminate program
				//		or render goal screen

				// ---> send new data to players, ball and wherever they need them

		// ---> calling move methods for all movingObjs

		// //Clear screen
		// SDL_SetRenderDrawColor( globData.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		// SDL_RenderClear(globData.gRenderer);

		// //Render current frame
		// SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ];
		// gSpriteSheetTexture.render( ( SCREEN_WIDTH - currentClip->w ) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip );
		// bolan[j/6].render(x,y);

		//Update screen
		SDL_RenderPresent( globData.gRenderer );

		// //Go to next frame
		// ++frame;
		// ++j;
		// x++;
		// y+=2;
		// if ( x>200)
		// 	x=0;
		// //Cycle animation
		// if( j / 6 >= 2 )
		// {
		// 	j=0;
		// }
		// if( frame / 4 >= WALKING_ANIMATION_FRAMES )
		// {
		// 	frame = 0;
		// }
	}

	//Free resources and close SDL
	close();

	return 0;
}