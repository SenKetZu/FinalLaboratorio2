#pragma once
#include <SFML/Graphics.hpp>
class Notas{
private:
	sf::Sprite _nota;

	sf::Texture _textura;

	float altura=0;
	sf::Vector2f dimensiones, _centroObjeto;

public:
	
	Notas(const char* nombre_imagen, sf::Vector2f escala);

	
	sf::Sprite& devolver();

	void presionar();


};

