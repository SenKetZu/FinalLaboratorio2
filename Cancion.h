#pragma once
#include <iostream>
#include "Structs.h"
#include "Nota.h"
#include <vector>


class Cancion{

private:

	FILE* _P;
	int _offset=0;
	std::vector<Hitpoint> _cancionRaw;
	std::vector<Nota> _cancion;

private:

	void getCancion();
	void fillCancion();

public:

	void setOffset(int off);
	int getOffset();
	void SetCancion(const char* cancionPath);
	std::vector<Nota>& cancionFull();
	int getSize();
	


};

