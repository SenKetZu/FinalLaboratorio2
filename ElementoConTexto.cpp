#include "ElementoConTexto.h"
#include "Archivo.h"
ElementoConTexto::ElementoConTexto()
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

ElementoConTexto::ElementoConTexto(std::string text)
{
	_nombrCancion.setString(text);
}

void ElementoConTexto::setAltura(float altura)
{
	_altura = altura;
	_marco.setPosition(Render::getInstance().devolver().getSize().x / 2, altura);
	_nombrCancion.setPosition(Render::getInstance().devolver().getSize().x / 2, altura);
}

void ElementoConTexto::setNombreCancion(std::string nombre)
{
	_nombrCancion.setString(nombre);
	_nombrCancion.setOrigin(_nombrCancion.getGlobalBounds().width / 2, _nombrCancion.getGlobalBounds().height / 2);
}

bool ElementoConTexto::isOnAltura()
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

std::vector<sf::Drawable*> ElementoConTexto::getElements()
{
	//_elements.clear();
	_elements.push_back(&_marco);
	_elements.push_back(&_nombrCancion);

	return _elements;
}

bool ElementoConTexto::isSelected()
{
	return _marco.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(Render::getInstance().devolver())));
}

void ElementoConTexto::highlight(bool x)
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
