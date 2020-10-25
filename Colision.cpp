#include "Colision.h"

Colision::Colision()
{
	_traste.setSize({ 250,50 });
	_traste.setPosition(500, 640);



}

bool Colision::isColliding(sf::Sprite& obj)
{
	if (_traste.getGlobalBounds().intersects(obj.getGlobalBounds())) {
		
		return true;
	}
	return false;	
}

sf::RectangleShape& Colision::getTrast()
{
	return _traste;
}
