
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}

void enemy::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void enemy::setSprite(string sprite)
{
	spr->setSpriteSheet(sprite);
}

void enemy::drawRotation(character *pers)
{
	angle = atan2((pers->getY() - y), (pers->getX() - x)) * 180 / PI;
	dir_x = speed*cos((PI / 180) * angle);
	dir_y = speed*sin((PI / 180) * angle);
	totaldir = abs(dir_x) + abs(dir_y);
	prop_x = dir_x / totaldir;
	prop_y = dir_y / totaldir;
	h_speed = prop_x * speed;
	v_speed = prop_y * speed;
	gDebug.depurar("ev-spd", v_speed);
	gDebug.depurar("eh-spd", h_speed);
	gDebug.depurar("eangle", angle);
	if (gTeclado.segurando[TECLA_D]) {
		x += h_speed;
		y += v_speed;
	}
	else {
		spr->setAnimacao(0, true);
	}
	spr->desenhar(x, y, angle);
}

int enemy::getX()
{
	return x;
}

int enemy::getY()
{
	return y;
}

int enemy::getAngle()
{
	return angle;
}

int enemy::getSpeed()
{
	return speed;
}
