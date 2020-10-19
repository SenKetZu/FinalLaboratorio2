#include <SFML/Graphics.hpp>
#include <iostream>
#include "Notas.h"
#include "Animacion.h"
#include "Cancion.h"




int main(){
    sf::RenderWindow Ventana(sf::VideoMode(800, 600), "title", sf::Style::Default);
    //este ciclo se repite por cada frame

    Cancion test;
    test.SetCancion("kubaLoveNormal.osu");
    test.getNotas();





    while (Ventana.isOpen()){
 
        sf::Event event;
        
        while (Ventana.pollEvent(event)){
            //------------------------------------Banderas-----------------------------------------------------
            sf::Vector2i posmouse;
            posmouse = sf::Mouse::getPosition(Ventana);
            switch (event.type){

                case sf::Event::Closed: Ventana.close(); break;

                case sf::Event::MouseButtonReleased: {
                    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        //left_click = false;

                    }
                    if (!sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                        //rigth_click = false;

                    }
                    
                }

                case sf::Event::MouseButtonPressed: {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        std::cout << "asd" << std::endl;
                        //left_click = true;

                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                        
                        std::cout << "asd" << std::endl;
                        //rigth_click = true;
                        

                    }
                    break;
                }
  
                default:
                    break;
            }            

        }




        //-----------------------------Dibujado------------------
/*
if (left_click) {
            animarNotas.seguirMouse(Ventana);
        }

        if (rigth_click) {
            sf::sleep(sf::milliseconds(500));
            animarNotas.cambiarNota();

        }


        Ventana.draw(fondo);

        Ventana.draw(mangoBlur);

        Ventana.draw(mango);

        Ventana.draw(animarNotas.devolver());
*/
        

        Ventana.display();
        
    }

    return 0;
}