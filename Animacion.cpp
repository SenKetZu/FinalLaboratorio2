#include "Animacion.h"



Animacion::Animacion(Notas notas[4]):_objeto(notas[0].devolver()){
	
	_colorAct = 0;

	_vecNotas = notas;

	
}

void Animacion::empezarCaer() {








	//_objeto.setPosition();










}

void Animacion::seguirMouse(sf::RenderWindow& pantalla) {

	_posMouse=sf::Mouse::getPosition(pantalla);

	_objeto.setPosition(sf::Vector2f(_posMouse));


}

void Animacion::cambiarNota() {
	if (_colorAct == 3) {
		_colorAct = 0;
	}
	else {
		_colorAct++;
	}



	_objeto = _vecNotas[_colorAct].devolver();
	_objeto.setPosition(sf::Vector2f(_posMouse));
}

sf::Sprite& Animacion::devolver()
{
	return _objeto;
}



void Animacion::centrar(sf::RenderWindow& pantalla) {

	sf::Vector2u b =pantalla.getSize();
	_objeto.setPosition(b.x/2, b.y/2);
	

}