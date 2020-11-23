#include "Archivo.h"
#include <iostream>
#include "dirent.h"



Archivo::Archivo():directorio(opendir("Sources\\songs"))
{

}


Archivo& Archivo::cargarLista()
{
	std::string aux;
	
	// mustra todos los archivos y directorios

	while ((cancion = readdir(directorio)) != NULL) {
		if (*cancion->d_name != '.' && *cancion->d_name != '..') {
			(void)strtok(cancion->d_name, " ");
			aux = strtok(NULL, "");

			listaCanciones.push_back(aux);
		}
				
			
	}
	closedir(directorio);
	
	
	for ( std::string x : listaCanciones) {
		std::cout << x << std::endl;
	}
	return *this;
}
