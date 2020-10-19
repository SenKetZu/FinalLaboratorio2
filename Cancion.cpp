#include "Cancion.h"




void Cancion::SetCancion(const char* cancionName){
	char Dir[50] = "Sources\\Songs\\";
	_P = fopen(strcat(Dir,cancionName), "r");

	if (_P == NULL) { std::cout << "failLoadFile"; }

	getCancion();
}

void Cancion::getCancion(){
	
	Hitpoint nota;
	char buffer[200];
	char* aux;
	bool hitpoins = false;

	while (fgets(buffer, 200, _P)!=NULL) {

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

			_cancion.push_back(nota);
		}
	}
	fclose(_P);
}

Hitpoint Cancion::getNota(){

	Hitpoint devolver= _cancion[_nextNota];
	++_nextNota;

	return devolver;
}

int Cancion::getSize(){
	return _cancion.size();
}

int Cancion::getNotasApretadas()
{
	return _notasAcertadas+_notasPerdidas;
}

int Cancion::getNext()
{
	return _nextNota;
}



