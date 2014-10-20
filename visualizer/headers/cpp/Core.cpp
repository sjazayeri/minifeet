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
		// gData->field->render(0,0);
		// gData->bolanRed[3]->render(0,0);
		// gData->bolanRed[1]->render(35,0);

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
		clog << i<<" x,y = " << _x << " " << _y << endl; 
		//converting positions
		//I wish that works
		_x = 6*_x +270;
		_y = -6*_y +360;
		//end of correcting positions
		temPos = make_pair ((int)_x,(int)_y);
		gData->playersPos.push_back(temPos);
	}
	cin >> _x >> _y;
	clog << "ball x,y = " << _x << " " << _y << endl; 
	gData->ballPos = make_pair((int)_x,(int)_y);
	cin >> gData->gameState ;
	clog << ":::STATE:::" << gData->gameState << endl;
	clog << "gCycleNum = " << gData->cycleNum << endl;

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
	//
	gData->movingObjs.push_back(new Ball(temp));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanYellow, false));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanYellow, false));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanYellow, false));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanYellow, false));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanYellow, false));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanRed));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanRed));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanRed));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanRed));
	gData->movingObjs.push_back(new Player("bolan",gData->bolanRed));
	getInputs(gData);
	setNewData(gData);
	clog << "end of initial data" << endl;

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
