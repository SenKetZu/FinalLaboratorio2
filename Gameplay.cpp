#include "Gameplay.h"



void Gameplay::initSong(){
    //ciclo donde se ejecutara la cancion
    Cancion _cancion;
    Render mostrar;
    _cancion.SetCancion("kubaLoveNormal.osu");
    
    


    
    sf::Clock tiempoTranscurrido;
    while (true){


        
        
        
        
       

        

       
        



        




        //mostrar.clear();
        mostrar.fondo();
        mostrar.actualizarNotas(_cancion.cancionFull());
        
        
        
        mostrar.devolver().display();
    }






}


