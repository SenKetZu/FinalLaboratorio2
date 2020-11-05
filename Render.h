#pragma once
#include <SFML/Graphics.hpp>
#include "Nota.h"
#include "Cancion.h"
#include "Animacion.h"
#include <vector>
#include <iostream>



class Render{
private:

	sf::Texture _tx0, _tx1, _tx2, _tx3, _fondoT, _mangoTBLUR, _mangoT,_splashT;
	sf::RenderWindow _Ventana;
	std::vector<Nota> _cancion;
	sf::Sprite _mangoBLUR, _mango,_splash;
	sf::RectangleShape _fondo;
	sf::Font _fuente;
	sf::Text _PuntajeText;
	int _puntajeInt = 0;
	bool _seteadas = false, _sp;
	float localOffset = 527.0f;
private:
	


public:

	Render();

	void clear();
	void mostrarFondo();
	void dibujar(const sf::Drawable& obj);
	void actualizarNotas(std::vector<Nota>& song);
	void actualizarPuntaje();
	void mostrarPuntaje();
	void splash(int ch);
	void splash();
	sf::RenderWindow& devolver();
};

