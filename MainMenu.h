//
// Created by igor on 02.02.2020.
//

#ifndef WIZARDTOWERGAME_MAINMENU_H
#define WIZARDTOWERGAME_MAINMENU_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Game.h"

int const NumOfElements = 3;
class MainMenu {
public:
    MainMenu(float width, float height);
    ~MainMenu() {};
    void DrawMenu(sf::RenderWindow &window);
    void StartMenu(sf::RenderWindow &app);
    sf::Text menu[NumOfElements];
private:
    sf::Font font;
};


#endif //WIZARDTOWERGAME_MAINMENU_H
