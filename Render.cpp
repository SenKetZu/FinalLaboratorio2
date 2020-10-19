#include "Render.h"


Render::Render():_Ventana(sf::VideoMode(800,600),"SANTI LA PUTA QUE TE PARIO",sf::Style::Default) {/*equisde*/}

void Render::dibujar(sf::Sprite obj) {
	_Ventana.draw(obj);
}

void Render::dibujar(sf::RectangleShape obj) {
	_Ventana.draw(obj);
}
