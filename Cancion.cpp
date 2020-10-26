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


			nota._time = (atof(aux)/5)*(-1)-_offset;

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

sf::Music& Cancion::getSonido()
{
	return _sonido;
}

void Cancion::setOffset(int off)
{
	for (Nota &e : _cancion) {
		e.addAltura((off * (-1)));
	}
}

int Cancion::getOffset()
{
	return _offset;
}

//public
void Cancion::SetCancion(const char* cancionName){
	char Dir[50] = "Sources\\Songs\\";
	_P = fopen(strcat(Dir,cancionName), "r");

	if (_P == NULL) { std::cout << "failLoadFile"; }

	getCancion();
	fillCancion();

	_sonido.openFromFile("Sources\\Songs\\MyLove.wav");
	_sonido.setVolume(10.0f);
}

std::vector<Nota>& Cancion::getCancionNotas()
{
	return _cancion;
}

int Cancion::getSizeRaw()
{
	return _cancionRaw.size();
}

int Cancion::getSize()
{
	return _cancion.size();
}

Nota Cancion::getLastNota()
{
	return _cancion[getSize()];
}







