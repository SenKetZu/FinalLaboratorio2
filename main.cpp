#include <SFML/Graphics.hpp>
#include <iostream>




class slime {

private:


public:
    void dibujarSlime();


};

void slime::dibujarSlime() {




}



int main(){


    sf::RenderWindow window(sf::VideoMode(1200,800), "SFML works!");
    sf::RectangleShape fondo(sf::Vector2f(1200.f, 800.f));
    sf::Sprite izEye;
    sf::RectangleShape derEye(sf::Vector2f(100.f, 150.f));
    sf::RectangleShape bocaElMasGrande(sf::Vector2f(80.f, 80.f));

    sf::RectangleShape borde1(sf::Vector2f(600.f, 600.f));
    sf::RectangleShape borde2(sf::Vector2f(575.f, 575.f));
    borde1.setFillColor(sf::Color::Black);
    borde2.setFillColor(sf::Color::Green);


    fondo.setFillColor(sf::Color::Green);
   // izEye.setFillColor(sf::Color::Black);
    derEye.setFillColor(sf::Color::Black);
    bocaElMasGrande.setFillColor(sf::Color::Black);

    sf::Texture sprite;



    window.setMouseCursorVisible(false);



    if (!sprite.loadFromFile("char.png")) {
        std::cout << "fail";
       
    }

    izEye.setTexture(sprite);
    
    while (window.isOpen()){
        sf::Vector2i posmouse;
        sf::Event event;
        while (window.pollEvent(event)){
            
            
            switch (event.type){

            case sf::Event::Closed:window.close(); break;

            case sf::Event::MouseMoved:
                posmouse = sf::Mouse::getPosition(window);
                izEye.setPosition(posmouse.x - 200, posmouse.y - 75);
                derEye.setPosition(posmouse.x +100, posmouse.y - 75);
                bocaElMasGrande.setPosition(posmouse.x + 20, posmouse.y +130);
                
                borde1.setPosition(posmouse.x -300, posmouse.y -270);
                borde2.setPosition(posmouse.x -290, posmouse.y -260);

                break;

            default:
                break;
            }                
        }

        window.clear();
        window.draw(fondo);

        window.draw(borde1);
        window.draw(borde2);

        window.draw(izEye);
        window.draw(derEye);
        window.draw(bocaElMasGrande);
        window.display();
    }

    return 0;
}