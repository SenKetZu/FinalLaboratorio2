#pragma once
#include <SFML/Graphics.hpp>
class Colision
{
private:

	sf::RectangleShape _traste;





public:
	Colision();
	bool isColliding(sf::Sprite& obj);
	sf::RectangleShape& getTrast();

};

