#include "Pressable.h"
#include "Nota.h"
#include <iostream>






Pressable& Pressable::presionar()
{
	_wasPressed = true;
	return *this;
}

bool Pressable::isPressed()
{

	return _wasPressed;
}

Pressable& Pressable::centrar()
{
	sf::Vector2f tam(_nota.getGlobalBounds().height, _nota.getGlobalBounds().width);

	_nota.setOrigin(tam.x / 2, tam.y / 2);
	return *this;
}

Pressable& Pressable::setTexture(sf::Texture& tx)
{
	_nota.setTexture(tx);
	return *this;
}

Pressable& Pressable::setChanel(int ch)
{
	_chanel = ch;
	return *this;
}

Pressable& Pressable::setAltura(float altura)
{
	_altura = altura;
	return *this;
}

Pressable& Pressable::addAltura(float esp)
{
	if (!esp) {
		_altura += _speed;
	}
	else {
		_altura += esp;
	}

	return *this;
}

Pressable& Pressable::setScale(float x, float y)
{
	_nota.setScale(x, y);
	return *this;
}

Pressable& Pressable::setPosition(float x)
{
	_nota.setPosition(x, _altura);
	return *this;
}

Pressable& Pressable::setPosition(float x, float y)
{
	_nota.setPosition(x, y);
	return *this;
}

Pressable& Pressable::setOnScreen()
{
	_isOnScreen = true;
	return *this;
}

Pressable& Pressable::setOffScreen()
{
	_isOnScreen = false;
	return *this;
}

Pressable& Pressable::setSpeed(float speed)
{
	_speed = speed;

	return *this;
}

float Pressable::getAltura()
{
	return _altura;
}

int Pressable::getChanel()
{
	return _chanel;
}

bool Pressable::getOnScreen()
{
	return _isOnScreen;
}

sf::Sprite& Pressable::devolver()
{
	return _nota;
}