//
// Created by igor on 26.01.2020.
//

#ifndef WIZARDTOWERGAME_PROJECTILE_H
#define WIZARDTOWERGAME_PROJECTILE_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "FightingObject.h"
#include "Player.h"

class Projectile: public FightingObject  {
public:
    sf::Vector2f actualPosition;
    sf::Vector2f destination;
    sf::Vector2f size;
    sf::RectangleShape projectileShape;
    float speed;
    float maxDistance;
    float damage;
    Projectile(sf::Vector2f startingPosition, sf::Vector2f size, float speed, float maxDistance, float damage, sf::Vector2f destination);
    ~Projectile();
    void Update(std::vector<Projectile *> & projectileObjects, std::vector<FightingObject *> & fightingObjects);
    void Draw(sf::RenderWindow &window);
};


#endif //WIZARDTOWERGAME_PROJECTILE_H
