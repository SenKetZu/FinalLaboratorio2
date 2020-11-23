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
    int tic=0;
    _cancion.getSonido().setVolume(0);
    _cancion.getSonido().play();

    while (_mostrar.devolver().isOpen()) {
        if (tic == 60) {
            tic = 0;
        }

        while (_mostrar.devolver().pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _mostrar.devolver().close();
            }
        }
        

        inputs();
        
        

        //dibujado
        _mostrar.clear();
        _mostrar.mostrarFondo();
        _mostrar.dibujar(_trast.getTrast());
        _mostrar.actualizarNotas(_cancion.getCancionNotas());
        _mostrar.mostrarPuntaje();

        if (tic > 30) {
            _mostrar.splash();
        }
        

        _mostrar.devolver().display();


        ++tic;
    }

}

void Gameplay::inputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (!press[0]) {
            press[0] = true;
            if (_trast.isNoteColliding(_cancion.getNotas(0))){
                //aca se cambia para sumar puntos
                _mostrar.actualizarPuntaje();
                _mostrar.splash(0);
                
            }
        }
    }
    else {
        press[0] = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        if (!press[1]) {
            press[1] = true;

            if (_trast.isNoteColliding(_cancion.getNotas(1))) {
                //aca se cambia para sumar puntos
                _mostrar.actualizarPuntaje();
                _mostrar.splash(1);
               
            }
        }
    }
    else {
        press[1] = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
        if (!press[2]) {
            press[2] = true;
            if (_trast.isNoteColliding(_cancion.getNotas(2))) {
                //aca se cambia para sumar puntos
                _mostrar.actualizarPuntaje();
                _mostrar.splash(2);
                
            }
        }
    }
    else {
        press[2] = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        if (!press[3]) {
            press[3] = true;
            if (_trast.isNoteColliding(_cancion.getNotas(3))) {
                //aca se cambia para sumar puntos
                _mostrar.actualizarPuntaje();
                _mostrar.splash(3);
                
            }
        }
    }
    else {
        press[3] = false;
    }
}


