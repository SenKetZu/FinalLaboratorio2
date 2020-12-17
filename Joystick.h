#pragma once
#include "Structs.h"
#include <vector>
#include <SFML/Graphics.hpp>
class Joystick
{
public:
	
private:
	
	std::vector<KEYS> _teclasPulsadas = { NONE_KEY };
	std::vector<CLICKS> _clicksPulsados = {NONE_CLICKS};
	//azul,verde,roja,naranja,pausa
	bool estaPresionada[5] = { false };
	bool estaClickeado[3] = { false };


private:
	Joystick();
	
	
public:

	static Joystick& getInstance() {
		static Joystick instance;
		return instance;
	}
	sf::Vector2f getMousePos();
	std::vector<KEYS> checkTeclado();
	std::vector<CLICKS> checkMouse();
	bool checkClick();






	
};

