#include <SFML/Graphics.hpp>
#include <iostream>
#include "Notas.h"
#include "Animacion.h"






int main(){
    srand(time(NULL));

    sf::RenderWindow Ventana(sf::VideoMode(1200,800), "v0.00-1!",sf::Style::Close| sf::Style::Titlebar);
    sf::RectangleShape fondo(sf::Vector2f(1200, 800));
    sf::Texture textFondo;
    sf::Texture textMango;
    sf::Sprite mango;

    textFondo.loadFromFile("Sources\\Fondo-1.jpg");
    fondo.setTexture(&textFondo);
    textMango.loadFromFile("Sources\\todas_la_notas.png");
    mango.setTexture(textMango);
    mango.setScale(0.7, 0.7);
    fondo.setFillColor(sf::Color::Color(150,150,150));

    sf::Vector2f tamNotas = sf::Vector2f(0.3, 0.3);



    Notas NotaAzul("NotaAzul.png",tamNotas);
    Notas NotaRoja("NotaRoja.png", tamNotas);
    Notas NotaVerde("NotaVerde.png", tamNotas);
    Notas NotaNaranja("NotaNaranja.png", tamNotas);


    Notas notas[4] = { NotaVerde ,NotaRoja ,NotaNaranja ,NotaAzul };

    Animacion animarNotas(notas);
   


    //notaRoja.centrar(window);



    Ventana.setFramerateLimit(60);
    //window.setMouseCursorVisible(false);
    //sf::sleep(sf::seconds(1));
   
    bool left_click = false,rigth_click=false;

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
                        rigth_click = false;

                    }
                    
                }

                case sf::Event::MouseButtonPressed: {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        std::cout << "asd" << std::endl;
                        left_click = true;

                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                        
                        std::cout << "asd" << std::endl;
                        rigth_click = true;
                        

                    }
                    break;
                }
  
                default:
                    break;
            }            

        }




        //-----------------------------Dibujado------------------

        if (left_click) {
            animarNotas.seguirMouse(Ventana);
        }
        
        if (rigth_click) {
            sf::sleep(sf::milliseconds(500));
            animarNotas.cambiarNota();
            
        }
        

        Ventana.draw(fondo);

        Ventana.draw(mango);

        Ventana.draw(animarNotas.devolver());

        Ventana.display();
        
    }

    return 0;
}