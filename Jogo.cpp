#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, true);
	gJanela.setTamanho(1920, 1080);

	gRecursos.carregarSpriteSheet("pers", "assets/sprites/char.png");
	pers->setSprite("pers");
	pers->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	e->setSprite("pers");
	e->setPos(5, 5);
	//	O resto da inicialização vem aqui!
	//	...
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		pers->drawRotation();
		e->drawRotation(pers);
		if (gMouse.pressionou[BOTAO_MOUSE_ESQ]) {
			pers->shoot("pers");
		}
		pers->getB()->actions();
		//	Seu código vem aqui!
		//	...

		uniTerminarFrame();
	}
}