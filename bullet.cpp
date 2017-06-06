#include "bullet.h"



bullet::bullet()
{
}


bullet::~bullet()
{
}

void bullet::setBullet(int x, int y, int angle, string sprite, float v_s, float h_s)
{
	this->x = x;
	this->y = y;
	this->angle = angle;
	this->s->setSpriteSheet(sprite);
	this->v_speed = v_s*3;
	this->h_speed = h_s*3;
	this->exist = true;
}

void bullet::actions()
{
	if (exist == true) {
		x += h_speed;
		y += v_speed;
		s->desenhar(x, y, angle);
	}
}
