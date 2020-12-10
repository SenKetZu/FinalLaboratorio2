#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Render.h"
#include "TextPress.h"

enum Elementos {
	Play,
	Score,
	Config,
	Exit

};
class Menu {

private:
	int _separacion = 100,_offSet=150;
	int _pressedElement = -1;
	std::string _txtElements[4] = {"play","scores","config","exit"};
	Elementos _ele;
	sf::Font _letra=Render::getInstance().getFont();
	std::vector<TextPress>_elementos;




public:
	Menu();

	void menuOption();

};