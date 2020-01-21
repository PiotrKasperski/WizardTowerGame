//
// Created by krzysztof on 15.01.2020.
//

#include "Menu.h"

Menu::Menu(float width, float height){
    if(!font.loadFromFile("arial.ttf")){
        // error
    }
    sf::FloatRect TextRect = menu[NumOfElements].getLocalBounds();
    menu[NumOfElements].setOrigin(TextRect.left + TextRect.width/2.0f, TextRect.top + TextRect.height/2.0f);

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Nowa gra");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (NumOfElements + 1 ) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Wczytaj gre");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (NumOfElements + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Wyjscie");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (NumOfElements + 1) * 3));

    SelectedOption = 0;
}



void Menu::DrawMenu(sf::RenderWindow &window)
{
    for (int i = 0; i < NumOfElements; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::Up()
{
    if (SelectedOption - 1 >= 0)
    {
        menu[SelectedOption].setColor(sf::Color::White);
        SelectedOption--;
        menu[SelectedOption].setColor(sf::Color::Red);
    }
}

void Menu::Down()
{
    if (SelectedOption + 1 < NumOfElements)
    {
        menu[SelectedOption].setColor(sf::Color::White);
        SelectedOption++;
        menu[SelectedOption].setColor(sf::Color::Red);
    }
}