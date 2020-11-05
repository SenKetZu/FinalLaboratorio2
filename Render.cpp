#include "Render.h"







Render::Render() :_Ventana(sf::VideoMode(1280, 720), "V011", sf::Style::Default)
{ 
	_Ventana.setFramerateLimit(60);
	_fondo.setSize((sf::Vector2f(1280, 720)));
	
	_tx0.loadFromFile("Sources\\NotaAzul.png");
	_tx1.loadFromFile("Sources\\NotaVerde.png");
	_tx2.loadFromFile("Sources\\NotaRoja.png");
	_tx3.loadFromFile("Sources\\NotaNaranja.png");

	_splashT.loadFromFile("sources\\splash.png");
	_fondoT.loadFromFile("Sources\\Fondo-1.jpg");
	_mangoTBLUR.loadFromFile("Sources\\fondo_mango-recortado.png");
	_mangoT.loadFromFile("Sources\\todas_la_notas-centrada.png");
	_fuente.loadFromFile("sources\\Nightmare_Hero_Normal.ttf");
	
	_splashT.loadFromFile("sources\\splash.png");
	// fuente del texto
	_PuntajeText.setFont(_fuente);
	// tamaño de la fuente
	_PuntajeText.setCharacterSize(40);
	// posición del texto
	_PuntajeText.setPosition(400, 600);
	// cambiar el color
	_PuntajeText.setFillColor(sf::Color::Cyan); 
	
	_splash.setTexture(_splashT);
	_splash.setScale(.15, .15);
}



void Render::mostrarFondo()
{
	

	
	_fondo.setTexture(&_fondoT);
	_Ventana.draw(_fondo);
	
	_mangoBLUR.setTexture(_mangoTBLUR);
	_mangoBLUR.setScale(.7, .7);
	_mangoBLUR.setPosition(470, 0);
	
	_Ventana.draw(_mangoBLUR);

	_mango.setTexture(_mangoT);
	_mango.setScale(.65, .65);
	_mango.setPosition(500,20);
	_Ventana.draw(_mango);
	
}

void Render::dibujar(const sf::Drawable& obj) {
	_Ventana.draw(obj);
}


void Render::clear()
{
	_Ventana.clear();
}

sf::RenderWindow& Render::devolver()
{
	return _Ventana;
}

void Render::actualizarNotas(std::vector<Nota>& song){
	
	
	for (int i = 0; i < song.size();++i) {
		
		if (song[i].getAltura() > 720) {
			song[i].setOffScreen();
		}

		switch (song[i].getChanel())
		{
		case 0:
			
			song[i].addAltura().setPosition(localOffset);

			if (!_seteadas) {

				song[i].setTexture(_tx0).centrar().setScale(.25, .25);
	
				
			}
			break;

		case 1:

			song[i].addAltura().setPosition(localOffset + 64);

			if (!_seteadas) {

				song[i].setTexture(_tx1).centrar().setScale(.25, .25);
			
			}
			break;

		case 2:

			song[i].addAltura().setPosition(localOffset + 130.5);

			if (!_seteadas) {

				song[i].setTexture(_tx2).centrar().setScale(.25, .25);
				
			}

			break;

		case 3:

			song[i].addAltura().setPosition(localOffset + 191);

			if (!_seteadas) {

				song[i].setTexture(_tx3).centrar().setScale(.25, .25);
				
			}
			break;

		default:
			break;
		}

		if (song[i].getAltura()>-30&&!song[i].getOnScreen()) {
			song[i].setOnScreen();
			
		}
		if (song[i].getOnScreen()) {
			_Ventana.draw(song[i].devolver());
		}
	}
	_seteadas = true;
}

void Render::actualizarPuntaje()
{
	++_puntajeInt;
	_PuntajeText.setString(std::to_string(_puntajeInt)); 
}

void Render::mostrarPuntaje()
{
	_Ventana.draw(_PuntajeText);
}

void Render::splash(int ch)
{
	switch (ch)
	{
	case 0:
		_splash.setPosition({ localOffset-35 ,645 });
		_sp = true;
		break;
	case 1:
		_splash.setPosition({ localOffset+64-35 ,645 });
		_sp = true;
		break;
	case 2:
		_splash.setPosition({ localOffset+130-35 ,645 });
		_sp = true;
		break;
	case 3:
		_splash.setPosition({ localOffset+191-35 ,645 });
		_sp = true;
		break;


	default:
		break;
	}
	_Ventana.draw(_splash);
}

void Render::splash()
{
	if (_sp) {
		_Ventana.draw(_splash);
	}
	
}


