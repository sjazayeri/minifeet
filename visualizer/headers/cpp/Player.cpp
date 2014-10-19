#include "../Player.h"

Player::Player()
{}

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