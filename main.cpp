#include <SFML/Graphics.hpp>
#include <iostream>




class Slime {

private:
    sf::RectangleShape _izEye;
    sf::RectangleShape _derEye;
    sf::RectangleShape _bocaElMasGrande;
    sf::RectangleShape _borde;
public:
    void construirSlime(sf::RenderWindow & pantalla);
    void moverSlime(sf::RenderWindow & pantalla, sf::Vector2i);
    void dibujarSlime(sf::RenderWindow & pantalla);
    void pestañeoSlime();


};

void Slime::construirSlime(sf::RenderWindow &pantalla) {

    _derEye.setSize(sf::Vector2f(100.f, 150.f));
    _izEye.setSize(sf::Vector2f(100.f, 150.f));
    _bocaElMasGrande.setSize(sf::Vector2f(80.f, 80.f));
    _borde.setSize(sf::Vector2f(600.f, 600.f));
    

    _izEye.setFillColor(sf::Color::Black);
    _derEye.setFillColor(sf::Color::Black);
    _bocaElMasGrande.setFillColor(sf::Color::Black);
    _borde.setFillColor(sf::Color::Green);
    _borde.setOutlineThickness(20.f);
    _borde.setOutlineColor(sf::Color::Black);
}

void Slime::moverSlime(sf::RenderWindow &pantalla,sf::Vector2i posmouse) {


    
    _izEye.setPosition(posmouse.x - 200, posmouse.y - 75);
    _derEye.setPosition(posmouse.x + 100, posmouse.y - 75);
    _bocaElMasGrande.setPosition(posmouse.x + 20, posmouse.y + 130);

    _borde.setPosition(posmouse.x - 300, posmouse.y - 270);

    

}

void Slime::dibujarSlime(sf::RenderWindow &pantalla) {
    
    pantalla.draw(_borde);
    pantalla.draw(_izEye);
    pantalla.draw(_derEye);
    pantalla.draw(_bocaElMasGrande);
}

void Slime::pestañeoSlime() {
    
    
    
    
    _izEye.setSize
    _derEye.setSize

}





int main(){


    sf::RenderWindow window(sf::VideoMode(1200,800), "SFML works!");
    sf::RectangleShape fondo(sf::Vector2f(1200, 800));
    fondo.setFillColor(sf::Color::Green);

    Slime limo;
    limo.construirSlime(window);

    window.setMouseCursorVisible(false);
    

    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)){
            
            sf::Vector2i posmouse;
            switch (event.type){

            case sf::Event::Closed:window.close(); break;

            case sf::Event::MouseMoved:
                
                posmouse = sf::Mouse::getPosition(window);
                limo.moverSlime(window,posmouse);

                break;

            case sf::Event::MouseLeft:
                limo.pestañeoSlime();
                break;

            default:
                break;
            }                
        }
        window.clear();
        window.draw(fondo);
        limo.dibujarSlime(window);
        

        window.display();
    }

    return 0;
}