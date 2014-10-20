#ifndef MOVING_OBJ_
#define MOVING_OBJ_
#include <iostream>
using namespace std;

#define CYCLEPROP 5

class MovingObj
{
public:

	void move();
	virtual void setNewXY(int _newX, int _newY) = 0;
	virtual void render(unsigned int graphicalCycleNum) = 0;

	string name;
	int x, y;
	int newX,newY;
	int oldX, oldY;
	double dx, dy;
};

#endif