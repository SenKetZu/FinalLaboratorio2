#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Render.h"
#include "Master.h"


int main(){
    sf::RenderWindow Ventana(sf::VideoMode(1200, 800), "v0.00-5!", sf::Style::Close | sf::Style::Titlebar);


    sf::Event suceso;
    while (Ventana.isOpen()) {

        //entrada
        while (Ventana.pollEvent(suceso)) {

            switch (suceso.type){

                case sf::Event::Closed:
                    Ventana.close();
                    break;


                default:break;
            }

        }




        //proceso/actualizar
        


        Ventana.draw()




    }

    

    return 0;
}