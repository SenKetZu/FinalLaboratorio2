#include <SFML/Graphics.hpp>
#include <iostream>
#include "Notas.h"
#include "Animacion.h"






int main(){
    

    sf::RenderWindow window(sf::VideoMode(1200,800), "v0.00-1!",sf::Style::Close| sf::Style::Titlebar);
    sf::RectangleShape fondo(sf::Vector2f(1200, 800));
    fondo.setFillColor(sf::Color::Color(150,150,150));
    



    Notas nota("NotaAzul.png");

    Animacion notaRoja(nota.devolver());
   


    //notaRoja.centrar(window);



    window.setFramerateLimit(60);
    //window.setMouseCursorVisible(false);
    //sf::sleep(sf::seconds(1));
    bool incIz = false, incDer = false;
    while (window.isOpen()){

        sf::Event event;
        
        while (window.pollEvent(event)){
            //------------------------------------Banderas-----------------------------------------------------
            sf::Vector2i posmouse;
            posmouse = sf::Mouse::getPosition(window);
            switch (event.type){

            case sf::Event::Closed:window.close(); break;

            case sf::Event::MouseButtonReleased:
                if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    incIz = false;

                }
                if (!sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    incDer = false;
                }


                break;

            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    
                    incIz = true;
                }
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    incDer = true;
                    

                }
                
                break;

  
            default:
                break;
            }            

        }
        //-----------------------------Dibujado------------------
        if (incIz) {
   
        }
        if (incDer) {
   

        }
        window.draw(fondo);
 
        //limo.dibujar(window);
        
        window.draw( nota.devolver());

        window.display();
        
    }

    return 0;
}