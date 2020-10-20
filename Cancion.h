#pragma once
#include <iostream>
#include "Structs.h"
#include <vector>

class Cancion{
private:
	FILE* P;

public:

	
	void SetCancion(const char* cancionPath);
	std::vector<_puntosNotas> getNotas();


};

