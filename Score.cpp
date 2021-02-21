#include "Score.h"

void Puntaje::setPuntaje(int puntaje)
{
	_puntaje = puntaje;
}

int Puntaje::getPuntaje()
{
	return _puntaje;
}

void Puntaje::setNombre(std::string nombre)
{
	_nombre = nombre;
}

std::string Puntaje::getNombre()
{
	return _nombre;
}
