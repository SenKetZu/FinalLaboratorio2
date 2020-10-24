#include "Gameplay.h"



void Gameplay::initSong(){
    //ciclo donde se ejecutara la cancion
    
    
    while (_mostrar.devolver().isOpen()){
        

        while (_mostrar.devolver().pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _mostrar.devolver().close();
            }
        }
        

        


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            
            if (_trast.isColliding(_mostrar.getNotaActual().devolver())&& _mostrar.getNotaActual().getChanel()==0) {
                _trast.getTrast().setFillColor(sf::Color::Blue);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            if (_trast.isColliding(_mostrar.getNotaActual().devolver()) && _mostrar.getNotaActual().getChanel() == 1) {
                _trast.getTrast().setFillColor(sf::Color::Green);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            if (_trast.isColliding(_mostrar.getNotaActual().devolver()) && _mostrar.getNotaActual().getChanel() == 2) {
                _trast.getTrast().setFillColor(sf::Color::Red);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            if (_trast.isColliding(_mostrar.getNotaActual().devolver()) && _mostrar.getNotaActual().getChanel() == 3) {
                _trast.getTrast().setFillColor(sf::Color(255, 165, 0));
            }
        }
        
       

        //dibujado
        _mostrar.clear();
        _mostrar.fondo();
        _mostrar.actualizarNotas(_cancion.cancionFull());
     
        _mostrar.dibujar(_trast.getTrast());
        
        _mostrar.devolver().display();
    }






}

void Gameplay::setConfig()
{
    _cancion.SetCancion("kubaLoveNormal.osu");
    
}


