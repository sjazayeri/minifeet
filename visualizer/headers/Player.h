#ifndef PLAYER_H
#define PLAYER_H
#include "MovingObj.h"
#include "LTexture.h"
#include <vector>
#include <iostream>
using namespace std;

class LTexture;

class Player : public MovingObj
{
public:
	Player(string _name, vector<LTexture*> _pngFiles);
	
	virtual void setNewXY(int _newX, int _newY);
	virtual void render(unsigned int graphicalCycleNum);
	
private:
	// renderers contains player PNG pictures
	vector<LTexture*> mood;
	// specifies player's direction when dy=0
	bool direction;

};

#endif