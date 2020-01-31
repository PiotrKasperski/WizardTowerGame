//
// Created by igor on 26.01.2020.
//

#ifndef WIZARDTOWERGAME_PROJECTILE_H
#define WIZARDTOWERGAME_PROJECTILE_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../FightingObject.h"


class Projectile: public FightingObject  {
public:
    sf::Vector2f actualPosition;
    sf::Vector2f destination;
    sf::Vector2f size;
    sf::RectangleShape projectileShape;
    std::string name;
    float speed;

    bool isCollision(std::vector<CollisionObject *> vector) override;

    float maxDistance;
    float damage;

    Projectile(const sf::Vector2f &size, const std::string &name, float speed, float maxDistance, float damage);

    Projectile(Projectile &projectile, sf::Vector2f startingPosition, float damage, sf::Vector2f destination);

    Projectile(const sf::Vector2f &position, const sf::Vector2f &destination, const sf::Vector2f &size,
               const std::string &name, float speed, float maxDistance, float damage);

    Projectile();

    ~Projectile();

    void move(std::vector<CollisionObject *> vector) override;


    void Draw(sf::RenderWindow &window);

    CollisionObject *hitedObject;
};


#endif //WIZARDTOWERGAME_PROJECTILE_H
