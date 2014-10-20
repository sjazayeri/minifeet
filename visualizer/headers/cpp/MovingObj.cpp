#include "../MovingObj.h"

//calculate current position of Obj
void MovingObj::move()
{
	// cerr << "MOVE:::dx--dy" << dx << dy << endl;
	x += dx;
	y += dy;
}