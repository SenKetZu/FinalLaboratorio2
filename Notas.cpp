#include "Notas.h"
#include <iostream>



Notas::Notas(const char *nombre_imagen,sf::Vector2f escala) {
	char Dir[50] = "Sources\\";
	if (!_textura.loadFromFile(strcat(Dir,nombre_imagen))) {
		std::cout << "fail";
	}
	//_textura.setSmooth(true);
	_nota.setTexture(_textura);

	_nota.setScale(escala);









}

sf::Sprite& Notas::devolver() {

	return _nota;



}



void Notas::dimensionar(float x, float y) {


	_nota.setScale(x, y);



}