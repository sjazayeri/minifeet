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

	if(!loadBald(gData))
	{
		printf("Failed to load Bald!\n");
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
	if( !temp->loadFromFile( "../visualizer/assets/field1.jpg" ))
	{
		printf( "Failed to load field!\n" );
		success = false;
	}
	else
	{	
		gData->field = temp;
	}
	
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

bool loadBald(SharedData* gData)
{
	LTexture* temp = new LTexture(gData);
	bool success = true;

	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k1-front-m.png"))
	{
		printf( "Failed to load k1-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k1-front-r.png"))
	{
		printf( "Failed to load k1-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k1-front-l.png"))
	{
		printf( "Failed to load k1-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k1-back-m.png"))
	{
		printf( "Failed to load k1-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k1-back-r.png"))
	{
		printf( "Failed to load k1-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldYellow.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k1-back-l.png"))
	{
		printf( "Failed to load k1-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldYellow.push_back(temp);
	}
	
	//loading png file of baldRed
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k2-front-m.png"))
	{
		printf( "Failed to load k2-front-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k2-front-r.png"))
	{
		printf( "Failed to load k2-front-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k2-front-l.png"))
	{
		printf( "Failed to load k2-front-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k2-back-m.png"))
	{
		printf( "Failed to load k2-back-m.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k2-back-r.png"))
	{
		printf( "Failed to load k2-back-r.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldRed.push_back(temp);
	}
	temp = new LTexture(gData);
	if( !temp->loadFromFile("../visualizer/assets/characters/bald/k2-back-l.png"))
	{
		printf( "Failed to load k2-back-l.png!\n" );
		success = false;
	}
	else
	{	
		gData->baldRed.push_back(temp);
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
		_x = 6*_x +270;
		_y = -6*_y +360;
		//end of correcting positions
		temPos = make_pair ((int)_x,(int)_y);
		gData->playersPos.push_back(temPos);
	}
	cin >> _x >> _y;

	#ifdef _DEBUG
	cerr << "BALL:: " << _x << "-" << _y << endl;
	#endif

	_x = 6*_x +270;
	_y = -6*_y +360;
	gData->ballPos = make_pair((int)_x,(int)_y);
	cin >> gData->gameState ;

	#ifdef _DEBUG
	cerr << "STATE:: " << gData->gameState << endl;
	cerr << "CYCLE:: " << gData->cycleNum << endl;
	#endif

	return true;
}

void handleState(int state)
{
	if (state == 0)
	{
		//defualt 
	}
	else if (state == 1)
	{
		// team1_goal
	}
	else if (state == 2)
	{
		// team2_goal
	}
	else if (state == 3)
	{
		// offside
	}
	else if (state == 4)
	{
		// kickoff
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
	temp->loadFromFile("../visualizer/assets/ball.png");
	
	gData->movingObjs.push_back(new Ball(temp));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanYellow, false));
	gData->movingObjs.push_back(new Player("nokami",gData->nokamiYellow, false));
	gData->movingObjs.push_back(new Player("noa",gData->noaYellow, false));
	gData->movingObjs.push_back(new Player("pejman",gData->pejmanYellow, false));
	gData->movingObjs.push_back(new Player("bald",gData->baldYellow, false));
	
	gData->movingObjs.push_back(new Player("bolan",gData->bolanRed));
	gData->movingObjs.push_back(new Player("nokami",gData->nokamiRed));
	gData->movingObjs.push_back(new Player("noa",gData->noaRed));
	gData->movingObjs.push_back(new Player("pejman",gData->pejmanRed));
	gData->movingObjs.push_back(new Player("bald",gData->baldRed));
	
	getInputs(gData);
	setNewData(gData);
	return true;
}

void renderAll(SharedData* gData)
{
	// vector<int> sortedObjs;

	// //sorting players and ball
	// vector<int> mvIndex;
	// for (int i = 0; i < gData->movingObjs.size(); i++)
	// 	mvIndex.push_back(i);

	// while ( mvIndex.size() != 0 ) {\
	// 	int i = 0;
	// 	int min = mvIndex[i];

	// 	for (int j = 0; j < mvIndex.size(); j++) {
	// 		if (gData->movingObjs[mvIndex[j]]->y < gData->movingObjs[mvIndex[i]]->y)
	// 			min = mvIndex[j];
	// 		else if (gData->movingObjs[mvIndex[j]]->y == gData->movingObjs[mvIndex[i]]->y)
	// 			if (gData->movingObjs[mvIndex[j]]->x < gData->movingObjs[mvIndex[i]]->x)
	// 				min = mvIndex[j];
	// 			else if (gData->movingObjs[mvIndex[j]]->x == gData->movingObjs[mvIndex[i]]->x)
	// 				if (gData->movingObjs[mvIndex[j]]->name == "ballony")
	// 					min = mvIndex[j];
	// 	}

	// 	sortedObjs.push_back(min);
	// 	mvIndex.erase(mvIndex.begin() + min);
	// }

	// // rendering all
	// for (int i = 0; i < sortedObjs.size(); i++)
	// 	gData->movingObjs[sortedObjs[i]]->render(gData->cycleNum);

	// return;

	for (int i = 0; i < gData->movingObjs.size(); i++)
		gData->movingObjs[i]->render(gData->cycleNum);
}
