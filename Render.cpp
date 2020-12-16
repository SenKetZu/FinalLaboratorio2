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
	_fuente.loadFromFile("sources\\fuentes\\Nightmare_Hero_Normal.ttf");




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



Render& Render::mostrarFondo()
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
	
	return *this;
}

Render& Render::dibujar(const sf::Drawable& obj) {
	_Ventana.draw(obj);
	return *this;
}

Render& Render::dibujar(std::vector<sf::Drawable*> obj)
{
	for (auto  *element:obj) {
		
		_Ventana.draw(*element);
	}
	return *this;
}


Render& Render::clear()
{
	_Ventana.clear();

	return *this;
}

sf::RenderWindow& Render::devolver()
{
	return _Ventana;

}

sf::Font& Render::getFont()
{
	return _fuente;
}

Render& Render::actualizarNotas(std::vector<std::vector<Nota>>& song){
	
	
	for (int i = 0; i < 4;++i) {
		for (int j = 0; j < song[i].size(); ++j) {

			if (song[i][j].getAltura() > 720) {
				song[i][j].setOffScreen();
			}

			switch (song[i][j].getChanel())
			{
			case 0:

				song[i][j].addAltura().setPosition(localOffset);

				if (!_seteadas) {

					song[i][j].setTexture(_tx0).centrar().setScale(.25, .25);


				}
				break;

			case 1:

				song[i][j].addAltura().setPosition(localOffset + 64);

				if (!_seteadas) {

					song[i][j].setTexture(_tx1).centrar().setScale(.25, .25);

				}
				break;

			case 2:

				song[i][j].addAltura().setPosition(localOffset + 130.5);

				if (!_seteadas) {

					song[i][j].setTexture(_tx2).centrar().setScale(.25, .25);

				}

				break;

			case 3:

				song[i][j].addAltura().setPosition(localOffset + 191);

				if (!_seteadas) {

					song[i][j].setTexture(_tx3).centrar().setScale(.25, .25);

				}
				break;

			default:
				break;
			}

			if (song[i][j].getAltura() > -30 && !song[i][j].getOnScreen()) {
				song[i][j].setOnScreen();

			}
			if (song[i][j].getOnScreen()) {
				_Ventana.draw(song[i][j].devolver());
			}

		}
	
	}
	_seteadas = true;
	return *this;
}

Render& Render::actualizarPuntaje()
{
	++_puntajeInt;
	_PuntajeText.setString(std::to_string(_puntajeInt)); 
	return *this;
}

Render& Render::mostrarPuntaje()
{
	_Ventana.draw(_PuntajeText);
	return *this;
}

Render& Render::display()
{
	_Ventana.display();
	return *this;
}

sf::Vector2f Render::getSize()
{
	return sf::Vector2f(_Ventana.getSize());
}

void Render::handleEvents()
{
	while (_Ventana.pollEvent(_event)) {
		if (_event.type == sf::Event::Closed) {
			Render::getInstance().devolver().close();
		}
	}






}

bool Render::isOpen()
{

	return _Ventana.isOpen();

}

void Render::close()
{
	_Ventana.close();
}




