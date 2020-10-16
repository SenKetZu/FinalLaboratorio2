#include "Animacion.h"
#include <iostream>


Animacion::Animacion(Notas notas[]):_objeto(notas[0].getSprite()){
	
	_colorAct = 0;

	_vecNotas = notas;


	
}

Animacion::Animacion(sf::Sprite &objeto) :_objeto(objeto) {

	_textura = *_objeto.getTexture();


}



void Animacion::seguirMouse(sf::RenderWindow& pantalla) {

	_posMouse=sf::Mouse::getPosition(pantalla);

	_objeto.setPosition(sf::Vector2f(_posMouse));


}

void Animacion::cambiarNota() {
	if (_colorAct == 3) {
		_colorAct = 0;
	}
	else {
		_colorAct++;
	}



	_objeto = _vecNotas[_colorAct].getSprite();
	_objeto.setPosition(sf::Vector2f(_posMouse));
}

sf::Sprite& Animacion::devolver()
{
	return _objeto;
}

void Animacion::centrar(sf::RenderWindow& pantalla) {
	
	sf::Vector2f centroImagen = sf::Vector2f(_objeto.getGlobalBounds().width / 2, _objeto.getGlobalBounds().height / 2);
	
	_objeto.setOrigin(centroImagen);

	_objeto.setPosition(pantalla.getSize().x/2, pantalla.getSize().y/2.7);

}


