#pragma once
#include <string>

class Puntaje
{
private:
	int _puntaje;
	std::string _nombre;
public:
	void setPuntaje(int puntaje);
	int getPuntaje();

	void setNombre(std::string nombre);
	std::string getNombre();
};

