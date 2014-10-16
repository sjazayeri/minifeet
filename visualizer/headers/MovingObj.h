#ifndef MOVING_OBJ_
#define MOVING_OBJ_
using namespace std;

class MovingObj
{
public:
	MovingObj();
	~MovingObj();

	void move();
	virtual void setNewXY(int newX, int newY) = 0;

private:
	int x, y;
	int oldX, oldY;
	int dx, dy;
};

#endif