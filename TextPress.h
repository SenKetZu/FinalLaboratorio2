#pragma once
#include <SFML/Graphics.hpp>
class TextPress
{
private:
	sf::Text _element;

	

public:
	
	TextPress(sf::Font& fuente,const char* texto);
	bool check();
	//(int tamaño letra, color base, color outline, grosor linea exterior, posicion vector2f )
	TextPress& setCaracteristicas(int tam,sf::Color base, sf::Color outline, int grosOutline, sf::Vector2f posicion);
	TextPress& setString(const char* texto);
	TextPress& highlight(bool estaMarcado);

	sf::Text& getText();

};

