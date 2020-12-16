#pragma once
#include "ElementoCancion.h"
#include <SFML/Graphics.hpp>
#include <vector>


class SelectorCancion
{
private:

	sf::RectangleShape _background;
	sf::Texture _backTexture;
	sf::CircleShape _flechaArriva, _flechaAbajo;
	std::vector<ElementoCancion> _elements;
	float _alturaOffset=100, _spaceBtwn=150.f;
	bool _cancion = false;





private:
	void checkHighlightArrow();
	void checkHighlightElements();
	void checkSelectedArrow();
	void checkSelectedElement();
	void relocateElements();

public:
	SelectorCancion();
	void selectorLoop();


};

