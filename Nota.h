#pragma once
#include <SFML/Graphics.hpp>

class Nota{
private:

	sf::Sprite _nota;
	float _altura;
	int _chanel;
	bool _pressed = false;
	

public:

	
	
	void centrar();
	void setTexture(sf::Texture&tx);
	void setChanel(int ch);
	void setAltura(float altura);
	void addAltura();
	float getAltura();
	int getChanel();
	sf::Sprite& devolver();

};



