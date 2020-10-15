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


	sf::Vector2u b = _textura.getSize();
	sf::Vector2f a = escala;
	_centroObjeto = sf::Vector2f((b.x * a.x), (b.y * a.y));
	_nota.setOrigin(_centroObjeto);

	_textura.setSmooth(true);
}

sf::Sprite& Notas::devolver() {

	return _nota;
}

void Notas::dimensionar(float x, float y) {

	_nota.setScale(x, y);

}