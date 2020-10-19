#pragma once
#include <SFML/Graphics.hpp>
#include "Notas.h"
#include "Cancion.h"
#include "Animacion.h"
#include <vector>



class Render{
private:

	int _delta = 0;
	int _colorAct;
	//Notas *_vecNotas;

	//sf::Sprite& _objeto;
	sf::Texture _textura;
	sf::Vector2f _posicion;
	sf::Vector2i _posMouse;
	sf::RenderWindow _Ventana;
	std::vector<sf::Texture> _texturasNotas;



public:

	Render();
	void playNota();
	void presionar();
	void playNivel();
	void dibujar(sf::Sprite dibujo);
	void Update();

};

