#pragma once
#include <SFML/Graphics.hpp>
#include "Nota.h"
#include "Cancion.h"
#include "Animacion.h"
#include <vector>
#include <iostream>



class Render{
private:
	//Ventana principal
	sf::RenderWindow _Ventana;

	//notas
	sf::Texture _tx0, _tx1, _tx2, _tx3; 
	std::vector<Nota> _cancion;

	//fondo
	sf::RectangleShape _fondo;
	sf::Texture _fondoT;

	//texturas otras
	sf::Texture _mangoTBLUR, _mangoT, _splashT;
	sf::Sprite _mangoBLUR, _mango,_splash;
	

	sf::Font _fuente;
	sf::Text _PuntajeText;
	int _puntajeInt = 0;
	bool _seteadas = false, _sp;
	float localOffset = 527.0f;

	sf::Event _event;
private:
	Render();


public:

	static Render& getInstance() 
	{ 
		static Render instancia;
		return instancia; 
	}

	Render& clear();
	Render& mostrarFondo();
	Render& dibujar(const sf::Drawable& obj);
	Render& dibujar(std::vector<sf::Drawable*> obj);
	Render& actualizarNotas(std::vector<std::vector<Nota>>& song);
	Render& actualizarPuntaje();
	Render& mostrarPuntaje();
	Render& display();
	sf::Vector2f getSize();
	void handleEvents();
	bool isOpen();
	void close();
	void resetPuntaje();
	sf::RenderWindow& devolver();
	sf::Font& getFont();
};

