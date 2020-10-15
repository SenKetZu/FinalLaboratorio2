#include "Notas.h"
#include <iostream>


Notas::Notas(const char *nombre_imagen,sf::Vector2f escala) {
	
	
	
	char Dir[50] = "Sources\\";
	if (!_textura.loadFromFile(strcat(Dir,nombre_imagen))) {
		std::cout << "fail";
	}

	_nota.setTexture(_textura);

	_nota.setScale(escala);


	_centroObjeto = sf::Vector2f(_nota.getGlobalBounds().width / 2, _nota.getGlobalBounds().height / 2);

	_nota.setOrigin(_centroObjeto);

	_textura.setSmooth(true);
}

sf::Sprite& Notas::getSprite() {

	return _nota;
}

void Notas::mover(float x, float y){

	_nota.setPosition(x, y);
}

void Notas::presionar(){
	



}

void Notas::setScale(float x, float y) {

	_nota.setScale(x, y);

}