#ifndef MOVING_OBJ_
#define MOVING_OBJ_
using namespace std;

#define CYCLEPROP 5

class MovingObj
{
public:

	void move();
	virtual void setNewXY(int _newX, int _newY) = 0;

	int x, y;
	int newX,newY;
	int oldX, oldY;
	int dx, dy;
};

#endif