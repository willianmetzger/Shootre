#pragma once
#include "libunicornio.h"

class tile
{
public:
	tile();
	~tile();
	void SetDestructible(bool d);

	bool   GetDestructible();
	Sprite* GetSprite();

private:
	Sprite s;
	bool destrucible = false;
};

