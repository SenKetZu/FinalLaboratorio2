#include "Render.h"




Render::Render():_Ventana(sf::VideoMode(1200, 800), "v0.00-5!", sf::Style::Close | sf::Style::Titlebar) {
}


void Render::dibujar(sf::Sprite dibujo){
    _Ventana.draw(dibujo);
}

void Render::Update(){
    _Ventana.display();
}
