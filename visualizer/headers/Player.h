#ifndef PLAYER_H
#define PLAYER_H
#include "MovingObj.h"

class Player : public MovingObj
{
public:
	Player(string _name, vector<string> _pngFiles);
	
	virtual void setNewXY(int newX, int newY) = 0;

	string Name() { return name; }
	
private:
	stirng name;

	// renderers contains player PNG pictures
	vector<LTexture*> mood;

	// specifies player's direction when dy=0
	bool direction;

};

#endif