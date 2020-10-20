#pragma once
#include <SFML/Graphics.hpp>
#include "Notas.h"
#include "Cancion.h"
#include "Animacion.h"
#include <vector>



class Render{
private:

	sf::RenderWindow _Ventana;


public:
	Render();
	void dibujar(sf::Sprite obj);
	void dibujar(sf::RectangleShape obj);
};

