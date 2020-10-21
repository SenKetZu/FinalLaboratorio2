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
	float offset = 513.0f;

	for (auto &nota:song) {
		
		switch (nota.getChanel())
		{
		case 0:
			nota.devolver().setPosition(offset, nota.getAltura());nota.addAltura(); 
			if (nota.getAltura() > -30) {
				nota.setTexture(tx0);
				nota.devolver().setScale(.25, .25);
				nota.centrar();
				
			}
			break;
		case 1:
			nota.devolver().setPosition(offset+64, nota.getAltura());nota.addAltura();

			if (nota.getAltura() > -30) {
				nota.setTexture(tx1);
				nota.devolver().setScale(.25, .25);
				nota.centrar();
			}
			break;
		case 2:
			nota.devolver().setPosition(offset+130.5, nota.getAltura());nota.addAltura();

			if (nota.getAltura() > -30) {
				nota.setTexture(tx2);
				nota.devolver().setScale(.25, .25);
				nota.centrar();
			}
			break;
		case 3:
			nota.devolver().setPosition(offset+191, nota.getAltura());nota.addAltura();

			if (nota.getAltura() > -30) {
				nota.setTexture(tx3);
				nota.devolver().setScale(.25, .25);
				nota.centrar();
			}
			break;


		default:
			break;
		}

		_Ventana.draw(nota.devolver());




	}









}
