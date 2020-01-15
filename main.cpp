#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


int main() {
    sf::RenderWindow app(sf::VideoMode(512, 256), "WizardTower");
    Game game(app);
    return 0;
}