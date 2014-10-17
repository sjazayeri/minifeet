#include "./headers/Core.h"
using namespace std;
//The window we'll be rendering to

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if(!init())
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;
			
			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				// //Clear screen
				// SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				// SDL_RenderClear(gRenderer);

				// //Render current frame
				// SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ];
				// gSpriteSheetTexture.render( ( SCREEN_WIDTH - currentClip->w ) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip );
				// bolan[j/6].render(x,y);

				//Update screen
				SDL_RenderPresent( gRenderer );

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
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}