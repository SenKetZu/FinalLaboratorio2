#include "Cancion.h"
#include <vector>

Cancion::Cancion(){

}

void Cancion::SetCancion(const char* cancionName){
	char Dir[50] = "Sources\\Songs\\";
	P = fopen(strcat(Dir,cancionName), "r");

	if (P == NULL) { std::cout << "failLoadFile"; }


}

int Cancion::getNotas(){
	std::vector<std::vector<int>> matrizNotas;

	char buffer[200];

	bool hitpoins = false;

	while (fgets(buffer, 200, P)!=NULL) {


		if (!strcmp(buffer,"[HitObjects]\n")) {
			hitpoins = true;
		}
		if (hitpoins) {
			
			strtok(buffer,",");

		}



	}

	fclose(P);
	return 0;
}
