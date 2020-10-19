#include "Gameplay.h"



void Gameplay::initSong(){
    //ciclo donde se ejecutara la cancion
    Cancion _cancion;
    Render mostrar;
    _cancion.SetCancion("kubaLoveNormal.osu");
    
    


    sf::Clock tiempo;

    while (_cancion.getSize()>_cancion.getNotasApretadas()){
        sf::Int32 transcurrido = tiempo.getElapsedTime().asMilliseconds();






        if (transcurrido < _cancion.getNota()._time) {
            
            mostrar.actualizarNotas(notasEnPantalla);


        }








    }






}
