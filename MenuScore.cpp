#include "MenuScore.h"
#include "Render.h"
#include "Joystick.h"
#include "Configuracion.h"
#include "Archivo.h"
#include <iostream>
MenuScore::MenuScore() {
	Archivo::getInstance().loadScore(_puntajes);
	_exitButton.setPointCount(3);
	_exitButton.setRadius(50);

}

void MenuScore::scoreLoop()
{
	while (!_salir)
	{
		Render::getInstance().handleEvents();

		checkExit();

		drawScores();




		
	}




}

bool MenuScore::checkExit()
{
	if (_exitButton.getGlobalBounds().contains(Joystick::getInstance().getMousePos()) && Joystick::getInstance().checkClick()) {
		return true;
	}
	return false;
}

void MenuScore::drawScores()
{
}

void MenuScore::añadirScore(int score)
{
	Puntaje aux;
	aux.setNombre(Configuracion::getInstance().getName());
	aux.setPuntaje(score);

	if (_puntajes.size() < 3) {
		
		_puntajes.push_back(aux);
	}
	else
	{
		for (int i=0;i<3;++i)
		{
			if (score > _puntajes[i].getPuntaje())
			{				
				_puntajes.insert(_puntajes.begin() + i, aux);
				_puntajes.pop_back();
			}
		}
	}
	Archivo::getInstance().saveScore(_puntajes);
}
