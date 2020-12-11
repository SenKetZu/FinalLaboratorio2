#pragma once
#include <SFML/Graphics.hpp>
#include "Structs.h"



class TextPress
{
private:
	sf::Text _element;

	Elementos test;

public:
	
	TextPress(sf::Font& fuente,const char* texto);
	Elementos check();
	//(int tamaño letra, color base, color outline, grosor linea exterior, posicion vector2f )
	TextPress& setCaracteristicas(int tam,sf::Color base, sf::Color outline, int grosOutline, int offSet);
	TextPress& setString(const char* texto);
	TextPress& highlight(bool estaMarcado);

	sf::Text& getText();

};

