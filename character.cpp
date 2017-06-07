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

void character::rotation()
{
	angle = atan2((gMouse.y - y), (gMouse.x - x)) * 180.f / PI;
	if (angle == 180 || abs(angle) == 90) {
		angle--;
	}
	dir_x = speed*cos((PI / 180) * angle);
	dir_y = speed*sin((PI / 180) * angle);
	totaldir = abs(dir_x) + abs(dir_y);
	prop_x = dir_x / totaldir;
	prop_y = dir_y / totaldir;
	h_speed = prop_x * speed;
	v_speed = prop_y * speed;
	//gDebug.depurar("v-spd", v_speed);
	//gDebug.depurar("h-spd", h_speed);
	//gDebug.depurar("angle", angle);
	//gDebug.depurar("x", x);
	//gDebug.depurar("y", y);
}

void character::walk(tilemap *t)
{
	if (gTeclado.segurando[TECLA_W]) {
		int temp_angle = angle - 60;
		float temp_dir_x, temp_dir_y, temp_totaldir, temp_vspeed, temp_hspeed;
		bool can_walk[3] = { 0 };

		for (int i = 0; i < 3; i++) {
			temp_dir_x = speed*cos((PI / 180) * temp_angle);
			temp_dir_y = speed*sin((PI / 180) * temp_angle);
			temp_totaldir = abs(temp_dir_x) + abs(temp_dir_y);
			temp_hspeed = (temp_dir_x / temp_totaldir) * speed;
			temp_vspeed = (temp_dir_y / temp_totaldir) * speed;

			temp_angle += 60;

			int newpos_x = abs((x + temp_hspeed * 6) / 32) - 1;
			int newpos_y = abs((y + temp_vspeed * 6) / 32) - 1;
			can_walk[i] = t->GetTilemap()[newpos_y][newpos_x]->getCanWalk();
		}
		if (can_walk[1] == true & can_walk[0] == true & can_walk[2] == true) {
			x += h_speed;
			y += v_speed;
		}
		else if (can_walk[1] == true & can_walk[0] == true & can_walk[2] == false) {
			temp_angle -= 180;

			temp_dir_x = speed*cos((PI / 180) * temp_angle);
			temp_dir_y = speed*sin((PI / 180) * temp_angle);
			temp_totaldir = abs(temp_dir_x) + abs(temp_dir_y);
			temp_hspeed = (temp_dir_x / temp_totaldir) * speed;
			temp_vspeed = (temp_dir_y / temp_totaldir) * speed;

			x += temp_hspeed;
			y += temp_vspeed;
		}
		else if (can_walk[1] == true & can_walk[0] == false & can_walk[2] == true) {
			x += temp_hspeed;
			y += temp_vspeed;
		}
	}
}

void character::draw()
{
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

int character::getSpeed()
{
	return speed;
}

float character::getHSpeed()
{
	return h_speed;
}

float character::getVSpeed()
{
	return v_speed;
}

bullet* character::getB()
{
	return b;
}
