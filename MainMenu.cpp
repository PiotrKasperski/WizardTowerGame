//
// Created by igor on 02.02.2020.
//

#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(float width, float height){
    if(!font.loadFromFile("Fonts/font.ttf")){
        // error
    }
    sf::FloatRect TextRect = menu[NumOfElements].getLocalBounds();
    menu[NumOfElements].setOrigin(TextRect.left + TextRect.width/2.0f, TextRect.top + TextRect.height/2.0f);
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("PO PROJEKT THE GAME");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (NumOfElements + 1 ) * 1));
    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Nowa gra");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (NumOfElements + 1) * 2));
    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Zakoncz gre");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (NumOfElements + 1) * 3));
}
void MainMenu::DrawMenu(sf::RenderWindow &window)
{
    for (int i = 0; i < NumOfElements; i++)
    {
        window.draw(menu[i]);
    }
}
void MainMenu::StartMenu(sf::RenderWindow &app) {
    DrawMenu(app);
    app.display();



    while (app.isOpen()) {
        auto mouse = sf::Mouse::getPosition(app);
        auto mouse_in_map = app.mapPixelToCoords(mouse);
        if(menu[1].getGlobalBounds().contains(mouse_in_map) &&
           sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            while(menu[1].getGlobalBounds().contains(mouse_in_map) &&
                  sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {}
            Game game(app);

        }
        if(menu[2].getGlobalBounds().contains(mouse_in_map) &&
           sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            while(menu[2].getGlobalBounds().contains(mouse_in_map) &&
                  sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {}
            app.close();

        }
    }
    app.display();
}