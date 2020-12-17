#pragma once
#include <SFML/Audio.hpp>

#include "Structs.h"
#include "Nota.h"
#include <vector>


class Cancion{

private:

	FILE* _P;
	int _offset=-650;
	float _Dificultad=5;
	std::vector<Hitpoint> _cancionRaw;
	std::vector<Nota> _notasRojas, _notasVerdes, _notasAzules, _notasNaranjas;
	std::vector<std::vector<Nota>> _cancion;
	sf::Music _sonido;

private:

	char* getCancion();
	void fillCancion();

public:
	Cancion();
	void playMusic(bool y_n);
	sf::Music& getSonido();
	void setOffset(int off);
	void SetCancionOsu();
	int getOffset();
	int getSizeRaw();
	int getSize();
	std::vector<Nota>& getNotas(int ch);
	int getCantNotas();
	std::vector<std::vector<Nota>>& getCancionNotas();
	
	

	


};

