#ifndef BALL_
#define BALL_
#include "MovingObj.h"
#include "LTexture.h"
using namespace std;

class LTexture;

class Ball : public MovingObj
{
public: 
	Ball(string _pngFile);
	Ball();
	virtual void setNewXY(int _newX, int _newY);
private:
	// renderer contains player PNG picture
	LTexture* texture;
};

#endif