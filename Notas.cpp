#include "Notas.h"
#include <iostream>




void Notas::press()
{
	pressed = true;
}

int Notas::getChanel()
{
	return chanel;
}

void Notas::setAltura(float altura)
{
	_altura = altura;
}

void Notas::addAltura()
{
	_altura+=50.0f;
}

float Notas::getAltura()
{
	return _altura;
}

Notas::Notas(int color,sf::Vector2f escala) {
	
	chanel = color;
	switch (color){
		case 0:
			if (!_textura.loadFromFile("Sources\\NotaAzul.png") ) {
				std::cout << "fail";
			}
			break;
		case 1:
			if (!_textura.loadFromFile("Sources\\NotaVerde.png")) {
				std::cout << "fail";
			}
			break;
		case 2:
			if (!_textura.loadFromFile("Sources\\NotaRoja.png")) {
				std::cout << "fail";
			}
			break;
		case 3:
			if (!_textura.loadFromFile("Sources\\NotaNaranja.png")) {
				std::cout << "fail";
			}
			break;

	default:
		break;
	}

	_nota.setTexture(_textura);

	_nota.setScale(escala);

	_nota.setOrigin(sf::Vector2f(_nota.getGlobalBounds().width / 2, _nota.getGlobalBounds().height / 2));

	_textura.setSmooth(true);
}

sf::Sprite& Notas::devolver()
{
	return _nota;
}





