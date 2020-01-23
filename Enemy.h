//
// Created by klonek on 21.01.20.
//

#ifndef WIZARDTOWERGAME_ENEMY_H
#define WIZARDTOWERGAME_ENEMY_H


#include "CollisionObject.h"
#include "MovableObjects.h"
#include "FightingObject.h"

class Enemy : public FightingObject {
private:
    bool isAttack;
    FightingObject *fightedObject;
public:
/*
    Enemy(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect);*/

    void move(std::vector<CollisionObject *> vector) override;

    Enemy(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect);


    void Update(sf::RenderWindow &window) override;

    void TakeDamage(int gainedDmg, FightingObject &object) override;

    void MakeDamage(std::vector<FightingObject *> fightingObjects) override;

    void Fight(std::vector<FightingObject *> vector) override;
};


#endif //WIZARDTOWERGAME_ENEMY_H
