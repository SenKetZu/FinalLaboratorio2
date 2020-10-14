#include <SFML/Graphics.hpp>
#include <iostream>
#include "Notas.h"
#include "Animacion.h"






int main(){
    

    sf::RenderWindow Ventana(sf::VideoMode(1200,800), "v0.00-1!",sf::Style::Close| sf::Style::Titlebar);
    sf::RectangleShape fondo(sf::Vector2f(1200, 800));
    fondo.setFillColor(sf::Color::Color(150,150,150));

    sf::Vector2f tamNotas = sf::Vector2f(0.55, 0.55);



    Notas NotaAzul("NotaAzul.png",tamNotas);

    Animacion Animacion_Azul(NotaAzul.devolver());
   


    //notaRoja.centrar(window);



    Ventana.setFramerateLimit(60);
    //window.setMouseCursorVisible(false);
    //sf::sleep(sf::seconds(1));
   
    bool left_click = false;

    //este ciclo se repite por cada frame
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
                        left_click = false;

                    }
                    if (!sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

                    }
                    break;
                }

                case sf::Event::MouseButtonPressed: {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        left_click = true;

                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {



                    }
                    break;
                }
  
                default:
                    break;
                }            

        }




        //-----------------------------Dibujado------------------
        if (left_click) {
            Animacion_Azul.seguirMouse(Ventana);
        }


        Ventana.draw(fondo);
        
        Ventana.draw(NotaAzul.devolver());

        Ventana.display();
        
    }

    return 0;
}