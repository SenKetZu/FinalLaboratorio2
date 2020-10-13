#pragma once
#include <SFML/Graphics.hpp>


class Animacion{
private:
	float _delta;
	float _rotacion;
	sf::Sprite &_objeto;
	sf::Texture _textura;
	sf::Vector2f posicion;
	
public:
	Animacion(sf::Sprite&objeto);
	void inclinar(float rotacion);
	void caida();
	void centrar(sf::RenderWindow &pantalla);


};

