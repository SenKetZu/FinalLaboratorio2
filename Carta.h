#pragma once
#include <SFML/Graphics.hpp>


class Carta{
private:
	sf::Sprite _carta;
	sf::Texture _textura;
	sf::Vector2f centroPantalla;


public:
	Carta(sf::RenderWindow&pantalla);
	void setSize(float x, float y);
	void centrar(sf::RenderWindow&pantalla);
	void mostrar(sf::RenderWindow&pantalla);
	sf::Sprite &devolverSprite();



};

