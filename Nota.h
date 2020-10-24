#pragma once
#include <SFML/Graphics.hpp>

class Nota{
private:

	sf::Sprite _nota;
	float _altura=0.0f;
	int _chanel;
	bool _pressed = false;
	

public:

	
	float getAltura();
	int getChanel();

	Nota& centrar();
	Nota& setTexture(sf::Texture&tx);
	Nota& setChanel(int ch);
	Nota& setAltura(float altura);
	Nota& addAltura(float alt=10.0f);
	Nota& setScale(float x, float y);
	Nota& setPosition(float x );
	Nota& setPosition(float x, float y);
	sf::Sprite& devolver();

};



