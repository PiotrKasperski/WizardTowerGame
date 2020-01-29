//
// Created by igor on 23.01.2020.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "InventoryGui.h"
void InventoryGui::initFont() {
    this->font.loadFromFile("../Fonts/font.ttf");
}
InventoryGui::InventoryGui(Player* player) {
    this->initFont();
    this->drawInv = false;
    this->player  = player;

    this->invDialog.setSize(sf::Vector2f(128 , 19));
    this->invDialog.setFillColor(sf::Color::Blue);
    this->invTexture.loadFromFile("../assets/textures/stat.png");
    this->invSprite.setTexture(invTexture);
}
InventoryGui::~InventoryGui() = default;


void InventoryGui::Update(sf::RenderWindow &window) {
    // wypelnianie wektora itemami (pelny obiekt)
    // bedzie jakies player get equipment funkcja
    InventoryGui::invToDraw = player->PlayerEq;
    InventoryGui::position.clear();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {}
        this->drawInv = !this->drawInv;
    }
    // wypelnianie wektora position textem do wypisania
    for (size_t i = 0 ; i < InventoryGui::invToDraw.size() ; i++)
    {
        sf::Text textInPos;
        textInPos.setFont(InventoryGui::font);
        textInPos.setString(InventoryGui::invToDraw[i]->name);
        textInPos.setCharacterSize(20);
        textInPos.setPosition(player->getPosition().x - 100 , player->getPosition().y - (InventoryGui::invToDraw.size() * 25) / 2 + (i * 25));
        if(InventoryGui::invToDraw[i]->isEquiped){
            textInPos.setFillColor(sf::Color::Green);
        }
        InventoryGui::position.push_back(textInPos);
    }
    backToGameText.setFont(InventoryGui::font);
    backToGameText.setString("WROC");
    backToGameText.setCharacterSize(20);
    backToGameText.setPosition(player->getPosition().x - 100 , player->getPosition().y + 100 );

}

void InventoryGui::Draw(sf::RenderWindow &window)
{
    if(this->drawInv) {
        this->invSprite.setPosition(sf::Vector2f(player->getPosition().x - 128, player->getPosition().y - 160));
        this->invDialog.setPosition(sf::Vector2f(player->getPosition().x - 64, player->getPosition().y - 8));
        auto mouse = sf::Mouse::getPosition(window);
        auto mouse_in_map = window.mapPixelToCoords(mouse);


        for(auto &pos : InventoryGui::position) {
            if(pos.getGlobalBounds().contains(mouse_in_map) &&
               sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                while(pos.getGlobalBounds().contains(mouse_in_map) &&
                      sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {}
                for(auto &eq : InventoryGui::invToDraw) {
                    if(pos.getString() == eq->name){
                        eq->use(player->PlayerEq);
                    }
                }
                }
            }
        if(backToGameText.getGlobalBounds().contains(mouse_in_map) &&
           sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            while(backToGameText.getGlobalBounds().contains(mouse_in_map) &&
                  sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {}
            this->drawInv = !this->drawInv;
        }
        window.draw(this->invSprite);
        for(auto &pos : InventoryGui::position) {
            window.draw(pos);
        }
        window.draw(backToGameText);
    }

}