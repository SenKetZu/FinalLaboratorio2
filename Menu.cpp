#include "Menu.h"
#include "Render.h"
#include <iostream>
#include "Structs.h"
#include "SFML/Graphics.hpp"
#include "Gameplay.h"

Menu::Menu()
{
	_fondo.setSize(sf::Vector2f(Render::getInstance().devolver().getSize()));
	_texturaFondo.loadFromFile("Sources\\BackGroundMenu.png");
	_fondo.setTexture(&_texturaFondo);
	
	for (std::string el : _txtElements) {
		TextPress aux(_letra, el.c_str());
		_elementos.push_back(aux);
	}

	for (auto& elemento : _elementos)
	{
		elemento.setCaracteristicas(70,sf::Color::Transparent,sf::Color(12, 183, 242),1, _offSet);
		
		_offSet += _separacion;

	}

}

void Menu::menuOption()
{
	sf::Event _event;

	while(Render::getInstance().devolver().isOpen()){
		
		while (Render::getInstance().devolver().pollEvent(_event)) {
			if (_event.type == sf::Event::Closed) {
				Render::getInstance().devolver().close();
			}
		}
		Render::getInstance().dibujar(_fondo);
		for (auto& el : _elementos) {
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				switch (el.check())
				{
				case Play:
					Gameplay::getInstance().initSong();
					break;
				case Score:
					break;
				case Config:
					break;
				case Exit:					
					Render::getInstance().devolver().close();
					break;
				default:
					break;
				}
			}			

			if (el.check()>=0&& el.check()<=3) {
				el.highlight(true);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					std::cout << "seleccionado" << std::endl;
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
