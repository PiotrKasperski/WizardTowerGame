#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    sf::RenderWindow app(sf::VideoMode(1024, 512), "WizardTower");
    Game game(app);
    return 0;
}