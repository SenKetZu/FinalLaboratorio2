#pragma once
#include <iostream>
#include <vector>
#include "Structs.h"


class Cancion{
private:
	FILE* _P;

public:

	void SetCancion(const char* cancionPath);
	std::vector<_puntosNotas> getNotas();


};

