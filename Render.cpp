#include "Render.h"




Render::Render() :_Ventana(sf::VideoMode(1280, 720), "SANTI LA PUTA QUE TE PARIO", sf::Style::Default)
{ 
	_Ventana.setFramerateLimit(60);
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

void Render::dibujar(sf::Sprite obj) {
	_Ventana.draw(obj);
}

void Render::dibujar(sf::RectangleShape obj)
{
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

void Render::actualizarNotas(std::vector<Notas>& song){

	
	for (Notas &nota:song) {
		if (true) {

			_Ventana.draw(nota.devolver());

		}
		switch (nota.getChanel())
		{
		case 0:nota.devolver().setPosition(515, nota.getAltura()); nota.addAltura(); break;
		case 1:nota.devolver().setPosition(580, nota.getAltura()); nota.addAltura(); break;
		case 2:nota.devolver().setPosition(645, nota.getAltura()); nota.addAltura(); break;
		case 3:nota.devolver().setPosition(707, nota.getAltura()); nota.addAltura(); break;


		default:
			break;
		}


		std::cout << "SATY PUTO ";



	}









}
