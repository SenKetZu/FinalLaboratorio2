#include "Gameplay.h"



void Gameplay::initSong(){
    //ciclo donde se ejecutara la cancion
    setConfig();
    gameLoop();

}

void Gameplay::setConfig()
{
    _cancion.SetCancion("kubaLoveNormal.osu");
    
}

void Gameplay::gameLoop()
{
    
    _cancion.getSonido().play();

    while (_mostrar.devolver().isOpen()) {


        while (_mostrar.devolver().pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _mostrar.devolver().close();
            }
        }
        _trast.getTrast().setFillColor(sf::Color::Transparent);
        inputs();
        
        

        //dibujado
        _mostrar.clear();
        _mostrar.mostrarFondo();
        _mostrar.dibujar(_trast.getTrast());
        _mostrar.actualizarNotas(_cancion.getCancionNotas());

        

        _mostrar.devolver().display();
    }

}

void Gameplay::inputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (!press[0]) {
            press[0] = true;
            if (_trast.isNoteColliding(_cancion.getCancionNotas(),0)) {
                //aca se cambia para sumar puntos
                _trast.getTrast().setFillColor(sf::Color::Blue);
            }
        }
    }
    else {
        press[0] = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        if (!press[1]) {
            press[1] = true;
            if (_trast.isNoteColliding(_cancion.getCancionNotas(), 1)) {
                //aca se cambia para sumar puntos
                _trast.getTrast().setFillColor(sf::Color::Green);
            }
        }
    }
    else {
        press[1] = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
        if (!press[2]) {
            press[2] = true;
            if (_trast.isNoteColliding(_cancion.getCancionNotas(), 2)) {
                //aca se cambia para sumar puntos
                _trast.getTrast().setFillColor(sf::Color::Red);
            }
        }
    }
    else {
        press[2] = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        if (!press[3]) {
            press[3] = true;
            if (_trast.isNoteColliding(_cancion.getCancionNotas(), 3)) {
                //aca se cambia para sumar puntos
                _trast.getTrast().setFillColor(sf::Color(255, 165, 0));
            }
        }
    }
    else {
        press[3] = false;
    }
}


