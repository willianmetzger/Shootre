#pragma once
#include "bullet.h"
class character
{
public:
	character();
	~character();
	void setPos(int x, int y);
	void setSprite(string sprite);
	void drawRotation();
	void shoot(string spr);

	int getX();
	int getY();
	int getAngle();
	bullet* getB();
private:
	float x, y, life, angle;
	float speed = 3, v_speed = 0, h_speed = 0, dir_x, dir_y, totaldir;
	float prop_x, prop_y;
	Sprite *spr = new Sprite;
	bullet *b = new bullet;
};
