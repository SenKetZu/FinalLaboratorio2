#include "Menu.h"
#include "Render.h"
#include <iostream>
#include "SFML/Graphics.hpp"

Menu::Menu()
{
	
	
	
	for (std::string el : _txtElements) {
		TextPress aux(_letra, el.c_str());
		_elementos.push_back(aux);
	}

	for (auto& elemento : _elementos)
	{

		elemento.getText().setCharacterSize(70);
		elemento.getText().setFillColor(sf::Color::Cyan);
		elemento.getText().setOutlineColor(sf::Color::Red);
		elemento.getText().setOutlineThickness(2);
		elemento.getText().setOrigin({ elemento.getText().getGlobalBounds().width / 2,elemento.getText().getGlobalBounds().height / 2 });
		elemento.getText().setPosition(sf::Vector2f(Render::getInstance().devolver().getSize().x / 2, _offSet));

		_offSet += _separacion;

	}
}

void Menu::menuOption()
{
	

	while(Render::getInstance().devolver().isOpen()){
		
		
		for (auto& el : _elementos) {			

			if (el.check()) {
				el.highlight(true);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					std::cout << "selecciona	do" << std::endl;
				}
			}
			else {
				el.highlight(false);
			}
			Render::getInstance().dibujar(el.getText());
		}

		Render::getInstance().devolver().display();

	}
}
