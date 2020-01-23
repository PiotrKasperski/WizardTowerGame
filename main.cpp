#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    sf::RenderWindow app(sf::VideoMode(500, 500), "WizardTower");
    Game game(app);
    return 0;
}