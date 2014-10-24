#include "../Core.h"


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
				 //Initialize SDL_ttf 
				if( TTF_Init() == -1 ) 
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() ); 
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
	// LTexture soccerField(gData);
	LTexture* temp = new LTexture(gData);
	//loading png file of bolanYellow
	if(!loadBolan(gData))
	{
		printf("Failed to load Bolan!\n");
		success = false;
	}
	
	if(!loadNokami(gData))
	{
		printf("Failed to load Nokami!\n");
		success = false;
	}

	if(!loadmasih(gData))
	{
		printf("Failed to load masih!\n");
		success = false;
	}
	if(!loadPejman(gData))
	{
		printf("Failed to load pejman!\n");
		success = false;
	}
	if(!loadNoa(gData))
	{
		printf("Failed to load  Noa! \n");
		success = false;
	}
	//Load field
	temp = new LTexture(gData);
	if( !temp->loadFromFile( "../visualizer/assets/field.png" ))
	{
		printf( "Failed to load field!\n" );
		success = false;
	}
	else
	{	
		gData->field = temp;
	}
	
	//Load gate
	temp = new LTexture(gData);
	if( !temp->loadFromFile( "../visualizer/assets/gate.png" ))
	{
		printf( "Failed to load gate!\n" );
		success = false;
	}
	else
	{	
		gData->gate = temp;
	}

	gData->gFont = TTF_OpenFont( "../visualizer/assets/astri.ttf", 28 );
	if( gData->gFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		gData->scoreT1 = new LTexture(gData);
		gData->scoreT2 = new LTexture(gData);
		gData->gtime = new LTexture(gData);
	}
	// else
	// {
	// 	//Render text
	// 	gData->scoreT1 = new LTexture(gData);
	// 	SDL_Color textColor = { 0, 0, 0 };
	// 	if( !gData->scoreT1->loadFromRenderedText( "The quick brown fox jumps over the lazy dog", textColor))
	// 	{
	// 		printf( "Failed to render text texture!\n" );
	// 		success = false;
	// 	}
	// }
	return success;
}

