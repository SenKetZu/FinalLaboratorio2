#pragma once
#include "Structs.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Notas.h"

class Gameplay{
private:
	std::vector<_puntosNotas> _notasCancion;





public:
	 void setNotas(std::vector<_puntosNotas> notas);
	 void initSong();


};

