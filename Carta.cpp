#include "Carta.h"
#include <iostream>

Carta::Carta(sf::RenderWindow &pantalla) {


	std::cout << "test1";
	if (!_textura.loadFromFile("sources\\BlankCard3.png")) { std::cout << "fail load"; }
	_carta.setPosition(sf::Vector2f((pantalla.getSize().x)/2-(/2), (pantalla.getSize().y)/2-(_y/2)));

	_carta.setTexture(_textura);

	_carta.
}

void Carta::setSize(float x, float y) {

	_carta.setScale(sf::Vector2f(x, y));
}

void Carta::mostrar(sf::RenderWindow &pantalla) {

	pantalla.draw(_carta);


}