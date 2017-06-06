#pragma once
#include "enemy.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	character *pers = new character;
	enemy *e = new enemy;
};

