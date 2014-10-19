#include "../Player.h"

Player::Player(string _name, vector<LTexture*> _pngFiles)
{
	name = _name;
	mood = _pngFiles;
}

void Player::setNewXY(int _newX, int _newY)
{
	oldX = newX;
	oldY = newY;
	x = oldX;
	y = oldY;
	newX = _newX;
	newY = _newY;
	dx = (newX-oldX)/CYCLEPROP;
	dy = (newY-oldY)/CYCLEPROP;
	if(direction == 1 && dy>0)
		direction = 0;
	else if (direction =0 && dy<0)
		direction = 1;
}

void Player::render(unsigned int cycleNum)
{
	LTexture* texture = NULL;

	texture = setMood(cycleNum);

	texture->render(x, y);
}

LTexture* Player::setMood(unsigned int cycleNum)
{
	int state = cycleNum % 4;
	LTexture* returnTexture = NULL;

	// if his face was visible
	if (direction)
		if ( state == 0 || state == 2)
			returnTexture = mood[0];
		if ( state == 1 )
			returnTexture = mood[1];
		if ( state == 3 )
			returnTexture = mood[2];

	// if his back was visible
	if (!direction)
		if ( state == 0 || state == 2)
			returnTexture = mood[3];
		if ( state == 1 )
			returnTexture = mood[4];
		if ( state == 3 )
			returnTexture = mood[5];

	return returnTexture;
}