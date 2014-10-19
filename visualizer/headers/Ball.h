#ifndef BALL_
#define BALL_
#include "MovingObj.h"
#include "LTexture.h"
using namespace std;

class LTexture;

class Ball : public MovingObj
{
public: 
	Ball(LTexture* _pngFile);

	virtual void setNewXY(int _newX, int _newY);
	virtual void render(unsigned int graphicalCycleNum);
	
private:
	// renderer contains player PNG picture
	LTexture* texture;
};

#endif