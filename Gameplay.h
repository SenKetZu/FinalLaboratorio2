#pragma once
#include "Structs.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Nota.h"
#include "Cancion.h"
#include "Render.h"
#include "Colision.h"
#include "Structs.h"
#include "ElementoConTexto.h"

class Gameplay{
private:
	enum ESTADOSJUEGO {
		Jugando,
		Pausa,
		Terminado
	};
	ESTADOSJUEGO _estadoActual;
	std::vector<KEYS> _teclaPulsada;
	Cancion _cancion;
	Colision _trast;
	bool press[4] = { false };
	int _tic = 0;


private:
	
	Gameplay();
	void pause();
	bool check(KEYS tecla);
public:
	static Gameplay& getInstance()
	{
		static Gameplay instancia;
		return instancia;
	}

	 void initSong();
	 void setConfig();
	 void gameLoop();
	 void inputs();
	 void show();
	 void showMenuPause(std::vector<ElementoConTexto>& ele, sf::RectangleShape pauseBackground);
};

