//
// Created by klonek on 21.01.20.
//

#ifndef WIZARDTOWERGAME_ENEMY_H
#define WIZARDTOWERGAME_ENEMY_H


#include "CollisionObject.h"
#include "MovableObjects.h"

class Enemy : public CollisionObject, public MovableObjects {
public:
/*
    Enemy(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect);*/

    void move(std::vector<CollisionObject *> vector) override;

    Enemy(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect);


    void Update(sf::RenderWindow &window) override;


};


#endif //WIZARDTOWERGAME_ENEMY_H
