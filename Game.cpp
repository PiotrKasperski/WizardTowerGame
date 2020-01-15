//
// Created by klonek on 11.12.19.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include "Game.h"
#include "Engine.h"
#include "Menu.h"

Game::Game(sf::RenderWindow &window) {
    //Engine engine(window);
    class Menu menu(window);
}

/*void Game::gameLoop(sf::RenderWindow &window) {

    sf::RectangleShape rectangle(sf::Vector2f(64, 64));
    sf::RectangleShape rectangles[3][3];
    for(int i=0; i<3 ;i++){
        for (int j=0; j<3; j++){
            rectangles[i][j].setSize(sf::Vector2f(64,64));
            rectangles[i][j].setPosition(sf::Vector2f(i*64, j*64));
        }
    }

    rectangle.setFillColor(sf::Color::Cyan);

    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i position = sf::Mouse::getPosition(window);
            std::cout<< floor(position.x/64)  << " " << floor(position.y/64) << std::endl;
            rectangles[(int)floor(position.x/64)][(int)floor(position.y/64)].setFillColor(sf::Color::Red);

        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
            sf::Vector2i position = sf::Mouse::getPosition(window);
            std::cout<< floor(position.x/64)  << " " << floor(position.y/64) << std::endl;
            rectangles[(int)floor(position.x/64)][(int)floor(position.y/64)].setFillColor(sf::Color::Green);

        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        //update
        rectangle.setPosition(rectangle.getPosition().x+1, rectangle.getPosition().y+1);

        //render

        window.draw(rectangle);
        for(int i=0; i<3 ;i++){
            for (int j=0; j<3; j++){
                window.draw(rectangles[i][j]);
            }
        }
        window.display();

    }
}*/
