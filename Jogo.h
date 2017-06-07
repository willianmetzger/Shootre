#pragma once
#include "room.h"
#include "enemy.h"
#include "tilemap.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

	character* GetPers();
	enemy* GetEnemy();

private:

	room* stage_1 = new room;
	room* stage_2;
	room* stage_3;

	character* pers = new character;
	enemy* e = new enemy;
};

