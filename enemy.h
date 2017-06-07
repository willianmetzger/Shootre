#pragma once
#include "character.h"
class enemy
{
public:
	enemy();
	~enemy();
	void setPos(int x, int y);
	void setSprite(string sprite);
	void drawRotation(character *e);

	int getX();
	int getY();
	int getAngle();
	int getSpeed();
private:
	int x, y, life, angle, speed = 3;
	float v_speed = 0, h_speed = 0, dir_x, dir_y, totaldir;
	float prop_x, prop_y;
	Sprite *spr = new Sprite;
};


