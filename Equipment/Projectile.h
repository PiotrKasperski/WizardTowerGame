//
// Created by igor on 26.01.2020.
//

#ifndef WIZARDTOWERGAME_PROJECTILE_H
#define WIZARDTOWERGAME_PROJECTILE_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../FightingObject.h"


class Projectile: public FightingObject  {
public:
    bool hited = false;
    sf::Vector2f actualPosition;
    float rotation;
    sf::Vector2f size;
    std::string name;
    float speed;
    float maxDistance;
    float damage;
    FightingObject *attacker;

    bool isCollision(std::vector<CollisionObject *> vector) override;

    Projectile(const sf::Vector2f &size, const std::string &name, float speed, float maxDistance, float damage);

    Projectile(Projectile &projectile, sf::Vector2f startingPosition, float damage, float rotation,
               FightingObject &attacker);

    Projectile(const sf::Vector2f &position, float rotation, const sf::Vector2f &size,
               const std::string &name, float speed, float maxDistance, float damage, FightingObject &attacker);

    Projectile();

    ~Projectile();

    void move(std::vector<CollisionObject *> vector) override;


    void Draw(sf::RenderWindow &window);


};


#endif //WIZARDTOWERGAME_PROJECTILE_H
