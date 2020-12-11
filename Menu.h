#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Render.h"
#include "TextPress.h"


class Menu {

private:
	int _separacion = 150,_offSet=120;
	int _pressedElement = -1;
	std::string _txtElements[4] = {"Play","Scores","Config","Exit"};
	Elementos _ele;
	sf::Font _letra=Render::getInstance().getFont();
	std::vector<TextPress>_elementos;
	sf::RectangleShape _fondo;
	sf::Texture _texturaFondo;




public:
	Menu();

	void menuOption();

};