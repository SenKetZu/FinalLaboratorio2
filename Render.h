#pragma once
#include <SFML/Graphics.hpp>
#include "Nota.h"
#include "Cancion.h"
#include "Animacion.h"
#include <vector>
#include <iostream>



class Render{
private:

	sf::Texture tx0, tx1, tx2, tx3;
	sf::RenderWindow _Ventana;
	std::vector<Nota> _cancion;
	


private:
	


public:

	Render();

	void clear();
	void mostrarFondo();
	void dibujar(const sf::Drawable& obj);
	void actualizarNotas(std::vector<Nota>& song);
	void actualizarPuntaje();
	sf::RenderWindow& devolver();
};

