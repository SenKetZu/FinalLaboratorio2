#include "Nota.h"
#include <iostream>








int Nota::getChanel()
{
	return _chanel;
}

void Nota::centrar()
{
	sf::Vector2f tam(_nota.getGlobalBounds().height, _nota.getGlobalBounds().width);

	_nota.setOrigin(tam.x / 2, tam.y / 2);
	
}

void Nota::setTexture(sf::Texture& tx)
{
	_nota.setTexture(tx);
}

void Nota::setChanel(int ch)
{
	_chanel = ch;
}

void Nota::setAltura(float altura)
{
	_altura = altura;
}

void Nota::addAltura(float alt)
{
	_altura+=alt;
}

float Nota::getAltura()
{
	return _altura;
}





sf::Sprite& Nota::devolver()
{
	return _nota;
}





