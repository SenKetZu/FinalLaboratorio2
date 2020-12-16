#include "ElementoCancion.h"
#include "Archivo.h"
ElementoCancion::ElementoCancion()
{
	
	_marco.setSize({ 600,70 });
	_marco.setOrigin(_marco.getSize().x/2, _marco.getSize().y / 2);	
	_marco.setFillColor(sf::Color::Transparent);
	_marco.setOutlineColor(sf::Color::Red);
	_marco.setOutlineThickness(2);

	_nombrCancion.setFont(Render::getInstance().getFont());
	_nombrCancion.setFillColor(sf::Color::Black);
	_nombrCancion.setOutlineThickness(1);
	_nombrCancion.setOutlineColor(sf::Color::White);
	_nombrCancion.setCharacterSize(30);
}

void ElementoCancion::setAltura(float altura)
{
	_altura = altura;
	_marco.setPosition(Render::getInstance().devolver().getSize().x / 2, altura);
	_nombrCancion.setPosition(Render::getInstance().devolver().getSize().x / 2, altura);
}

void ElementoCancion::setNombreCancion(std::string nombre)
{
	_nombrCancion.setString(nombre);
	_nombrCancion.setOrigin(_nombrCancion.getGlobalBounds().width / 2, _nombrCancion.getGlobalBounds().height / 2);
}

bool ElementoCancion::isOnAltura()
{
	int alt = Render::getInstance().getSize().y - 100;
	if (_marco.getPosition().y > alt)
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::vector<sf::Drawable*> ElementoCancion::getElements()
{
	//_elements.clear();
	_elements.push_back(&_marco);
	_elements.push_back(&_nombrCancion);

	return _elements;
}

bool ElementoCancion::isSelected()
{
	return _marco.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(Render::getInstance().devolver())));
}

void ElementoCancion::highlight(bool x)
{
	if(x)
	{
		_marco.setFillColor(sf::Color(135, 206, 250, 1));
	}
	else
	{
		_marco.setFillColor(sf::Color::Transparent);
	}
	
}
