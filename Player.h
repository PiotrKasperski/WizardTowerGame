//
// Created by klonek on 09.01.20.
//

#ifndef WIZARDTOWERGAME_PLAYER_H
#define WIZARDTOWERGAME_PLAYER_H


#include "RendererObject.h"
#include "MovableObjects.h"
#include "CollisionObject.h"
#include "FightingObject.h"
#include "Equipment/Weapon.h"
#include "Equipment/Armor.h"


class Player : public FightingObject {
public:
    float rotation;
    Weapon* weaponStart;
    Armor* armorStart;
    std::vector<Equipment *> PlayerEq;
    void TakeDamage(int gainedDmg, FightingObject &object) override;

    void Fight(std::vector<FightingObject *> vector) override;

    std::vector <std::string> getStats();

    Player(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect);

    void move(std::vector<CollisionObject *>) override;

    void Update(sf::RenderWindow &window) override;

    void setSpriteRotation();
};


#endif //WIZARDTOWERGAME_PLAYER_H
