#include "Gameplay.h"



void Gameplay::initSong(){
    //ciclo donde se ejecutara la cancion
    Cancion cancion;
    Render mostrar;
    cancion.SetCancion("kubaLoveNormal.osu");
    
    


    sf::Event event;
    sf::Clock tiempoTranscurrido;
    
    while (mostrar.devolver().isOpen()){
        
        while (mostrar.devolver().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                mostrar.devolver().close();
            }
        }
        
       

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            
            

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) {



        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)) {



        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K)) {



        }
        
       


        mostrar.clear();
        mostrar.fondo();
        mostrar.actualizarNotas(cancion.cancionFull());
     
        
        
        mostrar.devolver().display();
    }






}


