//
// Created by igor on 23.01.2020.
//

#ifndef WIZARDTOWERGAME_INVENTORYGUI_H
#define WIZARDTOWERGAME_INVENTORYGUI_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../../RendererObject.h"
#include "../../Player.h"

class InventoryGui: public RendererObject {
private:
    Player* player;
    sf::Font font;
    sf::RectangleShape invDialog;
    sf::Sprite invSprite;
    sf::Texture invTexture;
    bool drawInv;
    std::vector <Equipment *> StatsToDraw;
    std::vector <sf::Text> position;
    sf::Text BackToGameText;



    void initFont();
public:
    InventoryGui(Player* player);
    ~InventoryGui();


// functions


    void Update(sf::RenderWindow &window);
    void Draw(sf::RenderWindow& window);
};


#endif //WIZARDTOWERGAME_INVENTORYGUI_H
