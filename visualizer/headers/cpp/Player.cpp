#include "../Player.h"

Player::Player(string _name, vector<LTexture*> _pngFiles)
{
	name = _name;
	mood = _pngFiles;
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
	else if (direction =0 && dy<0)
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
	if (direction)
		switch (state) {
			case 0:
			case 1:
			case 2:
			case 6:
			case 7:
			case 8:
				returnTexture = mood[0];
				break;
			case 3:
			case 4:
			case 5:
				returnTexture = mood[1];
				break;
			case 9:
			case 10:
			case 11:
				returnTexture = mood[2];
				break;
		}

	// if his back was visible
	if (!direction)
		switch (state) {
			case 0:
			case 1:
			case 2:
			case 6:
			case 7:
			case 8:
				returnTexture = mood[3];
				break;
			case 3:
			case 4:
			case 5:
				returnTexture = mood[4];
				break;
			case 9:
			case 10:
			case 11:
				returnTexture = mood[5];
				break;
		}
	return returnTexture;
}