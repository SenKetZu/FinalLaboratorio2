#pragma once
#include "ElementoConTexto.h"
#include <SFML/Graphics.hpp>
#include <vector>


class SelectorCancion
{
private:

	sf::RectangleShape _background;
	sf::Texture _backTexture;
	sf::CircleShape _flechaArriva, _flechaAbajo;
	std::vector<ElementoConTexto> _elements;
	float _alturaOffset=100, _spaceBtwn=150.f;
	bool _cancion = false;





private:

	void checkHighlight();
	void checkPress();
	void relocateElements();

public:
	SelectorCancion();
	void selectorLoop();


};

