#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MainMenu.h"

int main() {
    sf::RenderWindow app(sf::VideoMode(1600, 900), "WizardTower");
    MainMenu menu(app.getSize().x, app.getSize().y);
    menu.StartMenu(app);
    return 0;
}