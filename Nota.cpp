#include "Nota.h"
#include <iostream>










Nota& Nota::centrar()
{
	sf::Vector2f tam(_nota.getGlobalBounds().height, _nota.getGlobalBounds().width);

	_nota.setOrigin(tam.x / 2, tam.y / 2);
	return *this;
}

Nota& Nota::setTexture(sf::Texture& tx)
{
	_nota.setTexture(tx);
	return *this;
}

Nota& Nota::setChanel(int ch)
{
	_chanel = ch;
	return *this;
}

Nota& Nota::setAltura(float altura)
{
	_altura = altura;
	return *this;
}

Nota& Nota::addAltura(float alt)
{
	_altura+=alt;
	return *this;
}

Nota& Nota::setScale(float x, float y)
{
	_nota.setScale(x, y);
	return *this;
}

Nota& Nota::setPosition(float x)
{
	_nota.setPosition(x, _altura);
	return *this;
}

Nota& Nota::setPosition(float x, float y)
{
	_nota.setPosition(x, y);
	return *this;
}

Nota& Nota::setOnScreen()
{
	_isOnScreen = true;
	return *this;
}

float Nota::getAltura()
{
	return _altura;
}

int Nota::getChanel()
{
	return _chanel;
}

bool Nota::getOnScreen()
{
	return _isOnScreen;
}

sf::Sprite& Nota::devolver()
{
	return _nota;
}





