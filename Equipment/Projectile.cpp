//
// Created by igor on 26.01.2020.
//

#include <iostream>
#include "Projectile.h"

Projectile::~Projectile() = default;


/*    if(this->maxDistance > 0) {
        if (this->destination.x > this->actualPosition.x && this->destination.x > 0) {
            this->actualPosition.x += this->speed;
        } else  {
            this->actualPosition.x -= this->speed;
        }
        if (this->destination.y > this->actualPosition.y && this->destination.y > 0) {
            this->actualPosition.y += this->speed;
        } else  {
            this->actualPosition.y -= this->speed;
        }
    --this->maxDistance;
    this->projectileShape.setPosition(this->actualPosition);
    this->setDmgBoxPosition(sf::Vector2f(this->actualPosition.x, this->actualPosition.y));
    std::cout << this->getDmgBox().contains(fightingObjects[0]->getDmgBox().left, fightingObjects[0]->getDmgBox().top) << std::endl;
    //std::cout <<"x: " << this->getDmgBox().left << " y: " << this->getDmgBox().top  << std::endl;
        for (auto &fightObject: fightingObjects) {
            if (this->getDmgBox().intersects(fightObject->getDefenseBox()) ||
                this->getDmgBox().contains(fightObject->getDefenseBox().left, fightObject->getDefenseBox().top)) {
                fightObject->TakeDamage(
                        this->damage, *this);
                projectileObjects.erase(std::find(projectileObjects.begin(), projectileObjects.end(), this));
            }
        }
    } else {
        projectileObjects.erase(std::find(projectileObjects.begin(), projectileObjects.end(), this));
    }*/

    void Projectile::Draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
}

void Projectile::move(std::vector<CollisionObject *> vector) {
    // MovableObjects::move(vector);
}

bool Projectile::isCollision(std::vector<CollisionObject *> vector) {
    for (const auto &item : vector) {
        for (const auto &boundingBox : *item->getBoundingBoxes()) {
            if (boundingBox->intersects(this->getDmgBox())) {
                this->hitedObject = item;
                return true;
            }
        }
    }
    return false;
}

Projectile::Projectile(const sf::Vector2f &size, const std::string &name, float speed, float maxDistance, float damage)
        : size(size), name(name), speed(speed), maxDistance(maxDistance), damage(damage) {
    if (this->texture.loadFromFile("../assets/textures/sword.png")) {
        std::cout << "swordLoaded" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    Projectile::setDmgBox(sf::FloatRect(
            this->position,
            size));
}

Projectile::Projectile(Projectile &projectile, sf::Vector2f startingPosition, float damage, sf::Vector2f destination) {
    *this = projectile;
    this->position = startingPosition;
    this->sprite.setPosition(this->position);
    this->texture.loadFromFile("../assets/textures/sword.png");
    //this->sprite.setTextureRect(sf::IntRect(0,0,32,32));
    this->sprite.setTexture(this->texture);
    this->damage += damage;
    this->destination = destination;
    Projectile::setDmgBox(sf::FloatRect(
            this->position,
            this->size));
}

Projectile::Projectile() {}



