#include "character.h"



character::character()
{
}


character::~character()
{
}

void character::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void character::setSprite(string sprite)
{
	spr->setSpriteSheet(sprite);
}

void character::drawRotation()
{
	angle = atan2((gMouse.y - y), (gMouse.x - x)) * 180.f / PI;
	dir_x = speed*cos((PI / 180) * angle);
	dir_y = speed*sin((PI / 180) * angle);
	totaldir = abs(dir_x) + abs(dir_y);
	prop_x = dir_x / totaldir;
	prop_y = dir_y / totaldir;
	h_speed = prop_x * speed;
	v_speed = prop_y * speed;
	gDebug.depurar("v-spd", v_speed);
	gDebug.depurar("h-spd", h_speed);
	gDebug.depurar("angle", angle);
	gDebug.depurar("x", x);
	gDebug.depurar("y", y);
	if (gTeclado.segurando[TECLA_W]) {
		x += h_speed;
		y += v_speed;
	}
	else {
		spr->setAnimacao(0, true);
	}
	spr->desenhar(x, y, angle);
}

void character::shoot(string spr)
{
	b->setBullet(x, y, angle, spr, v_speed, h_speed);
}

int character::getX()
{
	return x;
}

int character::getY()
{
	return y;
}

int character::getAngle()
{
	return angle;
}

bullet* character::getB()
{
	return b;
}
