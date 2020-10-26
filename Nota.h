#pragma once
#include <SFML/Graphics.hpp>

class Nota{
private:

	sf::Sprite _nota;
	float _altura=0.0f;
	int _chanel;
	bool _isOnScreen = false;
	

public:

	
	float getAltura();
	int getChanel();
	bool getOnScreen();

	Nota& centrar();
	Nota& setTexture(sf::Texture&tx);
	Nota& setChanel(int ch);
	Nota& setAltura(float altura);
	Nota& addAltura(float alt=15.0f);
	Nota& setScale(float x, float y);
	Nota& setPosition(float x );
	Nota& setPosition(float x, float y);
	Nota& setOnScreen();
	Nota& setOffScreen();
	sf::Sprite& devolver();

};



