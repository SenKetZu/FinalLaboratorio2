#pragma once
#include <iostream>
#include "Structs.h"
#include "Notas.h"
#include <vector>

class Cancion{

private:

	FILE* _P;
	int _notaActual = 0, _notasAcertadas, _notasPerdidas;
	std::vector<Hitpoint> _cancionRaw;
	std::vector<Notas> _cancion;
private:

	void getCancion();
	void fillCancion();

public:

	void SetCancion(const char* cancionPath);
	Hitpoint getNota(bool siguiente=false);
	std::vector<Notas>& cancionFull();
	int getSize();
	int getNotasApretadas();
	int getNext();
	void presionarNota();


};

