#include "Joystick.h"
#include <SFML/Graphics.hpp>
#include "Render.h"

Joystick::Joystick()
{
}

std::vector<KEYS> Joystick::checkTeclado()
{
    _teclasPulsadas.clear();
   
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (!estaPresionada[0]) {
            estaPresionada[0] = true;
            _teclasPulsadas.push_back(Blue);
        }
    }
    else {
        estaPresionada[0] = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        if (!estaPresionada[1]) {
            estaPresionada[1] = true;
            _teclasPulsadas.push_back(Green);
        }
    }
    else {
        estaPresionada[1] = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
        if (!estaPresionada[2]) {
            estaPresionada[2] = true;
            _teclasPulsadas.push_back(Red);
        }
    }
    else {
        estaPresionada[2] = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        if (!estaPresionada[3]) {
            estaPresionada[3] = true;
            _teclasPulsadas.push_back(Orange);
        }
    }
    else {
        estaPresionada[3] = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        if (!estaPresionada[4]) {
            estaPresionada[4] = true;
            _teclasPulsadas.push_back(Pause);
        }
    }
    else {
        estaPresionada[4] = false;
    }
    
    if (_teclasPulsadas.size() == 0) {
        _teclasPulsadas.push_back(NONE_KEY);
    }
	return _teclasPulsadas;
}

std::vector<CLICKS> Joystick::checkMouse()
{
    _clicksPulsados.clear();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!estaClickeado[0]) {
            estaClickeado[0] = true;
            _clicksPulsados.push_back(Left);
        }
    }
    else {
        estaClickeado[0] = false;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        if (!estaClickeado[1]) {
            estaClickeado[1] = true;
            _clicksPulsados.push_back(Right);
        }
    }
    else {
        estaClickeado[1] = false;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
        if (!estaClickeado[2]) {
            estaClickeado[2] = true;
            _clicksPulsados.push_back(Middle);
        }
    }
    else {
        estaClickeado[2] = false;
    }
    if (_clicksPulsados.size() == 0) {
        _clicksPulsados.push_back(NONE_CLICKS);
    }
    return _clicksPulsados;
}

bool Joystick::checkClick()
{

    return checkMouse()[0]==Left;
}


sf::Vector2f Joystick::getMousePos()
{
    return sf::Vector2f(sf::Mouse::getPosition(Render::getInstance().devolver()));
}
