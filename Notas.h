#pragma once
#include <SFML/Graphics.hpp>
class Notas{
private:
	sf::Sprite _nota;
	sf::Texture _textura;
	float altura=0;
	sf::Vector2f dimensiones;






public:

	Notas(const char* nombre_imagen );
	void dimensionar(float x, float y);
	sf::Sprite& devolver();





};
