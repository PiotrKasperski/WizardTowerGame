//
// Created by igor on 24.01.2020.
//

#ifndef WIZARDTOWERGAME_LOOTGUI_H
#define WIZARDTOWERGAME_LOOTGUI_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../../RendererObject.h"
#include "../../Player.h"
#include "../../Story.h"
#include <stdlib.h>
#include <time.h>

class LootGui: public RendererObject {
private:
    Weapon *testWeapon;
    Weapon *testWeapon2;
    Armor *testArmor;
    Player* player;
    Story* story;
    sf::Font font;
    sf::RectangleShape invDialog;
    sf::RectangleShape lootDialog;
    sf::Sprite invSprite;
    sf::Sprite lootSprite;
    sf::Texture invTexture;
    bool drawLoot;
    std::vector <Equipment *> invToDraw;
    std::vector <Equipment *> lootToDraw;
    std::vector <sf::Text> positionInvText;
    std::vector <sf::Text> positionLootText;
    sf::Text backToGameText;



    void initFont();
public:
    LootGui(Player* player, Story* story);
    ~LootGui();


// functions


    void Update(sf::RenderWindow &window);
    void Draw(sf::RenderWindow& window);
};


#endif //WIZARDTOWERGAME_LOOTGUI_H
