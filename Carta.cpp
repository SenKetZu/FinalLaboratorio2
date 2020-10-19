#include "Carta.h"
#include <iostream>

Carta::Carta(sf::RenderWindow &pantalla) {
	
	//carga textura
	sf::Vector2f escala;
	sf::Vector2u tamaño;
	if (!_textura.loadFromFile("sources\\BlankCard3.png")) { std::cout << "fail load"; }	
	_carta.setTexture(_textura);
	

	
}

void Carta::centrar(sf::RenderWindow& pantalla) {
	
	sf::Vector2u tamaño;

	tamaño=_textura.getSize();

	sf::Vector2f centroPantalla;

	_carta.setOrigin(tamaño.x/2,tamaño.y);

	centroPantalla.x = pantalla.getSize().x/2;
	centroPantalla.y = pantalla.getSize().y/2;

	_carta.setPosition(centroPantalla.x,centroPantalla.y+(tamaño.y/4));
}

void Carta::setSize(float x, float y) {

	_carta.setScale(sf::Vector2f(x, y));
}

void Carta::mostrar(sf::RenderWindow &pantalla) {

	pantalla.draw(_carta);


}


sf::Sprite &Carta::devolverSprite() {
	return  _carta;

}