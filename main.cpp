#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"

int main() {
    sf::RenderWindow app(sf::VideoMode(512, 256), "WizardTower");
   // Game game(app);
    Menu menu(app);
    menu.DrawMenu(app);
    app.display();

    sf::Event event;
    while (app.pollEvent(event)){
        switch(event.type){
            case sf::Event::KeyReleased:
                switch(event.key.code){
                    case sf::Keyboard::Up:
                        menu.Up();
                        break;
                    case sf::Keyboard::Down:
                        menu.Down();
                        break;
                }
        }
    }

    return 0;
}