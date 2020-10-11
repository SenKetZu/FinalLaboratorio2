#include <SFML/Graphics.hpp>
#include <iostream>
#include "Carta.h"



class Slime {

private:
    sf::RectangleShape _izEye;
    sf::RectangleShape _derEye;
    sf::RectangleShape _bocaElMasGrande;
    sf::RectangleShape _borde;
public:
    void construir(sf::RenderWindow & pantalla);
    void mover(sf::RenderWindow & pantalla, sf::Vector2i);
    void dibujar(sf::RenderWindow &pantalla);
    void pestañeo(sf::RenderWindow &pantalla, sf::Vector2i posmaus, bool eyeOpen);


};

void Slime::construir(sf::RenderWindow &pantalla) {
    sf::Texture test;
    if (!test.loadFromFile("\Sources\\char.png")) {
        std::cout << "peruano";
    }


    _derEye.setSize(sf::Vector2f(100.f, 150.f));
    _izEye.setSize(sf::Vector2f(100.f, 150.f));
    _bocaElMasGrande.setSize(sf::Vector2f(80.f, 80.f));
    _borde.setSize(sf::Vector2f(600.f, 600.f));
    

    _izEye.setFillColor(sf::Color::Black);
    _derEye.setFillColor(sf::Color::Black);
    _bocaElMasGrande.setFillColor(sf::Color::Black);
    _borde.setFillColor(sf::Color::Green);
    _borde.setOutlineThickness(15.f);
    _borde.setOutlineColor(sf::Color::Black);

    _derEye.setTexture(&test, true);
}

void Slime::mover(sf::RenderWindow &pantalla,sf::Vector2i posmouse) {


    
    _izEye.setPosition(posmouse.x - 200, posmouse.y - 75);
    _derEye.setPosition(posmouse.x + 100, posmouse.y - 75);
    _bocaElMasGrande.setPosition(posmouse.x + 20, posmouse.y + 130);
    _borde.setPosition(posmouse.x - 300, posmouse.y - 270);

    

}

void Slime::dibujar(sf::RenderWindow &pantalla) {
    
    pantalla.draw(_borde);
    pantalla.draw(_izEye);
    pantalla.draw(_derEye);
    pantalla.draw(_bocaElMasGrande);
}

void Slime::pestañeo(sf::RenderWindow& pantalla,sf::Vector2i posmaus, bool eyeOpen) {
   
    if (eyeOpen) {
        _derEye.setPosition(sf::Vector2f(posmaus.x - 200, posmaus.y - 25));
        _izEye.setPosition(sf::Vector2f(posmaus.x + 100, posmaus.y - 25));
        _derEye.setSize(sf::Vector2f(100.f, 10.f));
        _izEye.setSize(sf::Vector2f(100.f, 10.f));

    }
    else {
        _derEye.setSize(sf::Vector2f(100.f, 150.f));
        _izEye.setSize(sf::Vector2f(100.f, 150.f));
        _derEye.setPosition(sf::Vector2f(posmaus.x - 200, posmaus.y - 75));
        _izEye.setPosition(sf::Vector2f(posmaus.x + 100, posmaus.y - 75));
    }
    



}





int main(){
    

    sf::RenderWindow window(sf::VideoMode(1200,800), "SFML works!",sf::Style::Close| sf::Style::Titlebar);
    sf::RectangleShape fondo(sf::Vector2f(1200, 800));
    fondo.setFillColor(sf::Color::Color(150,150,150));
    Carta test(window);

    test.setSize(0.5, 0.5);
   
    //limo.construir(window);
    

   // window.setMouseCursorVisible(false);
    //sf::sleep(sf::seconds(1));

    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)){
            
            sf::Vector2i posmouse;
            posmouse = sf::Mouse::getPosition(window);
            switch (event.type){

            case sf::Event::Closed:window.close(); break;

            case sf::Event::MouseMoved:
                
                posmouse = sf::Mouse::getPosition(window);
                //limo.mover(window,posmouse);

                break;

            case sf::Event::MouseButtonPressed:
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    //limo.pestañeo(window,posmouse,true);
                }
                break;

            case sf::Event::MouseButtonReleased:
               
                   // limo.pestañeo(window,posmouse,false);
  
            default:
                break;
            }                
        }
        window.clear();
        window.draw(fondo);
       
        //limo.dibujar(window);
        
        test.mostrar(window);

        window.display();
        
    }

    return 0;
}