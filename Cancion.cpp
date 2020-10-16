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
	using namespace std;
	while (fgets(buffer, 200, _P)!=NULL) {

		

		if (!strcmp(buffer,"[HitObjects]\n")) {
			hitpoins = true;
			continue;
		}
		
		if (hitpoins) {
			
			aux = strtok(buffer, ",");

			for (int i = 0; i < 3;++i) {
				if (i==0) {

					Nota._linea = atoi(aux) * 4 / 512;

				}
				if (i==2) {
					Nota._momento = atoi(aux);

				}
				
				aux = strtok(NULL, ",");

			}
			matrizNotas.push_back(Nota);
		}
		

	}

	fclose(_P);
	return matrizNotas;
}
