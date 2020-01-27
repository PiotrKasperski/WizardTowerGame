//
// Created by igor on 24.01.2020.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "LootGui.h"
void LootGui::initFont() {
    this->font.loadFromFile("Fonts/font.ttf");
}
LootGui::LootGui(Player* player) {
    this->initFont();
    this->drawLoot = false;
    this->player  = player;
    this->invDialog.setSize(sf::Vector2f(128 , 19));
    this->invDialog.setFillColor(sf::Color::Blue);
    this->invTexture.loadFromFile("assets/textures/stat.png");
    this->invSprite.setTexture(invTexture);
    this->lootDialog.setSize(sf::Vector2f(128 , 19));
    this->invDialog.setFillColor(sf::Color::Blue);
    this->lootSprite.setTexture(invTexture);

    testWeapon = new Weapon("loot bron", false, 10, 10);
    testWeapon2 = new Weapon("loot n bron", false, 10, 10);
    testArmor = new Armor("loot zbroja", false, 10, 10);
    lootToDraw.push_back(testWeapon);
    lootToDraw.push_back(testWeapon2);
    lootToDraw.push_back(testArmor);

}
LootGui::~LootGui() = default;


void LootGui::Update(sf::RenderWindow &window) {
    // wypelnianie wektora itemami (pelny obiekt)
    // bedzie jakies player get equipment funkcja
    LootGui::invToDraw = player->PlayerEq;
    LootGui::positionInvText.clear();
    LootGui::positionLootText.clear();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {}
        this->drawLoot = !this->drawLoot;
    }
    // wypelnianie wektora position textem do wypisania inventory
    for (size_t i = 0 ; i < LootGui::invToDraw.size() ; i++)
    {
        sf::Text textInPosInv;
        textInPosInv.setFont(LootGui::font);
        textInPosInv.setString(LootGui::invToDraw[i]->name);
        textInPosInv.setCharacterSize(20);
        textInPosInv.setPosition(player->getPosition().x - 100 , player->getPosition().y - (LootGui::invToDraw.size() * 25) / 2 + (i * 25));
        if(LootGui::invToDraw[i]->isEquiped){
            textInPosInv.setFillColor(sf::Color::Green);
        }
        LootGui::positionInvText.push_back(textInPosInv);
    }    // wypelnianie wektora position textem do wypisania lootu
    for (size_t i = 0 ; i < LootGui::lootToDraw.size() ; i++)
    {
        sf::Text textInPosLoot;
        textInPosLoot.setFont(LootGui::font);
        textInPosLoot.setString(LootGui::lootToDraw[i]->name);
        textInPosLoot.setCharacterSize(20);
        textInPosLoot.setPosition(player->getPosition().x + 200 , player->getPosition().y - (LootGui::lootToDraw.size() * 25) / 2 + (i * 25));
        LootGui::positionLootText.push_back(textInPosLoot);
    }
    backToGameText.setFont(LootGui::font);
    backToGameText.setString("WROC");
    backToGameText.setCharacterSize(20);
    backToGameText.setPosition(player->getPosition().x - 100 , player->getPosition().y + 100 );

}

void LootGui::Draw(sf::RenderWindow &window)
{
    if(this->drawLoot) {
        this->invSprite.setPosition(sf::Vector2f(player->getPosition().x - 128, player->getPosition().y - 160));
        this->invDialog.setPosition(sf::Vector2f(player->getPosition().x - 64, player->getPosition().y - 8));
        this->lootSprite.setPosition(sf::Vector2f(player->getPosition().x + 128, player->getPosition().y - 160));
        this->lootDialog.setPosition(sf::Vector2f(player->getPosition().x + 64, player->getPosition().y - 8));
        auto mouse = sf::Mouse::getPosition(window);
        auto mouse_in_map = window.mapPixelToCoords(mouse);


        for(auto &pos : LootGui::positionInvText) {
            if(pos.getGlobalBounds().contains(mouse_in_map) &&
               sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                while(pos.getGlobalBounds().contains(mouse_in_map) &&
                      sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {}
                for(auto &eq : LootGui::invToDraw) {
                    if(pos.getString() == eq->name){
                        eq->use(player->PlayerEq, lootToDraw);
                    }
                }
            }
        }        for(auto &pos : LootGui::positionLootText) {
            if(pos.getGlobalBounds().contains(mouse_in_map) &&
               sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                while(pos.getGlobalBounds().contains(mouse_in_map) &&
                      sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {}
                for(auto &eq : LootGui::lootToDraw) {
                    if(pos.getString() == eq->name){
                       eq->use(player->PlayerEq, lootToDraw);
                        //   std::cout << "looting to eq" << std::endl;
                    }
                }
            }
        }
        if(backToGameText.getGlobalBounds().contains(mouse_in_map) &&
           sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            while(backToGameText.getGlobalBounds().contains(mouse_in_map) &&
                  sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {}
            this->drawLoot = !this->drawLoot;
        }
        window.draw(this->invSprite);
        window.draw(this->lootSprite);
        for(auto &pos : LootGui::positionInvText) {
            window.draw(pos);
        }for(auto &pos : LootGui::positionLootText) {
            window.draw(pos);
        }
        window.draw(backToGameText);
    }

}