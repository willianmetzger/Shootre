#pragma once
#include "libunicornio.h"

class tile
{
public:
	tile();
	~tile();
	void SetDestructible(bool d);
	void setCanWalk(bool c);

	bool GetDestructible();
	bool getCanWalk();
	Sprite* GetSprite();

private:
	Sprite s;
	bool destrucible = false;
	bool canWalk = false;
};

