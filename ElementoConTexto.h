#pragma once
#include <SFML/Graphics.hpp>
#include "Render.h"
#include <iostream>

class ElementoConTexto
{
private:
	sf::RectangleShape _marco;
	float _altura ;
	sf::Text _nombrCancion;
	std::vector<sf::Drawable*> _elements;

public:
	ElementoConTexto();
	ElementoConTexto(std::string text);
	void setAltura(float altura);
	void setNombreCancion(std::string nombre);
	bool isOnAltura();
	bool isSelected();
	void highlight(bool x);
	std::vector<sf::Drawable*> getElements();
};

