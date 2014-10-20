#include "../Player.h"

Player::Player(string _name, vector<LTexture*> _pngFiles, bool firstDir)
{
	name = _name;
	mood = _pngFiles;
	direction = firstDir;
}

void Player::setNewXY(int _newX, int _newY)
{
	oldX = newX;
	oldY = newY;
	x = oldX;
	y = oldY;
	newX = _newX;
	newY = _newY;
	dx = (newX-oldX)/CYCLEPROP;
	dy = (newY-oldY)/CYCLEPROP;
	cerr << "SET:::oldX--newX" << oldX << newX << _newX << endl;
	cerr << "SET:::dx--dy" << dx << dy << endl;
	if(dy>0)
		direction = 0;
	else if (dy<0)
		direction = 1;
}

void Player::render(unsigned int cycleNum)
{
	LTexture* texture = NULL;

	texture = setMood(cycleNum);

	texture->render(x, y);
}

LTexture* Player::setMood(unsigned int cycleNum)
{
	int speedScale = 5;
	int state = cycleNum % (4 * speedScale);
	LTexture* returnTexture = NULL;

	// if his face was visible
	if (direction) {
		if ( (0 <= state && state <= speedScale - 1) || (2*speedScale <= state && state <= 3*speedScale - 1))
			returnTexture = mood[0];
		else if (speedScale <= state && state <= 2*speedScale - 1)
			returnTexture = mood[1];
		else if (3*speedScale <= state && state <= 4*speedScale - 1)
			returnTexture = mood[2];
	}

	// if his back was visible
	else if (!direction) {
		if ( (0 <= state && state <= speedScale - 1) || (2*speedScale <= state && state <= 3*speedScale - 1))
			returnTexture = mood[3];
		else if (speedScale <= state && state <= 2*speedScale - 1)
			returnTexture = mood[4];
		else if (3*speedScale <= state && state <= 4*speedScale - 1)
			returnTexture = mood[5];
	}
	return returnTexture;
}