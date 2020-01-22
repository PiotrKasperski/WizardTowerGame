//
// Created by igor on 21.01.2020.
//

#include "Interface.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <sstream>
#include <SFML/Window/Event.hpp>

void Interface::initFont() {
    this->font.loadFromFile("Fonts/font.ttf");
}
void Interface::initHpBar() {
    this->hpBarBackground.setSize(sf::Vector2f(100.f, 10.f));
    this->hpBarBackground.setFillColor(sf::Color(50,50,50,200));
    this->hpBarBackground.setPosition(sf::Vector2f(20,10));

    this->hpBarCurrent.setSize(sf::Vector2f((this->player->getMaxLife() / this->player->getCurrentLife() * 100), 10.f));
    this->hpBarCurrent.setFillColor(sf::Color(250,20,20,200));
    this->hpBarCurrent.setPosition(this->hpBarBackground.getPosition());

}

void Interface::InitLvlText() {
    this->lvlText.setFont(font);
    this->lvlText.setFillColor(sf::Color::Red);
    this->lvlText.setCharacterSize(10);
    this->lvlText.setString(std::to_string(this->player->getLevel()));
    this->lvlText.setPosition(sf::Vector2f(20,20));

}
void Interface::initExpBar() {
    this->expBarBackground.setSize(sf::Vector2f(100.f, 10.f));
    this->expBarBackground.setFillColor(sf::Color(50,50,50,200));
    this->expBarBackground.setPosition(sf::Vector2f(20,45));

    this->expBarCurrent.setSize(sf::Vector2f(100.f, 10.f));
    this->expBarCurrent.setFillColor(sf::Color::Yellow);
    this->expBarCurrent.setPosition(this->expBarBackground.getPosition());

}

Interface::Interface(Player* player) {
    this->player = player;
    this->initFont();
    this->initHpBar();
    this->InitLvlText();
    this->initExpBar();
    this->drawStats = false;

    this->interfaceDialog.setSize(sf::Vector2f(128 , 19));
    this->interfaceDialog.setFillColor(sf::Color::Blue);
    this->statstexture.loadFromFile("assets/textures/stat.png");
    this->stats.setTexture(statstexture);
}

Interface::~Interface() = default;


// functions
void Interface::updateHpBar(sf::RenderWindow& window) {
    this->hpBarBackground.setPosition(window.mapPixelToCoords(sf::Vector2i(20,10)));
    this->hpBarCurrent.setPosition(this->hpBarBackground.getPosition());
    auto lifePercentage = (float)(this->player->getCurrentLife() * 100.f / this->player->getMaxLife()) ;
    if(this->player->getCurrentLife() > 0)
    this->hpBarCurrent.setSize(sf::Vector2f(lifePercentage, 10));

}
void Interface::updateGUI(sf::RenderWindow& window) {
    this->lvlText.setString(std::to_string(this->player->getLevel()));
    this->lvlText.setPosition(window.mapPixelToCoords(sf::Vector2i(2, 20)));
}
void Interface::updateExp(sf::RenderWindow& window) {
    this->expBarBackground.setPosition(window.mapPixelToCoords(sf::Vector2i(20,21)));
    this->expBarCurrent.setPosition(this->expBarBackground.getPosition());
    this->expBarCurrent.setSize(sf::Vector2f(100.f, 10.f));

}

void Interface::updateStatsGui(Player* player) {
    Interface::StatsToDraw=player->getStats();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        this->drawStats = true;
    }
    if(player->getFreePoints() > 0)
    {
        std::string ss;
        std::string tmp=" Punkty: ";
        ss = std::to_string(player->getFreePoints());
        tmp+=ss;
        Interface::StatsToDraw.push_back(tmp);

        for(size_t i=2 ; i<this->StatsToDraw.size()-1 ; i++)
        {
            Interface::StatsToDraw[i]+= " +";
        }

    }
    Interface::StatsToDraw.emplace_back("\n POWROT");
    for (size_t i = 0 ; i < Interface::StatsToDraw.size() ; i++)
    {
        Interface::position[i].setFont(Interface::font);
        Interface::position[i].setString(Interface::StatsToDraw[i]);
        Interface::position[i].setCharacterSize(20);
        Interface::position[i].setPosition(player->getPosition().x - 100 , player->getPosition().y -(Interface::StatsToDraw.size()*25)/2+(i*25));


    }
}

void Interface::stat(sf::RenderWindow &window, Player* player )
{
    if(this->drawStats) {
        this->stats.setPosition(sf::Vector2f(player->getPosition().x - 128, player->getPosition().y - 160));
        this->interfaceDialog.setPosition(sf::Vector2f(player->getPosition().x - 64, player->getPosition().y - 8));
        auto mouse = sf::Mouse::getPosition(window);
        auto mouse_in_map = window.mapPixelToCoords(mouse);

            if (player->getFreePoints() > 0) {
                Interface::StatsToDraw[this->StatsToDraw.size()-1] += "rozdaj punkty";
                if (Interface::position[2].getGlobalBounds().contains(mouse_in_map) &&
                        sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                        while(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){ }
                         player->setMaxLife(player->getMaxLife()+50);
                         player->setFreePoints(player->getFreePoints()-1);
                } else if (Interface::position[3].getGlobalBounds().contains(mouse_in_map) &&
                        sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    while(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){ }
                    player->setStrenght(player->getStrenght()+1); //zaimplemenotowac podnoszenie danej statystki
                    player->setFreePoints(player->getFreePoints()-1);

                } else if (Interface::position[4].getGlobalBounds().contains(mouse_in_map) &&
                        sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    while(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){ }
                    player->setDefence(player->getDefence()+1); //zaimplemenotowac podnoszenie danej statystki
                    player->setFreePoints(player->getFreePoints()-1);

                } else if (Interface::position[5].getGlobalBounds().contains(mouse_in_map) &&
                        sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    while(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){ }
                    player->setSpeed(player->getSpeed()+1); //zaimplemenotowac podnoszenie danej statystki
                    player->setFreePoints(player->getFreePoints()-1);

                }
            }

            if (Interface::position[this->StatsToDraw.size()-1].getGlobalBounds().contains(mouse_in_map) &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                Interface::drawStats = false;
            }



            window.draw(this->stats);
            for (size_t i = 0; i < Interface::StatsToDraw.size(); i++) {
                window.draw(Interface::position[i]);
            }
    }

}


void Interface::update(sf::RenderWindow& window){
    this->updateGUI(window);
    this->updateHpBar(window);
    this->updateExp(window);
    this->updateStatsGui(this->player);
}
void Interface::renderHpBar(sf::RenderWindow& window) {
    window.draw(this->hpBarBackground);
    window.draw(this->hpBarCurrent);

}
void Interface::renderGUI(sf::RenderWindow& window) {
    window.draw(this->lvlText);
}
void Interface::renderExp(sf::RenderWindow& window) {
    window.draw(this->expBarBackground);
    window.draw(this->expBarCurrent);
}

void Interface::render(sf::RenderWindow& window){
    this->renderHpBar(window);
    this->renderGUI(window);
    this->renderExp(window);
    this->stat(window, this->player);
}
