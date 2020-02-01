//
// Created by igor on 26.01.2020.
//

#include <iostream>
#include <cmath>
#include "Projectile.h"
#include "../FightMenager.h"

Projectile::~Projectile() = default;

    void Projectile::Draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
}

void Projectile::move(std::vector<CollisionObject *> vector) {

    sf::Vector2f moveVector = sf::Vector2f(this->speed * std::cos(M_PI * this->rotation / 180),
                                           this->speed * std::sin(M_PI * this->rotation / 180));
    this->maxDistance -= this->speed;
    this->position += moveVector;
    this->sprite.setPosition(this->position);
    this->setDmgBoxPosition(sf::Vector2f(this->position.x, this->position.y));

    if (this->maxDistance <= 0) {
        this->hited = true;
    }

}

bool Projectile::isCollision(std::vector<CollisionObject *> vector) {
    for (const auto &item : vector) {
        if (*item != *this->attacker) {
            for (const auto &boundingBox : *item->getBoundingBoxes()) {
                if (boundingBox->contains(this->getDmgBox().left + (this->getDmgBox().width / 2),
                                          this->getDmgBox().top + (this->getDmgBox().height / 2))) {
                    this->hited = true;
                    return true;
                }
            }
        }
    }

    return false;
}

Projectile::Projectile(const sf::Vector2f &size, const std::string &name, float speed, float maxDistance, float damage)
        : size(size), name(name), speed(speed), maxDistance(maxDistance), damage(damage) {
    this->maxDistance *= 32;
    Projectile::setDmgBox(sf::FloatRect(
            this->position,
            size));
}

Projectile::Projectile(Projectile &projectile, sf::Vector2f startingPosition, float damage, float rotation,
                       FightingObject &attacker) {
    *this = projectile;
    this->attacker = &attacker;
    this->position = startingPosition;
    this->sprite.setPosition(this->position);
    this->damage += damage;
    this->rotation = rotation;
    Projectile::setDmgBox(sf::FloatRect(
            this->position,
            this->size));
}

Projectile::Projectile() {}

Projectile::Projectile(const sf::Vector2f &position, float rotation, const sf::Vector2f &size,
                       const std::string &name, float speed, float maxDistance, float damage, FightingObject &attacker)
        :
        actualPosition(position), rotation(rotation), size(size), name(name), speed(speed),
        maxDistance(maxDistance), damage(damage), attacker(&attacker) {
    this->position = actualPosition;
    this->position.x += 16;
    this->position.y += 16;
    if (this->texture.loadFromFile("../assets/textures/" + this->name + ".png", sf::IntRect(0, 0, 32, 32))) {
        std::cout << "swordLoaded" << std::endl;
    }
    this->sprite.setTexture(this->texture, true);
    this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
    this->sprite.rotate(this->rotation + 45.0);
    this->sprite.setPosition(this->position);
    Projectile::setDmgBox(sf::FloatRect(
            this->position,
            this->size));
}




