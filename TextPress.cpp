#include "TextPress.h"
#include <iostream>
#include "Render.h"

TextPress::TextPress(sf::Font& fuente, const char* texto)
{
	_element.setFont(fuente);
	_element.setString(texto);
}

bool TextPress::check()
{
	bool test = _element.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(Render::getInstance().devolver()));
	
	
	return test;
}

TextPress& TextPress::setCaracteristicas(int tam, sf::Color base, sf::Color outline, int grosOutline, sf::Vector2f posicion)
{

	




	return *this;
}

TextPress& TextPress::setString(const char* texto)
{
	_element.setString(texto);
	return *this;
}

TextPress& TextPress::highlight(bool estaMarcado)
{
	if (estaMarcado) {
		_element.setOutlineColor(sf::Color::Blue);
	}
	else {
		_element.setOutlineColor(sf::Color::Red);
	}
	return *this;
}

sf::Text& TextPress::getText()
{
	return _element;
}
