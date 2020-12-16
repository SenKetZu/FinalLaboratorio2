#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Nota.h"

class Colision
{
private:

	sf::RectangleShape _traste;




	
public:
	Colision();
	

	bool isColliding(sf::Sprite& obj);
	bool isNoteColliding(std::vector<Nota>& cancion);

	sf::RectangleShape& getTrast();

};

