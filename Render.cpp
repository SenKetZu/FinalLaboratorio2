#include "Render.h"







Render::Render() :_Ventana(sf::VideoMode(1280, 720), "SANTI LA PUTA QUE TE PARIO", sf::Style::Default)
{ 
	_Ventana.setFramerateLimit(60);
	sf::Texture tx;
	
	tx0.loadFromFile("Sources\\NotaAzul.png");
	tx1.loadFromFile("Sources\\NotaVerde.png");
	tx2.loadFromFile("Sources\\NotaRoja.png");
	tx3.loadFromFile("Sources\\NotaNaranja.png");





}

Nota& Render::getNotaActual()
{
	return _notaAct;
}

void Render::fondo()
{
	sf::RectangleShape fondo(sf::Vector2f(1280, 720));
	sf::Texture fondoT;
	fondoT.loadFromFile("Sources\\Fondo-1.jpg");
	fondo.setTexture(&fondoT);
	_Ventana.draw(fondo);
	sf::Sprite mango;
	sf::Texture mangoT;
	mangoT.loadFromFile("Sources\\todas_la_notas-centrada.png");
	mango.setTexture(mangoT);
	mango.setScale(.65, .65);
	mango.setPosition(500,20);
	_Ventana.draw(mango);

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
	float localOffset = 513.0f;

	for (int i = 0; i < song.size();++i) {
		
		switch (song[i].getChanel())
		{
		case 0:

			song[i].setPosition(localOffset).addAltura();

			if (isNotaOnScreen(song[i])) {

				song[i].setTexture(tx0).centrar().setScale(.25, .25);				
			}
			break;
		case 1:

			song[i].setPosition(localOffset+64).addAltura();

			if (isNotaOnScreen(song[i])) {

				song[i].setTexture(tx1).centrar().setScale(.25, .25);
			}
			break;
		case 2:

			song[i].setPosition(localOffset+130.5).addAltura();

			if (isNotaOnScreen(song[i])) {

				song[i].setTexture(tx2).centrar().setScale(.25, .25);
			}
			break;
		case 3:

			song[i].setPosition(localOffset+191).addAltura();

			if (isNotaOnScreen(song[i])) {

				song[i].setTexture(tx3).centrar().setScale(.25, .25);
			}
			break;


		default:
			break;
		}
		if (song[i].getAltura()>680&& song[i].getAltura()<720) {
			_notaAct = song[i];
		}
		

		if (song[i].getAltura() > 720) {

			song.erase(song.begin()+i);
		}

		_Ventana.draw(song[i].devolver());
	}









}

void Render::actualizarPuntaje()
{
	// Creamos un objeto fuente
	sf::Font fuente;
	// Intentamos cargarla
	if (!fuente.loadFromFile("sources\\Nightmare_Hero_Normal.ttf"))
	{
		std::cout << "fail load ";
	}
	sf::RectangleShape fondo(sf::Vector2f(1280, 720));
	fondo.setFillColor(sf::Color::Black);
	// objeto texto
	sf::Text Puntaje;

	Puntaje.setString(""); // no se si anda
	// fuente del texto
	Puntaje.setFont(fuente);
	// tamaño de la fuente
	Puntaje.setCharacterSize(40);
	// posición del texto
	Puntaje.setPosition(400, 300);
	// cambiar el color
	Puntaje.setFillColor(sf::Color::Red); //aclaro que esto no se si anda

	// Dibujamos en pantalla
	
	_Ventana.draw(fondo);
	_Ventana.draw(Puntaje);
		




}

bool Render::isNotaOnScreen(Nota& nt)
{
	if (nt.getAltura() > -30) {
		return true;
	}
	return false;	
}
