#pragma once
#include <iostream>
#include <Windows.h>
#include "dirent.h"
#include <vector>
#include "Structs.h"

class Archivo
{
private:
	std::string _directorioDeCanciones = "Sources\\songs\\";
	DIR* _directorio;
	FILE* _P;
	struct dirent* _cancion;
	std::vector<std::string> _listaCancionesClean, _listaCancionesRaw;
	std::vector<Hitpoint> _cancionHits;
	std::vector<std::string>_ElementosDeLaCancionSeleccionada;
	bool _cancionSeleccionada = false;
	int _queCancionSelecciono = 0;

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
	
	std::string getDirectorioCancion();
	std::string getNombreCancionOSU();
	std::vector<Hitpoint> getCancion() { return _cancionHits; }
	std::vector<std::string> getListaNombres() { return _listaCancionesClean; }

	void cerrarDirectorio();
};

