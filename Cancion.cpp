#include "Cancion.h"


//private
void Cancion::getCancion() {
	
	Hitpoint nota;
	char buffer[200];
	char* aux;
	bool hitpoins = false;

	while (fgets(buffer, 200, _P) != NULL) {

		if (!strcmp(buffer, "[HitObjects]\n")) {
			hitpoins = true;

			continue;
		}

		if (hitpoins) {

			aux = strtok(buffer, ",");

			nota._pos = (atoi(aux) * 4) / 512;

			strtok(NULL, ",");
			aux = strtok(NULL, ",");


			nota._time = atoi(aux)/5*-1;

			_cancionRaw.push_back(nota);
		}
	}
	fclose(_P);
}

void Cancion::fillCancion()
{
	
	for (Hitpoint nota:_cancionRaw) {

		Nota _nota;
		_nota.setAltura(nota._time);
		_nota.setChanel(nota._pos);


		_cancion.push_back(_nota);



	}
}

//public
void Cancion::SetCancion(const char* cancionName){
	char Dir[50] = "Sources\\Songs\\";
	_P = fopen(strcat(Dir,cancionName), "r");

	if (_P == NULL) { std::cout << "failLoadFile"; }

	getCancion();
	fillCancion();
}



Hitpoint Cancion::getNota(bool siguiente)
{
	Hitpoint devolver = _cancionRaw[_notaActual];
	if (siguiente) {
		++_notaActual;
	}
	return devolver;
}

std::vector<Nota>& Cancion::cancionFull()
{
	return _cancion;
}

int Cancion::getSize()
{
	return _cancionRaw.size();
}

int Cancion::getNotasApretadas()
{
	return _notasAcertadas+_notasPerdidas;
}

int Cancion::getNext()
{
	return _notaActual;
}





