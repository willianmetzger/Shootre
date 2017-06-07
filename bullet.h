#pragma once
#include "tilemap.h"
class bullet
{
public:
	bullet();
	~bullet();
	void setBullet(int x, int y, int angle, string sprite, float v_s, float h_s);
	void actions();
private:
	Sprite *s = new Sprite;
	float v_speed, h_speed;
	int x, y, angle;
	bool exist = false;
};


