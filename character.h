#pragma once
#include "bullet.h"
class character
{
public:
	character();
	~character();
	void setPos(int x, int y);
	void setSprite(string sprite);
	void rotation();
	void walk(tilemap *t);
	void draw();
	void shoot(string spr);

	int getX();
	int getY();
	int getAngle();
	int getSpeed();
	float getHSpeed();
	float getVSpeed();
	bullet* getB();
private:
	int x, y, life, angle, speed = 4;
	float v_speed = 0, h_speed = 0, dir_x, dir_y, totaldir;
	float prop_x, prop_y;
	Sprite *spr = new Sprite;
	bullet *b = new bullet;
};
