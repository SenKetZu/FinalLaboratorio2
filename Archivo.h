#pragma once
#include <iostream>
#include <Windows.h>
#include "dirent.h"
#include <vector>
class Archivo
{
private:
	DIR* directorio;
	struct dirent* cancion;
	std::vector<std::string> listaCanciones;

private:
	Archivo();

public:

	static Archivo& getInstance()
	{
		static Archivo instancia;
		return instancia;
	}

	Archivo& cargarLista();



};

