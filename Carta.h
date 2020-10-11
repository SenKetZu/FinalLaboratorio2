#pragma once
#include <SFML/Graphics.hpp>


class Carta{
private:
	sf::Sprite _carta;
	sf::Texture _textura;
	//size
	float _x = 100.f, _y = 100.f;

public:
	Carta(sf::RenderWindow&pantalla);
	void setSize(float x, float y);
	
	void mostrar(sf::RenderWindow&pantalla);




};

