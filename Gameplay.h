#pragma once
#include "Structs.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Nota.h"
#include "Cancion.h"
#include "Render.h"
#include "Colision.h"


class Gameplay{
private:
	sf::Event _event;
	Render _mostrar;
	Cancion _cancion;
	Colision _trast;
	bool press[4] = { false };




public:

	 void initSong();
	 void setConfig();
	 void gameLoop();
	 void inputs();


};

