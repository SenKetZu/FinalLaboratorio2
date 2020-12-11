#include "Gameplay.h"


Gameplay::Gameplay() {

}

void Gameplay::initSong(){
    //ciclo donde se ejecutara la cancion
    setConfig();
    gameLoop();
}

void Gameplay::setConfig()
{
    _cancion.SetCancion("Kuba Oms - My Love (W h i t e) [Normal].osu");   
    _cancion.getSonido().setVolume(15);
    _cancion.getSonido().play();
}

void Gameplay::gameLoop()
{
    _tic = 0;   

    while (Render::getInstance().devolver().isOpen()) {
        
        if (_tic == 61) {
            _tic = 0;
        }

        while (Render::getInstance().devolver().pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                Render::getInstance().devolver().close();
            }
        }
        
        //entrada
        inputs();   

        //dibujado
        show();


        ++_tic;
    }

}

void Gameplay::inputs()
{

    //tecla azul
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (!press[0]) {
            press[0] = true;
            if (_trast.isNoteColliding(_cancion.getNotas(0))){
                //aca se cambia para sumar puntos
                Render::getInstance().actualizarPuntaje();
                
                
            }
        }
    }
    else {
        press[0] = false;
    }



    //tecla verde
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        if (!press[1]) {
            press[1] = true;

            if (_trast.isNoteColliding(_cancion.getNotas(1))) {
                //aca se cambia para sumar puntos
                Render::getInstance().actualizarPuntaje();
                
               
            }
        }
    }
    else {
        press[1] = false;
    }


    //tecla rojo
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
        if (!press[2]) {
            press[2] = true;
            if (_trast.isNoteColliding(_cancion.getNotas(2))) {
                //aca se cambia para sumar puntos
                Render::getInstance().actualizarPuntaje();
                
                
            }
        }
    }
    else {
        press[2] = false;
    }


    //tecla naranja
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        if (!press[3]) {
            press[3] = true;
            if (_trast.isNoteColliding(_cancion.getNotas(3))) {
                //aca se cambia para sumar puntos
                Render::getInstance().actualizarPuntaje();
                
                
            }
        }
    }
    else {
        press[3] = false;
    }
}

void Gameplay::show()
{
    Render::getInstance().clear();
    Render::getInstance().mostrarFondo();
    Render::getInstance().dibujar(_trast.getTrast());
    Render::getInstance().actualizarNotas(_cancion.getCancionNotas());
    Render::getInstance().mostrarPuntaje();




    Render::getInstance().devolver().display();
}


