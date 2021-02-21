#pragma once
#include "Score.h"
#include <vector>
#include <SFML/Graphics.hpp>

class MenuScore
{
private:
	sf::CircleShape _exitButton;
	sf::RectangleShape _cuadroPuntaje[3];
	std::vector<Puntaje> _puntajes;
	bool _salir = false;
public:
	MenuScore();
	void scoreLoop();
	bool checkExit();
	void drawScores();
	void añadirScore(int score);

};

