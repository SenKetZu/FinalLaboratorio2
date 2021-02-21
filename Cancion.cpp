#include "Cancion.h"
#include <iostream>
#include "Archivo.h"


bool Cancion::isFinished()
{
	if (_sonido.getStatus()==sf::SoundSource::Status::Stopped) {
		return true;
	}
	return false;
}

Cancion::Cancion()
{
	
}

void Cancion::playMusic(bool y_n)
{
	if(y_n)
	{
		_sonido.play();
	}
	else
	{
		_sonido.pause();
	}
	
}


//private
char* Cancion::getCancion() {
	
	Hitpoint nota;
	char buffer[200];
	char* aux, nombreWav[200];
	bool hitpoins = false,general =false ;

	while (fgets(buffer, 200, _P) != NULL) {



		if (!strcmp(buffer, "[HitObjects]\n")) {
			hitpoins = true;

			continue;
		}
		if (!strcmp(buffer, "[General]\n")) {
			general = true;

			continue;
		}


		if (general) {

			(void)strtok(buffer, ":");

			strcpy(nombreWav, strtok(NULL, "\n"));
			for (int i = 0; i < strlen(nombreWav);++i) {
				if (i != 0) {
					nombreWav[i - 1] = nombreWav[i];
				}
				if (i == strlen(nombreWav) - 1) {
					nombreWav[i] = '\0';
				}
			}
			std::cout << nombreWav << "<---"<<std::endl;


			general = false;
		}



		if (hitpoins) {

			aux = strtok(buffer, ",");

			nota._pos = (atoi(aux) * 4) / 512;

			(void)strtok(NULL, ",");
			aux = strtok(NULL, ",");


			nota._time = ((atof(aux)/ _Dificultad)*(-1.0f))-_offset;

			_cancionRaw.push_back(nota);
			

			
		}
	}

	fclose(_P);
	
	
	return nombreWav;
}

void Cancion::fillCancion()
{
	_cancion.clear();
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
void Cancion::SetCancionOsu(){

	
	char Dir[500] = "Sources\\Songs\\";
	char Dir2[200];
	strcat(Dir, Archivo::getInstance().getDirectorioCancion().c_str());
	strcat(Dir, "\\");
	strcpy(Dir2, Dir);
	strcat(Dir, Archivo::getInstance().getNombreCancionOSU().c_str());
	_P = fopen(Dir, "r");

	if (_P == NULL) { std::cout << "failLoadFile"; }


	strcat(Dir2, getCancion());
	
	fillCancion();

	_sonido.openFromFile(Dir2);
	
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







