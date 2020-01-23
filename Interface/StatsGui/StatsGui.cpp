//
// Created by igor on 23.01.2020.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "StatsGui.h"
void StatsGui::initFont() {
    this->font.loadFromFile("Fonts/font.ttf");
}
StatsGui::StatsGui(Player* player) {
    this->player = player;
    this->initFont();
    this->drawStats = false;

    this->interfaceDialog.setSize(sf::Vector2f(128 , 19));
    this->interfaceDialog.setFillColor(sf::Color::Blue);
    this->statstexture.loadFromFile("assets/textures/stat.png");
    this->stats.setTexture(statstexture);
}
StatsGui::~StatsGui() = default;


void StatsGui::Update(sf::RenderWindow &window) {
    StatsGui::StatsToDraw=player->getStats();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        // zabezpieczenie przed ciaglym wywolywaniem
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {}
        this->drawStats = !this->drawStats;
    }
    if(player->getFreePoints() > 0)
    {
        std::string ss;
        std::string tmp=" Punkty: ";
        ss = std::to_string(player->getFreePoints());
        tmp+=ss;
        StatsGui::StatsToDraw.push_back(tmp);

        for(size_t i=2 ; i<this->StatsToDraw.size()-1 ; i++)
        {
            StatsGui::StatsToDraw[i]+= " +";
        }

    }
    StatsGui::StatsToDraw.emplace_back("\n POWROT");
    for (size_t i = 0 ; i < StatsGui::StatsToDraw.size() ; i++)
    {
        StatsGui::position[i].setFont(StatsGui::font);
        StatsGui::position[i].setString(StatsGui::StatsToDraw[i]);
        StatsGui::position[i].setCharacterSize(20);
        StatsGui::position[i].setPosition(player->getPosition().x - 100 , player->getPosition().y -(StatsGui::StatsToDraw.size()*25)/2+(i*25));


    }
}

void StatsGui::Draw(sf::RenderWindow &window)
{
    if(this->drawStats) {
        this->stats.setPosition(sf::Vector2f(player->getPosition().x - 128, player->getPosition().y - 160));
        this->interfaceDialog.setPosition(sf::Vector2f(player->getPosition().x - 64, player->getPosition().y - 8));
        auto mouse = sf::Mouse::getPosition(window);
        auto mouse_in_map = window.mapPixelToCoords(mouse);

        if (player->getFreePoints() > 0) {
            StatsGui::StatsToDraw[this->StatsToDraw.size()-1] += "rozdaj punkty";
            if (StatsGui::position[2].getGlobalBounds().contains(mouse_in_map) &&
                sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                while(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){ }
                player->setMaxLife(player->getMaxLife()+50);
                player->setFreePoints(player->getFreePoints()-1);
            } else if (StatsGui::position[3].getGlobalBounds().contains(mouse_in_map) &&
                       sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                while(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){ }
                player->setStrenght(player->getStrenght()+1); //zaimplemenotowac podnoszenie danej statystki
                player->setFreePoints(player->getFreePoints()-1);

            } else if (StatsGui::position[4].getGlobalBounds().contains(mouse_in_map) &&
                       sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                while(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){ }
                player->setDefence(player->getDefence()+1); //zaimplemenotowac podnoszenie danej statystki
                player->setFreePoints(player->getFreePoints()-1);

            } else if (StatsGui::position[5].getGlobalBounds().contains(mouse_in_map) &&
                       sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                while(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){ }
                player->setSpeed(player->getSpeed()+1); //zaimplemenotowac podnoszenie danej statystki
                player->setFreePoints(player->getFreePoints()-1);

            }
        }

        if (StatsGui::position[this->StatsToDraw.size()-1].getGlobalBounds().contains(mouse_in_map) &&
            sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            StatsGui::drawStats = false;
        }

        window.draw(this->stats);
        for (size_t i = 0; i < StatsGui::StatsToDraw.size(); i++) {
            window.draw(StatsGui::position[i]);
        }
    }

}