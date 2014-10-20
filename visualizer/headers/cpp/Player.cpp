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
	if(direction == 1 && dy>0)
		direction = 0;
	else if (direction == 0 && dy<0)
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
	int state = cycleNum % 12;
	LTexture* returnTexture = NULL;

	// if his face was visible
	if (direction) {
		if ( (0 <= state && state <= 2) || (6 <= state && state <= 8))
			returnTexture = mood[0];
		else if (3 <= state && state <= 5)
			returnTexture = mood[1];
		else if (9 <= state && state <= 11)
			returnTexture = mood[2];
	}

	// if his back was visible
	if (!direction) {
		if ( (0 <= state && state <= 2) || (6 <= state && state <= 8))
			returnTexture = mood[3];
		else if (3 <= state && state <= 5)
			returnTexture = mood[4];
		else if (9 <= state && state <= 11)
			returnTexture = mood[5];
	}

	return returnTexture;
}