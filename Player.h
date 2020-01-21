//
// Created by klonek on 09.01.20.
//

#ifndef WIZARDTOWERGAME_PLAYER_H
#define WIZARDTOWERGAME_PLAYER_H


#include "RendererObject.h"
#include "MovableObjects.h"
#include "CollisionObject.h"
#include "FightingObject.h"

class Player : public MovableObjects, public CollisionObject, public FightingObject {
public:


    Player(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect);

    void move(std::vector<CollisionObject *>) override;

    void Update(sf::RenderWindow &window) override;
};


#endif //WIZARDTOWERGAME_PLAYER_H