bool loadNoa(SharedData* gData)
{
	LTexture* temp = new LTexture(gData);
	bool success = true;

	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s1-front-m.png"))
	{
		printf( "Failed to load s1-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s1-front-r.png"))
	{
		printf( "Failed to load s1-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s1-front-l.png"))
	{
		printf( "Failed to load s1-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s1-back-m.png"))
	{
		printf( "Failed to load s1-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s1-back-r.png"))
	{
		printf( "Failed to load s1-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s1-back-l.png"))
	{
		printf( "Failed to load s1-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaYellow.push_back(temp);
	}
	
	//loading png file of noaRed
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s2-front-m.png"))
	{
		printf( "Failed to load s2-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s2-front-r.png"))
	{
		printf( "Failed to load s2-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s2-front-l.png"))
	{
		printf( "Failed to load s2-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s2-back-m.png"))
	{
		printf( "Failed to load s2-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s2-back-r.png"))
	{
		printf( "Failed to load s2-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/noa/s2-back-l.png"))
	{
		printf( "Failed to load s2-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->noaRed.push_back(temp);
	}
	return success;
}

bool loadmasih(SharedData* gData)
{
	LTexture* temp = new LTexture(gData);
	bool success = true;

	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k1-front-m.png"))
	{
		printf( "Failed to load k1-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k1-front-r.png"))
	{
		printf( "Failed to load k1-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k1-front-l.png"))
	{
		printf( "Failed to load k1-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k1-back-m.png"))
	{
		printf( "Failed to load k1-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k1-back-r.png"))
	{
		printf( "Failed to load k1-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k1-back-l.png"))
	{
		printf( "Failed to load k1-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihYellow.push_back(temp);
	}
	
	//loading png file of masihRed
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k2-front-m.png"))
	{
		printf( "Failed to load k2-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k2-front-r.png"))
	{
		printf( "Failed to load k2-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k2-front-l.png"))
	{
		printf( "Failed to load k2-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k2-back-m.png"))
	{
		printf( "Failed to load k2-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k2-back-r.png"))
	{
		printf( "Failed to load k2-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/masih/k2-back-l.png"))
	{
		printf( "Failed to load k2-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->masihRed.push_back(temp);
	}
	return success;
}


bool loadPejman(SharedData* gData)
{
	LTexture* temp = new LTexture(gData);
	bool success = true;

	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p1-front-m.png"))
	{
		printf( "Failed to load p1-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p1-front-r.png"))
	{
		printf( "Failed to load p1-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p1-front-l.png"))
	{
		printf( "Failed to load p1-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p1-back-m.png"))
	{
		printf( "Failed to load p1-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p1-back-r.png"))
	{
		printf( "Failed to load p1-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p1-back-l.png"))
	{
		printf( "Failed to load p1-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanYellow.push_back(temp);
	}
	
	// loading png file of pejmanRed
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p2-front-m.png"))
	{
		printf( "Failed to load p2-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p2-front-r.png"))
	{
		printf( "Failed to load p2-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p2-front-l.png"))
	{
		printf( "Failed to load p2-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p2-back-m.png"))
	{
		printf( "Failed to load p2-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p2-back-r.png"))
	{
		printf( "Failed to load p2-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/pejman/p2-back-l.png"))
	{
		printf( "Failed to load p2-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->pejmanRed.push_back(temp);
	}
	clog << "PEJMAN "<<success << " " << gData->pejmanYellow.size()<<endl;
	return success;
}

bool loadNokami(SharedData* gData)
{
	LTexture* temp = new LTexture(gData);
	bool success = true;

	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n1-front-m.png"))
	{
		printf( "Failed to load n1-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n1-front-r.png"))
	{
		printf( "Failed to load n1-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n1-front-l.png"))
	{
		printf( "Failed to load n1-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n1-back-m.png"))
	{
		printf( "Failed to load n1-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n1-back-r.png"))
	{
		printf( "Failed to load n1-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n1-back-l.png"))
	{
		printf( "Failed to load n1-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiYellow.push_back(temp);
	}
	
	//loading png file of nokamiRed
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n2-front-m.png"))
	{
		printf( "Failed to load n2-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n2-front-r.png"))
	{
		printf( "Failed to load n2-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n2-front-l.png"))
	{
		printf( "Failed to load n2-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n2-back-m.png"))
	{
		printf( "Failed to load n2-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n2-back-r.png"))
	{
		printf( "Failed to load n2-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/nokami/n2-back-l.png"))
	{
		printf( "Failed to load n2-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->nokamiRed.push_back(temp);
	}
	return success;
}

bool loadBolan(SharedData* gData)
{
	LTexture* temp = new LTexture(gData);
	bool success = true;

	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b1-front-m.png"))
	{
		printf( "Failed to load b1-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b1-front-r.png"))
	{
		printf( "Failed to load b1-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b1-front-l.png"))
	{
		printf( "Failed to load b1-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b1-back-m.png"))
	{
		printf( "Failed to load b1-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b1-back-r.png"))
	{
		printf( "Failed to load b1-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b1-back-l.png"))
	{
		printf( "Failed to load b1-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanYellow.push_back(temp);
	}
	
	//loading png file of bolanRed
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b2-front-m.png"))
	{
		printf( "Failed to load b2-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b2-front-r.png"))
	{
		printf( "Failed to load b2-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b2-front-l.png"))
	{
		printf( "Failed to load b2-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b2-back-m.png"))
	{
		printf( "Failed to load b2-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b2-back-r.png"))
	{
		printf( "Failed to load b2-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bolan/b2-back-l.png"))
	{
		printf( "Failed to load b2-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->bolanRed.push_back(temp);
	}
	return success;
}


void close(SharedData* gData)
{
	
	for(int i=0; i<11; i++)
		delete gData->movingObjs[i];
	for(int j=0; j<6; j++)
	{
		delete gData->bolanYellow[j];
		delete gData->bolanRed[j];
	}
	delete gData->field;
	
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

bool getInputs(SharedData* gData)
{
	gData->playersPos.clear();
	pair<int,int> temPos;
	double _x,_y;
	for(int i=0; i<10;i++)
	{
		cin >>_x >>_y;

		#ifdef _DEBUG
		cerr << i<<"GET:: " << _x << "-" << _y << endl; 
		#endif

		//converting positions
		//I wish that works
		_x = 5*_x + 5*45 + 45;
		_y = -5*_y + 5*60 + 60;
		//end of correcting positions
		temPos = make_pair ((int)_x,(int)_y);
		gData->playersPos.push_back(temPos);
	}
	cin >> _x >> _y;

	#ifdef _DEBUG
	cerr << "BALL:: " << _x << "-" << _y << endl;
	#endif

	_x = 5*_x + 5*45 + 45;
	_y = -5*_y + 5*60 + 60;
	gData->ballPos = make_pair((int)_x,(int)_y);
	cin >> gData->gameState ;

	#ifdef _DEBUG
	cerr << "STATE:: " << gData->gameState << endl;
	cerr << "CYCLE:: " << gData->cycleNum << endl;
	#endif

	return true;
}

void handleState(int state,SharedData* gData)
{
	stringstream ss2;
	ss2 << 1000 - gData->cycleNum/5;
	SDL_Color textColort = { 255, 255, 255 };
	gData->gtime->loadFromRenderedText(ss2.str(),textColort);
	if (state == 0)
	{
		gData->lState = 0;
		//defualt 
	}
	else if (state == 4)
	{
		// team1_goal
		//Render text
		if(gData->lState == 0)
		{
			stringstream ss;
			ss.str()="";
			gData->score1++;
			ss << gData->score1;
			SDL_Color textColor = { 255, 0, 0 };
			gData->scoreT1->loadFromRenderedText(ss.str(), textColor);
		}
		gData->lState = 4;
	}
	else if (state == 5)
	{
		// team2_goal
		if (gData->lState ==0)
		{
			stringstream ss1;
			gData->score2++;
			ss1.str()="";
			ss1 << gData->score2;
			SDL_Color textColor = { 255, 255, 0 };
			gData->scoreT2->loadFromRenderedText( ss1.str(), textColor);
		}
		gData->lState = 5;
	}
}

void setNewData(SharedData* gData)
{
	for(int i=1 ; i<11;i++)
	{
		gData->movingObjs[i]->setNewXY(gData->playersPos[i-1].first,gData->playersPos[i-1].second);
	}
	gData->movingObjs[0]->setNewXY(gData->ballPos.first,gData->ballPos.second);
}

bool initGame(SharedData* gData)
{
	//I think it should be loaded in loading media but ...
	LTexture* temp = new LTexture(gData);
	SDL_Color textColorR = { 255,0,0 };
	SDL_Color textColorY = { 255,255,0};
	temp->loadFromFile("../visualizer/assets/ball.png");
	gData->scoreT1->loadFromRenderedText("0", textColorR);
	gData->scoreT2->loadFromRenderedText("0", textColorY);
	gData->movingObjs.push_back(new Ball(temp));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanYellow, false));
	gData->movingObjs.push_back(new Player("nokami",gData->nokamiYellow, false));
	gData->movingObjs.push_back(new Player("noa",gData->noaYellow, false));
	gData->movingObjs.push_back(new Player("pejman",gData->pejmanYellow, false));
	gData->movingObjs.push_back(new Player("masih",gData->masihYellow, false));
	
	gData->movingObjs.push_back(new Player("bolan",gData->bolanRed));
	gData->movingObjs.push_back(new Player("nokami",gData->nokamiRed));
	gData->movingObjs.push_back(new Player("noa",gData->noaRed));
	gData->movingObjs.push_back(new Player("pejman",gData->pejmanRed));
	gData->movingObjs.push_back(new Player("masih",gData->masihRed));
	
	getInputs(gData);
	setNewData(gData);
	return true;
}

void renderAll(SharedData* gData)
{
	vector<int> sortedObjs;

	//sorting players and ball
	vector<int> mvIndex;
	for (int i = 0; i < gData->movingObjs.size(); i++)
		mvIndex.push_back(i);

	while ( mvIndex.size() != 0 ) {
		int i = 0;
		int min = mvIndex[i];

		for (int j = 0; j < mvIndex.size(); j++) {
			if (gData->movingObjs[mvIndex[j]]->y < gData->movingObjs[mvIndex[i]]->y){
				min = mvIndex[j];
				i = j;
			}
			else if (gData->movingObjs[mvIndex[j]]->y == gData->movingObjs[mvIndex[i]]->y)
				if (gData->movingObjs[mvIndex[j]]->x < gData->movingObjs[mvIndex[i]]->x) {
					min = mvIndex[j];
					i = j;
				}
				else if (gData->movingObjs[mvIndex[j]]->x == gData->movingObjs[mvIndex[i]]->x)
					if (gData->movingObjs[mvIndex[j]]->name == "ballony") {
						min = mvIndex[j];
						i = j;
					}
		}

		sortedObjs.push_back(min);
		mvIndex.erase(mvIndex.begin() + i);
	}

	// rendering all
	for (int i = 0; i < sortedObjs.size(); i++)
		gData->movingObjs[sortedObjs[i]]->render(gData->cycleNum);

	return;

}
