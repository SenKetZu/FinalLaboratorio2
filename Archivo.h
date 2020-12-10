#pragma once
#include <iostream>
#include <Windows.h>
#include "dirent.h"
#include <vector>
#include "Structs.h"

class Archivo
{
private:
	std::string _dir = "Sources\\songs\\";
	DIR* _directorio;
	FILE* _P;
	struct dirent* _cancion;
	std::vector<std::string> _listaCancionesClean, _listaCancionesRaw;
	std::vector<Hitpoint> _cancionHits;
	bool _cancionSeleccionada = false;

private:
	Archivo();

public:

	static Archivo& getInstance()
	{
		static Archivo instancia;
		return instancia;
	}

	Archivo& loadLista();

	Archivo& selectCancion(int pos);
	std::vector<Hitpoint> getCancion() { return _cancionHits; }
	std::vector<std::string> getListaNombres() { return _listaCancionesClean; }

};

