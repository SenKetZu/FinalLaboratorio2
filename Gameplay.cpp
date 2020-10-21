#include "Gameplay.h"



void Gameplay::initSong(){
    //ciclo donde se ejecutara la cancion
    Cancion cancion;
    Render mostrar;
    cancion.SetCancion("kubaLoveNormal.osu");
    
    


    
    sf::Clock tiempoTranscurrido;
    while (mostrar.devolver().isOpen()){

        sf::Event event;
        mostrar.devolver().pollEvent(event);
        
        
        
       
       

        

       
        



        




        //mostrar.clear();
        mostrar.fondo();
        mostrar.actualizarNotas(cancion.cancionFull());
     
        
        
        mostrar.devolver().display();
    }






}


