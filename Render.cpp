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
			song[i].devolver().setPosition(localOffset, song[i].getAltura()); song[i].addAltura();
			if (song[i].getAltura() > -30) {
				song[i].setTexture(tx0);
				song[i].devolver().setScale(.25, .25);
				song[i].centrar();
				
			}
			break;
		case 1:
			song[i].devolver().setPosition(localOffset+64, song[i].getAltura()); song[i].addAltura();

			if (song[i].getAltura() > -30) {
				song[i].setTexture(tx1);
				song[i].devolver().setScale(.25, .25);
				song[i].centrar();
			}
			break;
		case 2:
			song[i].devolver().setPosition(localOffset+130.5, song[i].getAltura()); song[i].addAltura();

			if (song[i].getAltura() > -30) {
				song[i].setTexture(tx2);
				song[i].devolver().setScale(.25, .25);
				song[i].centrar();
			}
			break;
		case 3:
			song[i].devolver().setPosition(localOffset+191, song[i].getAltura()); song[i].addAltura();

			if (song[i].getAltura() > -30) {
				song[i].setTexture(tx3);
				song[i].devolver().setScale(.25, .25);
				song[i].centrar();
			}
			break;


		default:
			break;
		}

		_Ventana.draw(song[i].devolver());

		if (song[i].getAltura() > 680) {

			song.erase(song.begin()+i);
		}


	}









}
