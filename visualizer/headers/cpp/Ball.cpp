#include "../Ball.h"

Ball::Ball(LTexture* _pngFile)
{
	name = "ballony";
	texture = _pngFile;
}

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

void Ball::render(unsigned int cycleNum)
{
	texture->render(x, y);
}