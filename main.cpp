#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gameplay.h"
#include "Archivo.h"
#include "Menu.h"





int main(){
    Render::getInstance();


    Menu obj;
    obj.menuOption();


    Gameplay obj2;
    obj2.initSong();
    return 0;

}