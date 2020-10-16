#pragma once
#include <SFML/Graphics.hpp>



class Notas{
private:

	sf::Sprite _nota;
	sf::Texture _textura;
	//float altura=0;
	sf::Vector2f dimensiones, _centroObjeto;


	sf::Vector2f prueba = sf::Vector2f(50, 50);


public:
	
	Notas(const char* nombre_imagen, sf::Vector2f escala);
	void setScale(float x, float y);
	sf::Sprite& getSprite();
	void mover(float x, float y);
	void presionar();


};

