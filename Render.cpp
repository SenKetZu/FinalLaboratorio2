#include "Render.h"







Render::Render() :_Ventana(sf::VideoMode(1280, 720), "V011", sf::Style::Default)
{ 
	_Ventana.setFramerateLimit(60);

	
	_tx0.loadFromFile("Sources\\NotaAzul.png");
	_tx1.loadFromFile("Sources\\NotaVerde.png");
	_tx2.loadFromFile("Sources\\NotaRoja.png");
	_tx3.loadFromFile("Sources\\NotaNaranja.png");

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
	_PuntajeText.setFillColor(sf::Color::Red); 
}



void Render::mostrarFondo()
{
	sf::RectangleShape fondo(sf::Vector2f(1280, 720));

	
	fondo.setTexture(&_fondoT);
	_Ventana.draw(fondo);



	
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
	float localOffset = 527.0f;
	
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


