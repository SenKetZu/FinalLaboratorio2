#include "Archivo.h"
#include <iostream>
#include "dirent.h"

#define EN_PRUEBA false


Archivo::Archivo():_directorio(opendir(_directorioDeCanciones.c_str()))
{

}


Archivo& Archivo::loadLista()
{
	std::string aux;
	

	
	// mustra todos los archivos y directorios
	//rewinddir(_directorio);
	while ((_cancion = readdir(_directorio)) != NULL) {
		if (*_cancion->d_name != '.' && *_cancion->d_name != '..') {

			
			if (!_cancionSeleccionada)
			{
				_listaCancionesRaw.push_back(_cancion->d_name);
				
				(void)strtok(_cancion->d_name, " ");


				aux = strtok(NULL, "\n");
				_listaCancionesClean.push_back(aux);
			}
			else
			{
				_ElementosDeLaCancionSeleccionada.push_back(_cancion->d_name);
			}
			

			
		}
				
			
	}
	
	
	//mostrar en depuracion
	if (EN_PRUEBA) {
		for (std::string x : _listaCancionesClean) {
			std::cout << x << std::endl;
		}
		
	}
	if (EN_PRUEBA) {
		for (std::string y : _listaCancionesRaw) {
			std::cout << y << std::endl;
		}
		
	} 
	if (true) {
		for (std::string y : _ElementosDeLaCancionSeleccionada) {
			std::cout << y << std::endl;
		}

	}
	return *this;
}



Archivo& Archivo::selectCancion(int pos)
{
	_queCancionSelecciono = pos;
	_directorioDeCanciones += _listaCancionesRaw[pos];
	_directorio=opendir(_directorioDeCanciones.c_str());
	_cancionSeleccionada = true;

	loadLista();


	return *this;
}

std::string Archivo::getDirectorioCancion()
{

	return _listaCancionesRaw[_queCancionSelecciono];
}

std::string Archivo::getNombreCancionOSU()
{
	size_t pos = 0;
	char aux[200];
	for (std::string &str:_ElementosDeLaCancionSeleccionada) {
		std::cout << str << std::endl;
		
		pos = str.find(".osu");
		if ( pos != std::string::npos) {
			return str;
		}
	}
	//std::cout << aux << "<---------" << std::endl;
}

void Archivo::cerrarDirectorio()
{
	closedir(_directorio);
}
