//
// Created by klonek on 09.01.20.
//

#ifndef WIZARDTOWERGAME_PLAYER_H
#define WIZARDTOWERGAME_PLAYER_H


#include "RendererObject.h"
#include "MovableObjects.h"

class Player: public MovableObjects {
public:
    Player(const sf::Vector2i &position, const std::string textureFilename, sf::IntRect textureRect);

    void move() override;

    void Update(sf::RenderWindow &window) override;
};


#endif //WIZARDTOWERGAME_PLAYER_H
