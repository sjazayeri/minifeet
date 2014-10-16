#ifndef MOVING_OBJ_
#define MOVING_OBJ_

class MovingObj
{
public:
	virtual MovingObj() = 0;
	virtual ~MovingObj();

	void move();
	virtual void setNewXY(int newX, int newY) = 0;

private:
	int x, y;
	int oldX, oldY;
	int dx, dy;
};

#endif