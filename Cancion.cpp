#include "Cancion.h"
#include <iostream>

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


			nota._time = ((atof(aux)/ _Dificultad)*(-1.0f))-_offset;

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
		_nota.setSpeed(16.6666666f / _Dificultad);
		switch (nota._pos)
		{
		case 0:
			_notasAzules.push_back(_nota);
			break;
		case 1:
			_notasVerdes.push_back(_nota);
			break;
		case 2:
			_notasRojas.push_back(_nota);
			break;
		case 3:
			_notasNaranjas.push_back(_nota);
			break;

		default:
			break;
		}
	}
	_cancion.push_back(_notasAzules);
	_cancion.push_back(_notasVerdes);
	_cancion.push_back(_notasRojas);
	_cancion.push_back(_notasNaranjas);

}

sf::Music& Cancion::getSonido()
{
	return _sonido;
}

void Cancion::setOffset(int off)
{
	for (std::vector<Nota> &e : _cancion) {
		for (Nota& i : e) {
			i.addAltura((off * (-1)));
		}
		
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
	_sonido.setVolume(0);
}

std::vector<std::vector<Nota>>& Cancion::getCancionNotas()
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

std::vector<Nota>& Cancion::getNotas(int ch)
{

	return _cancion[ch];
}

int Cancion::getCantNotas()
{
	int size = 0;
	for (std::vector<Nota>& e : _cancion) {

		size += e.size();
	}

	return size;
}







