#include "../Player.h"

Player::Player(string _name, vector<LTexture*> _pngFiles)
{
	name = _name;
	mood = _pngFiles;
}