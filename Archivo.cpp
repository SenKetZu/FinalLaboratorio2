#include "Archivo.h"
#include <iostream>
#include "dirent.h"





std::vector<std::string> Archivo::devolverLista()
{

	if ((directorio = opendir("Sources\\songs")) != NULL) {
		/* print all the files and directories within directory */
		while ((cancion = readdir(directorio)) != NULL) {
			if (*cancion->d_name != '.' && *cancion->d_name != '..')
				listaCanciones.push_back(cancion->d_name);
			
		}
		closedir(directorio);
	}
	
	for (auto x : listaCanciones) {
		std::cout << x << std::endl;
	}
	return listaCanciones;
}
