#include "Gameplay.h"
#include "Joystick.h"
#include "ElementoConTexto.h"


Gameplay::Gameplay() {

}

void Gameplay::pause()
{



    sf::RectangleShape pauseBackground;
    pauseBackground.setSize(Render::getInstance().getSize());
    pauseBackground.setFillColor(sf::Color(50, 50, 50, 2));
    _cancion.playMusic(false);
    ElementoConTexto a;
    std::vector<ElementoConTexto> menu;// = { std::string("Continuar"),std::string("Salir") };
    menu.push_back(a);
    menu.push_back(a);



    menu[0].setNombreCancion("Continuar");
    menu[1].setNombreCancion("Salir");
    menu[0].setAltura((Render::getInstance().getSize().y / 2) - 60);
    menu[1].setAltura((Render::getInstance().getSize().y / 2) + 60);

    while (_estadoActual == Pausa) {
        Render::getInstance().handleEvents();
        showMenuPause(menu, pauseBackground);
        
        for (int i = 0; i < 2;++i) {
            if (menu[i].isSelected()) {
                menu[i].highlight(true);
                if (Joystick::getInstance().checkClick()) {
                    switch (i)
                    {
                    case 0:
                        _estadoActual = ESTADOSJUEGO::Jugando;
                        _cancion.playMusic(true);
                        return;
                        break;
                    case 1:
                        _estadoActual = ESTADOSJUEGO::Terminado;
                        
                        return;
                        break;
                    default:
                        break;
                    }
                }
            }
            else
            {
                menu[i].highlight(false);
            }
        }


        


        if (Joystick::getInstance().checkTeclado()[0] == Pause) {
            _estadoActual = Gameplay::Jugando;
            _cancion.playMusic(true);
        }
    }









}

bool Gameplay::check(KEYS tecla)
{
    bool isCorrect = false;
    isCorrect = _trast.isNoteColliding(_cancion.getNotas(tecla));
    return isCorrect;
}

void Gameplay::initSong(){
    //ciclo donde se ejecutara la cancion
    setConfig();
    _estadoActual = ESTADOSJUEGO::Jugando;
    gameLoop();
}

void Gameplay::setConfig()
{
    _cancion.SetCancionOsu();   
    _cancion.getSonido().setVolume(15);
    _cancion.getSonido().play();
}

void Gameplay::gameLoop()
{
    _tic = 0;   

    while (_estadoActual!=Terminado) {
        
        if (_tic == 61) {
            _tic = 0;
        }

        Render::getInstance().handleEvents();


        switch (_estadoActual)
        {
        case Gameplay::Jugando:
            //entrada
            inputs();
            break;
        case Gameplay::Pausa:
            pause();
            break;
        case Gameplay::Terminado:
            break;
        default:
            break;
        }
        

        
          

        //dibujado 
        
        show();

        ++_tic;
    }

}

void Gameplay::inputs()
{
    _teclaPulsada = Joystick::getInstance().checkTeclado();
    for (KEYS tecla : _teclaPulsada) {
        switch (tecla)
        {
        case Blue:case Green:case Red:case Orange:
            if (check(tecla))
            {
                Render::getInstance().actualizarPuntaje();
            }
            break;

        case Pause:
            _estadoActual = Pausa;
            
            
            break;
        default:
            break;
        }
    }

}

void Gameplay::show()
{
    Render::getInstance().clear().mostrarFondo().dibujar(_trast.getTrast());

    Render::getInstance().actualizarNotas(_cancion.getCancionNotas()).mostrarPuntaje();
   
    




    Render::getInstance().display();
}



void Gameplay::showMenuPause(std::vector<ElementoConTexto>& ele, sf::RectangleShape pauseBackground)
{
    Render::getInstance().clear();
    Render::getInstance().dibujar(pauseBackground);
    Render::getInstance().dibujar(ele[0].getElements());
    Render::getInstance().dibujar(ele[1].getElements());
    Render::getInstance().display();
}


