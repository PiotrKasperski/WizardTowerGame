//
// Created by igor on 21.01.2020.
//

#ifndef WIZARDTOWERGAME_INTERFACE_H
#define WIZARDTOWERGAME_INTERFACE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "Player.h"
class Interface {
private:
    Player* player;

    sf::Font font;
    sf::RectangleShape hpBarBackground;
    sf::RectangleShape hpBarCurrent;
    sf::RectangleShape expBarBackground;
    sf::RectangleShape expBarCurrent;
    sf::RectangleShape interfaceDialog;
    sf::Text lvlText;
    sf::Sprite stats;
    sf::Texture statstexture;
    bool drawStats;
    std::vector <std::string> StatsToDraw;
    sf::Text position[8];



    void InitLvlText();
    void initFont();
    void initHpBar();
    void initExpBar();
    void stat(sf::RenderWindow &window, Player* player);
public:
    Interface(Player* player);
    ~Interface();


// functions


void update(sf::RenderWindow &window);
void updateHpBar(sf::RenderWindow& window);
void updateGUI(sf::RenderWindow& window);
void updateExp(sf::RenderWindow& window);
void updateStatsGui(Player* player);


void render(sf::RenderWindow& window);
void renderHpBar(sf::RenderWindow& window);
void renderGUI(sf::RenderWindow &window);
void renderExp(sf::RenderWindow &window);

};
#endif //WIZARDTOWERGAME_INTERFACE_H
