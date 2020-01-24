//
// Created by igor on 23.01.2020.
//

#ifndef WIZARDTOWERGAME_STATSGUI_H
#define WIZARDTOWERGAME_STATSGUI_H


#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../../RendererObject.h"
#include "../../Player.h"

class StatsGui: public RendererObject {
private:
    Player* player;

    sf::Font font;
    sf::RectangleShape interfaceDialog;
    sf::Sprite stats;
    sf::Texture statstexture;
    bool drawStats;
    std::vector <std::string> StatsToDraw;
    sf::Text position[8];



    void initFont();
public:
    StatsGui(Player* player);
    ~StatsGui();


// functions


    void Update(sf::RenderWindow &window);
    void Draw(sf::RenderWindow& window);
};


#endif //WIZARDTOWERGAME_STATSGUI_H
