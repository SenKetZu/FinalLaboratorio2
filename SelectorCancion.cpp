#include "SelectorCancion.h"
#include "Archivo.h"
#include "Joystick.h"


SelectorCancion::SelectorCancion():_flechaArriva(25,3), _flechaAbajo(25,3)
{
	Archivo::getInstance().loadLista();
	_background.setSize(sf::Vector2f(Render::getInstance().getSize()));
	if (_backTexture.loadFromFile("Sources\\backSelector2.jpg")) {
		std::cout << "carga con exito" << std::endl;
	}
	else
	{
		std::cout << "error" << std::endl;
	}
	_background.setTexture(&_backTexture);
	//centrar el origen
	_flechaArriva.setOrigin(sf::Vector2f(_flechaArriva.getGlobalBounds().height / 2, _flechaArriva.getGlobalBounds().width / 2));
	_flechaArriva.setPosition(sf::Vector2f(Render::getInstance().devolver().getSize().x / 2, 30));
	_flechaArriva.setOutlineColor(sf::Color::Red);
	_flechaArriva.setOutlineThickness(2);
	_flechaArriva.setFillColor(sf::Color::Transparent);

	_flechaAbajo.setOrigin(sf::Vector2f(_flechaAbajo.getGlobalBounds().height / 2, _flechaAbajo.getGlobalBounds().width / 2));
	_flechaAbajo.rotate(180.0f);	
	_flechaAbajo.setPosition(sf::Vector2f(Render::getInstance().devolver().getSize().x / 2, Render::getInstance().devolver().getSize().y - 30));
	_flechaAbajo.setOutlineColor(sf::Color::Red);
	_flechaAbajo.setOutlineThickness(2);
	_flechaAbajo.setFillColor(sf::Color::Transparent);


	for (std::string nombre : Archivo::getInstance().getListaNombres()) {

		ElementoConTexto aux;
		aux.setNombreCancion(nombre);
		aux.setAltura(_alturaOffset);
		_elements.push_back(aux);
		_alturaOffset += _spaceBtwn;

	}
	_alturaOffset = 100.0f;
}

void SelectorCancion::selectorLoop()
{

	while (!_cancion) {
	
		Render::getInstance().handleEvents();
	
		//std::cout << _alturaOffset << std::endl;
		
		
	
	
		checkHighlight();
		checkPress();
		
		Render::getInstance().clear().dibujar(_background).dibujar(_flechaAbajo).dibujar(_flechaArriva);
		

		




		
		for (ElementoConTexto& el : _elements) {
			if(el.isOnAltura())
			Render::getInstance().dibujar(el.getElements());
		}
		Render::getInstance().display();	
	}
	_cancion = false;
}

void SelectorCancion::checkHighlight()
{
	//FLECHAS
	if (_flechaArriva.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(Render::getInstance().devolver())))) {
		_flechaArriva.setFillColor(sf::Color(135, 206, 250, 100));
	}
	else
	{
		_flechaArriva.setFillColor(sf::Color::Transparent);
	}
	if (_flechaAbajo.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(Render::getInstance().devolver())))) {
		_flechaAbajo.setFillColor(sf::Color(135, 206, 250, 100));
	}
	else
	{
		_flechaAbajo.setFillColor(sf::Color::Transparent);
	}
	//ELEMENTOS
	for (ElementoConTexto& el : _elements)
	{
		if (el.isSelected()) {
			el.highlight(true);
		}
		else
		{
			el.highlight(false);
		}
	}

}

void SelectorCancion::checkPress()
{


	if (Joystick::getInstance().checkMouse()[0] == Left) {

		//FLECHAS
		if (_flechaArriva.getGlobalBounds().contains(Joystick::getInstance().getMousePos()) && _alturaOffset < 100) {
			_alturaOffset += _spaceBtwn;
			relocateElements();
		}
		if (_flechaAbajo.getGlobalBounds().contains(Joystick::getInstance().getMousePos()) && _alturaOffset > ((_elements.size() - 5) * _spaceBtwn * -1)) {
			_alturaOffset -= _spaceBtwn;
			relocateElements();
		}
		//ELEMENTOS
		for (int i = 0; i < _elements.size(); ++i)
		{
			if (_elements[i].isSelected() && _elements[i].isOnAltura())
			{
				Archivo::getInstance().selectCancion(i);
				_cancion = true;

			}
		}
	}
	
	
}

void SelectorCancion::relocateElements()
{
	float altTemp = _alturaOffset;
	for (ElementoConTexto &el : _elements) {
		el.setAltura(_alturaOffset);
		_alturaOffset += _spaceBtwn;
	}
	_alturaOffset = altTemp;
}
