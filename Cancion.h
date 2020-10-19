#pragma once
#include <iostream>
#include "Structs.h"
#include <vector>

class Cancion{

private:

	FILE* _P;
	int _nextNota = 0, _notasAcertadas, _notasPerdidas;
	std::vector<Hitpoint> _cancion;

public:

	void SetCancion(const char* cancionPath);
	Hitpoint getNota();
	int getSize();
	int getNotasApretadas();
	int getNext();

private:

	void getCancion();

};

