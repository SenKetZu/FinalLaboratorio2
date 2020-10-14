#include "Animacion.h"



Animacion::Animacion(sf::Sprite &objeto):_objeto(objeto){
	_delta = 0;
	_rotacion= _objeto.getRotation();
	_textura = *_objeto.getTexture();


	sf::Vector2u b = _textura.getSize();
	_objeto.setOrigin(b.x / 2, b.y / 2);

}


void Animacion::inclinar(float rotacion) {
	
	sf::Vector2u tamaño = _textura.getSize();

	//_objeto.move(sf::Vector2f(4*rotacion,0));
	_rotacion += rotacion;
	_objeto.setRotation(_rotacion);

}


void Animacion::empezarCaer() {








	_objeto.setPosition();










}

void Animacion::seguirMouse(sf::RenderWindow& pantalla) {
	_posMouse=sf::Mouse::getPosition(pantalla);

	_objeto.setPosition(sf::Vector2f(_posMouse));


}

void Animacion::centrar(sf::RenderWindow& pantalla) {

	sf::Vector2u b =pantalla.getSize();
	_objeto.setPosition(b.x/2, b.y/2);
	

}