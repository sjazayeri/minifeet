#include "../Ball.h"

void Ball::setNewXY(int _newX, int _newY)
{
	oldX = newX;
	oldY = newY;
	x = oldX;
	y = oldY;
	newX = _newX;
	newY = _newY;
	dx = (newX-oldX)/CYCLEPROP;
	dy = (newY-oldY)/CYCLEPROP;
}

Ball::Ball(Ltexture* _pngFile)
{
	name = "ballony";
	texture = _pngFile;
}

Ball::render(unsigned int cycleNum)
{
	texture.render(x, y);
}