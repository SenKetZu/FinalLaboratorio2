#pragma once
#include <SFML/Graphics.hpp>


class Animacion{
private:
	float _delta;
	float _rotacion;
	sf::Sprite &_objeto;
	sf::Texture _textura;
	sf::Vector2f _posicion;
	sf::Vector2i _posMouse;
	
public:
	Animacion(sf::Sprite&objeto);
	void inclinar(float rotacion);
	void empezarCaer();
	void centrar(sf::RenderWindow &pantalla);
	void seguirMouse(sf::RenderWindow& pantalla);

};

