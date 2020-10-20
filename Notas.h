#pragma once
#include <SFML/Graphics.hpp>
class Notas{
private:

	sf::Sprite _nota;
	sf::Texture _textura;
	float _altura;
	int chanel;
	bool pressed = false;
public:
	void press();
	int getChanel();
	void setAltura(float altura);
	void addAltura();
	float getAltura();
	Notas(int color, sf::Vector2f escala);	
	sf::Sprite& devolver();

};



