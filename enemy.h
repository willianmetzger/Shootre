#pragma once
#include "character.h"
class enemy
{
public:
	enemy();
	~enemy();
	void setPos(int x, int y);
	void setSprite(string sprite);
	void drawRotation(character *pers);

	int getX();
	int getY();
	int getAngle();
private:
	int x, y, life, angle;
	float speed = 2, v_speed = 0, h_speed = 0, dir_x, dir_y, totaldir;
	float prop_x, prop_y;
	Sprite *spr = new Sprite;
};


