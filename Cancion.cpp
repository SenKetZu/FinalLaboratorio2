#include "Cancion.h"




void Cancion::SetCancion(const char* cancionName){
	char Dir[50] = "Sources\\Songs\\";
	P = fopen(strcat(Dir,cancionName), "r");

	if (P == NULL) { std::cout << "failLoadFile"; }


}

std::vector<_puntosNotas> Cancion::getNotas(){
	std::vector<_puntosNotas> matrizNotas;
	_puntosNotas nota;
	char buffer[200];
	char* aux;
	bool hitpoins = false;

	while (fgets(buffer, 200, P)!=NULL) {

		if (!strcmp(buffer, "[HitObjects]\n")) {
			hitpoins = true;

			continue;
		}
		
		if (hitpoins) {
			aux=strtok(buffer, ",");

			nota._pos = (atoi(aux) * 4) / 512;
			
				
			strtok(NULL, ","); 
			aux=strtok(NULL, ",");
		
				
			nota._time = atoi(aux);

			matrizNotas.push_back(nota);
		}
	}
	fclose(P);
	return matrizNotas;
}
