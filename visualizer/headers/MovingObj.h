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
	int get_nx();
	int get_ny();
	int get_oldX();
	int get_oldY();
	int get_dy();
	int get_dx();
private:
	int x, y;
	int oldX, oldY;
	int dx, dy;
};

#endif