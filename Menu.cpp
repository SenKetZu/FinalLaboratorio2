#include "Menu.h"
#include "Render.h"
#include <iostream>
#include "Structs.h"
#include "SFML/Graphics.hpp"
#include "SelectorCancion.h"
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

	for (TextPress& elemento : _elementos)
	{
		elemento.setCaracteristicas(70,sf::Color::Transparent,sf::Color(12, 183, 242),1, _offSet);
		
		_offSet += _separacion;

	}

}

void Menu::menuLoop()
{

	while(_ele==Elementos::NONE){
		
		Render::getInstance().handleEvents();

		Render::getInstance().dibujar(_fondo);
		for (TextPress& el : _elementos) {
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				_ele = el.check();
				switch (_ele)
				{
				case Play:	
				{
				SelectorCancion obj;
				obj.selectorLoop();
				Gameplay::getInstance().initSong();
				}					
					break;

				case Score:
					break;

				case Config:			
					break;

				case Exit:	
					Render::getInstance().close();
					break;

				default:
					break;
				}
			}			

			if (el.check()!=Elementos::NONE) {
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
		
		Render::getInstance().display();

	}
}
