#include "../MovingObj.h"

//calculate current position of Obj
void MovingObj::move()
{
	x += dx;
	y += dy;
}