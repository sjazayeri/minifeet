#include "../MovingObj.h"

MovingObj::MovingObj()
{}
MovingObj::~MovingObj()
{}
int MovingObj::get_nx()
{
	return x;
}

int MovingObj::get_ny()
{
	return y;
}

int MovingObj::get_oldX()
{
	return oldX;
}

int MovingObj::get_oldY()
{
	return oldY;
}

int MovingObj::get_dy()
{
	return dy;
}

int MovingObj::get_dx()
{
	return dx;
}