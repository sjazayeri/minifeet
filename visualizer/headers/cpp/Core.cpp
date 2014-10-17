#include "../Core.h"

// LTexture gSpriteSheetTexture;
// LTexture bolan[3];


bool loadMedia()
{
	//Loading success flag
	bool success = true;
	LTexture soccerField;
	//Load sprite sheet texture
	if( !soccerField.loadFromFile( "/home/amirhosein/MiniFeet/minifeet/visualizer/assets/field1.jpg" ) )
	{
		printf( "Failed to load field!\n" );
		success = false;
	}
	else
	{	
		soccerField.render(0,0);
	}
	
	return success;
}

void close()
{
	
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

// bool inti_game()
// {

// }