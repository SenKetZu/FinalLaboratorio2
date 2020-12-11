#include "TextPress.h"
#include <iostream>
#include "Render.h"

TextPress::TextPress(sf::Font& fuente, const char* texto)
{
	_element.setFont(fuente);
	_element.setString(texto);
}

Elementos TextPress::check()
{
	bool test = _element.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(Render::getInstance().devolver()));
	if (_element.getString() == "Play"&& test) {
		return Play;
	}if (_element.getString() == "Scores" && test) {
		return Score;
	}if (_element.getString() == "Config" && test) {
		return Config;
	}if (_element.getString() == "Exit" && test) {
		return Exit;
	}
	else {
		return NONE;
	}
}

TextPress& TextPress::setCaracteristicas(int tam, sf::Color base, sf::Color outline, int grosOutline, int offSet)
{

	_element.setCharacterSize(tam);
	_element.setFillColor(base);
	_element.setOutlineColor(outline);
	_element.setOutlineThickness(grosOutline);
	_element.setOrigin({ _element.getGlobalBounds().width / 2,_element.getGlobalBounds().height / 2 });
	_element.setPosition(sf::Vector2f(Render::getInstance().devolver().getSize().x / 8, offSet));




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
		_element.setOutlineColor(sf::Color::Cyan);
	}
	else {
		_element.setOutlineColor(sf::Color(12, 183, 242));
	}
	return *this;
}

sf::Text& TextPress::getText()
{
	return _element;
}
