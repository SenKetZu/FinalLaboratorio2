#include "Colision.h"

Colision::Colision()
{
	_traste.setSize({ 250,30 });
	_traste.setPosition(500, 675);
	_traste.setFillColor(sf::Color::Transparent);


}

bool Colision::isColliding(sf::Sprite& obj)
{
	if (_traste.getGlobalBounds().intersects(obj.getGlobalBounds())) {
		
		return true;
	}
	return false;	
}

bool Colision::isNoteColliding(std::vector<Nota>& chanel)
{
	
	for (Nota& x : chanel) {
		if (x.getOnScreen()) {
			if (_traste.getGlobalBounds().intersects(x.devolver().getGlobalBounds())) {
				return true;
			}
		}
	}
	return false;




}

sf::RectangleShape& Colision::getTrast()
{
	return _traste;
}
