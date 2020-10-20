#pragma once
#include <SFML/Graphics.hpp>
#include "Notas.h"
#include "Cancion.h"
#include "Animacion.h"
#include <vector>
#include <iostream>



class Render{
private:

	sf::RenderWindow _Ventana;
	std::vector<Notas> _cancion;
	bool FirstTime = true;
private:
	
	
public:
	Render();
	void fondo();
	void dibujar(sf::Sprite obj);
	void dibujar(sf::RectangleShape obj);
	void clear();
	sf::RenderWindow& devolver();
	void actualizarNotas(std::vector<Notas>& song);
};

