#pragma once
#include "Render.h"
#include <SFML/Graphics.hpp>



class Notas{
private:
	bool presionada;
	sf::Sprite _nota;
	sf::Texture _textura;

	sf::Vector2f dimensiones, _centroObjeto;



public:
	
	Notas(const char* nombre_imagen, sf::Vector2f escala);
	sf::Sprite& getSprite();
	void setScale(float x, float y);
	void mover(float x, float y);
	void presionar();


};

