#pragma once
#include <SFML/Graphics.hpp>
#include "Notas.h"

class Animacion{
private:

	float _delta=0;
	int _colorAct;
	Notas *_vecNotas;
	sf::Sprite &_objeto;
	sf::Texture _textura;
	sf::Vector2f _posicion;
	sf::Vector2i _posMouse;
	
public:
	
	Animacion(Notas notas[4]);
	Animacion(sf::Sprite &objeto);

	void empezarCaer();
	void centrar(sf::RenderWindow &pantalla);
	void seguirMouse(sf::RenderWindow& pantalla);
	void cambiarNota();
	sf::Sprite &devolver();
};

