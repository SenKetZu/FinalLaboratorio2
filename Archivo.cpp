#include "Archivo.h"
#include <iostream>
#include "dirent.h"

#define EN_PRUEBA false


Archivo::Archivo():_directorio(opendir(_dir.data()))
{

}


Archivo& Archivo::loadLista()
{
	std::string aux;
	std::vector<std::string>locales;

	
	// mustra todos los archivos y directorios
	
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
				locales.push_back(_cancion->d_name);
			}
			

			
		}
				
			
	}
	closedir(_directorio);
	
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
		for (std::string y : locales) {
			std::cout << y << std::endl;
		}

	}
	return *this;
}



Archivo& Archivo::selectCancion(int pos)
{
	_dir += _listaCancionesRaw[pos];
	opendir(_dir.data());
	_cancionSeleccionada = true;




	return *this;
}
