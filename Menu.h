//
// Created by krzysztof on 15.01.2020.
//
#pragma once
#include "SFML/Graphics.hpp"
#ifndef WIZARDTOWERGAME_MENU_H
#define WIZARDTOWERGAME_MENU_H

#define NumOfElements 3

class Menu {
public:
    Menu(float width, float height);
    ~Menu(){};

    void DrawMenu(sf::RenderWindow &window);
    void Up();
    void Down();

private:
    int SelectedOption;
    sf::Font font;
    sf::Text menu[NumOfElements];

#endif //WIZARDTOWERGAME_MENU_H
