//
// Created by igor on 26.01.2020.
//

#include <iostream>
#include "Projectile.h"
Projectile::Projectile(sf::Vector2f startingPosition, sf::Vector2f size, float speed, float maxDistance, float damage, sf::Vector2f destination) {
    Projectile::actualPosition = startingPosition;
    Projectile::size = size;
    Projectile::speed = speed;
    Projectile::maxDistance = maxDistance;
    Projectile::damage = damage;
    Projectile::destination = destination;

    Projectile::projectileShape.setSize(this->size);
    Projectile::projectileShape.setFillColor(sf::Color(50,50,50,200));
    Projectile::projectileShape.setPosition(this->actualPosition);
    Projectile::setDmgBox(sf::FloatRect(
            this->actualPosition,
            size));
}
Projectile::~Projectile() = default;


    void Projectile::Update(std::vector<Projectile *> & projectileObjects, std::vector<FightingObject *> & fightingObjects) {
    if(this->maxDistance > 0) {
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
    }
}
    void Projectile::Draw(sf::RenderWindow &window) {
    window.draw(this->projectileShape);
}