#ifndef CORE_
#define CORE_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stringstream>
#include <string>
#include "Player.h"
#include "Ball.h"

//Starts up SDL and creates window
bool init();
//Loads media
bool loadMedia();
//Frees media and shuts down SDL
void close();
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;



//Texture wrapper class
class LTexture
{
public:
		//Initializes variables
	LTexture();

		//Deallocates memory
	~LTexture();
		//Loads image at specified path
	bool loadFromFile( std::string path );
		//Deallocates texture
	void free();
		//Set color modulation
	void setColor( Uint8 red, Uint8 green, Uint8 blue );
		//Set blending
	void setBlendMode( SDL_BlendMode blending );
		//Set alpha modulation
	void setAlpha( Uint8 alpha );
		//Renders texture at given point
	void render( int x, int y, SDL_Rect* clip = NULL );
		//Gets image dimensions
	int getWidth();
	int getHeight();

private:
		//The actual hardware texture
	SDL_Texture* mTexture;

		//Image dimensions
	int mWidth;
	int mHeight;
};

#endif