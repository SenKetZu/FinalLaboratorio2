#pragma once
#include <SFML/Graphics.hpp>


class Pressable
{
private:

	sf::Sprite _nota;
	float _altura = 0.0f, _speed = 1;
	int _chanel;
	bool _isOnScreen = false, _wasPressed=false;

public:


	virtual float getAltura();
	virtual int getChanel();
	virtual bool getOnScreen();


	virtual Pressable& presionar();
	virtual bool isPressed();
	virtual Pressable& centrar();
	virtual Pressable& setTexture(sf::Texture& tx);
	virtual Pressable& setChanel(int ch);
	virtual Pressable& setAltura(float altura);
	virtual Pressable& addAltura(float esp = 0);
	virtual Pressable& setScale(float x, float y);
	virtual Pressable& setPosition(float x);
	virtual Pressable& setPosition(float x, float y);
	virtual Pressable& setOnScreen();
	virtual Pressable& setOffScreen();
	virtual Pressable& setSpeed(float speed);
	virtual sf::Sprite& devolver();






};

