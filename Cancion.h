#pragma once
#include <iostream>
#include "Structs.h"
#include "Nota.h"
#include <vector>
#include "NotaRoja.h"

class Cancion{

private:

	FILE* _P;
	int _notaActual = 0, _notasAcertadas, _notasPerdidas;
	std::vector<Hitpoint> _cancionRaw;
	std::vector<Nota> _cancion;
private:

	void getCancion();
	void fillCancion();

public:

	void SetCancion(const char* cancionPath);
	Hitpoint getNota(bool siguiente=false);
	std::vector<Nota>& cancionFull();
	int getSize();
	int getNotasApretadas();
	int getNext();
	


};

