#include "Cancion.h"



void Cancion::SetCancion(const char* cancionName){
	char Dir[50] = "Sources\\Songs\\";
	_P = fopen(strcat(Dir,cancionName), "r");

	if (_P == NULL) { std::cout << "failLoadFile"; }


}

std::vector<_puntosNotas> Cancion::getNotas(){


	std::vector<_puntosNotas> matrizNotas;

	char buffer[200];

	bool hitpoins = false;

	_puntosNotas Nota;
	char* aux;

	while (fgets(buffer, 200, _P)!=NULL) {

		if (!strcmp(buffer,"[HitObjects]\n")) {
			hitpoins = true;
			continue;
		}
		if (hitpoins) {
			
		

		}

	}
	

	fclose(_P);
	return matrizNotas;
}
