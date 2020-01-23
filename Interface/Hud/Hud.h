//
// Created by igor on 23.01.2020.
//

#ifndef WIZARDTOWERGAME_HUD_H
#define WIZARDTOWERGAME_HUD_H


#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../../RendererObject.h"
#include "../../Player.h"

class Hud: public RendererObject {
private:
    Player* player;

    sf::Font font;
    sf::RectangleShape hpBarBackground;
    sf::RectangleShape hpBarCurrent;
    sf::RectangleShape expBarBackground;
    sf::RectangleShape expBarCurrent;
    sf::Text lvlText;



    void InitLvlText();
    void initFont();
    void initHpBar();
    void initExpBar();
public:
    Hud(Player* player);
    ~Hud();


// functions


    void Update(sf::RenderWindow &window);
    void updateHpBar(sf::RenderWindow& window);
    void updateExpBar(sf::RenderWindow& window);
    void updateLvlText(sf::RenderWindow& window);


    void Draw(sf::RenderWindow& window);
    void drawHpBar(sf::RenderWindow& window);
    void drawExp(sf::RenderWindow &window);
    void drawLvlText(sf::RenderWindow& window);
};


#endif //WIZARDTOWERGAME_HUD_H
