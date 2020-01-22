#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"

int main() {
    sf::RenderWindow app(sf::VideoMode(512, 256), "WizardTower");
   // Game game(app);
    Menu menu(app.getSize().x, app.getSize().y);

    menu.DrawMenu(app);
    app.display();


    while (app.isOpen()) {
        sf::Event event;
        while (app.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.Up();
                            break;
                        case sf::Keyboard::Down:
                            menu.Down();
                            break;
                        case sf::Keyboard::Escape:
                            app.close();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem())
                            {
                                case 0:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    break;
                                case 1:
                                    std::cout << "Option button has been pressed" << std::endl;
                                    break;
                                case 2:
                                    std::cout << "Exit game button has been pressed" << std::endl;
                                    app.close();
                                    break;
                            }

                    }

            }

        }
    }
    app.display();
    //return 0;
}