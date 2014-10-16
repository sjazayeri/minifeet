#ifndef BALL_
#define BALL_
#include "MovingObj.h"
#include "LTexture.h"
using namespace std;

class Ball : public MovingObj
{
public: 
	Ball(string _pngFile);

private:
	// renderer contains player PNG picture
	LTexture* texture;
};

#endif