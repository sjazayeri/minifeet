#include "../Core.h"

// LTexture gSpriteSheetTexture;
// LTexture bolan[3];

bool init(SharedData* gData)
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gData->gWindow = SDL_CreateWindow( "MiniFeet", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gData->gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gData->gRenderer = SDL_CreateRenderer( gData->gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gData->gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gData->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia(SharedData* gData)
{
	//Loading success flag
	bool success = true;
	LTexture soccerField(gData);


	LTexture* temp = new LTexture(gData);
	//loading png file of bolan
	if( !temp->loadFromFile("./assets/characters/bolan/b1-front-m.png"))
	{
		printf( "Failed to load b1-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("./assets/characters/bolan/b1-front-r.png"))
	{
		printf( "Failed to load b1-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("./assets/characters/bolan/b1-front-l.png"))
	{
		printf( "Failed to load b1-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("./assets/characters/bolan/b1-back-m.png"))
	{
		printf( "Failed to load b1-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("./assets/characters/bolan/b1-back-r.png"))
	{
		printf( "Failed to load b1-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("./assets/characters/bolan/b1-back-l.png"))
	{
		printf( "Failed to load b1-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	
	//loading png file of bolan 2
	temp = new LTexture(gData);
		if( !temp->loadFromFile("./assets/characters/bolan/b2-front-m.png"))
	{
		printf( "Failed to load b2-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("./assets/characters/bolan/b2-front-r.png"))
	{
		printf( "Failed to load b2-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("./assets/characters/bolan/b2-front-l.png"))
	{
		printf( "Failed to load b2-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("./assets/characters/bolan/b2-back-m.png"))
	{
		printf( "Failed to load b2-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("./assets/characters/bolan/b2-back-r.png"))
	{
		printf( "Failed to load b2-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("./assets/characters/bolan/b2-back-l.png"))
	{
		printf( "Failed to load b2-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}


	//Load sprite sheet texture
	if( !soccerField.loadFromFile( "./assets/field1.jpg" ) )
	{
		printf( "Failed to load field!\n" );
		success = false;
	}
	else
	{	
		soccerField.render(0,0);
		gData->bolanRed[3]->render(0,0);
		gData->bolanRed[1]->render(35,0);

	}
	
	return success;
}

void close()
{
	
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

// bool init_game()
// {

// }