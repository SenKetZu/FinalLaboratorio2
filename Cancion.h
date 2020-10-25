#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include "Structs.h"
#include "Nota.h"
#include <vector>


class Cancion{

private:

	FILE* _P;
	int _offset=-0;
	std::vector<Hitpoint> _cancionRaw;
	std::vector<Nota> _cancion;
	sf::Music _sonido;
private:

	void getCancion();
	void fillCancion();

public:
	sf::Music& getSonido();
	void setOffset(int off);
	void SetCancion(const char* cancionPath);
	int getOffset();
	int getSizeRaw();
	int getSize();
	Nota getLastNota();
	std::vector<Nota>& getCancionNota();
	

	


};

