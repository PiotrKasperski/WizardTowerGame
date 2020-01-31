//
// Created by klonek on 21.01.20.
//

#include "FightingObject.h"

void FightingObject::TakeDamage(int gainedDmg, FightingObject &object) {
    Staticstics::setCurrentLife(Staticstics::getCurrentLife() - gainedDmg);
}

void FightingObject::MakeDamage(std::vector<FightingObject *> fightingObjects) {
    for (auto &fightObject: fightingObjects) {
        if (!this->defenseBox.intersects(fightObject->defenseBox))
            this->dmgBox.intersects(fightObject->defenseBox) ||
            this->dmgBox.contains(fightObject->defenseBox.left, fightObject->defenseBox.top) ? fightObject->TakeDamage(
                    this->getStrenght(), *this) :
            this->setStamina(this->getStamina() - 1);
    }

    }


const sf::FloatRect &FightingObject::getDmgBox() const {
    return dmgBox;
}

void FightingObject::setDmgBox(const sf::FloatRect &dmgBox) {
    FightingObject::dmgBox = dmgBox;
}

const sf::FloatRect &FightingObject::getDefenseBox() const {
    return defenseBox;
}

void FightingObject::setDefenseBox(const sf::FloatRect &defenseBox) {
    FightingObject::defenseBox = defenseBox;
}

void FightingObject::setDmgBoxPosition(const sf::Vector2f vector) {
    FightingObject::dmgBox.top = vector.y;
    FightingObject::dmgBox.left = vector.x;
}

void FightingObject::Fight(std::vector<FightingObject *>) {

}

void FightingObject::Update(sf::RenderWindow &window) {
    RendererObject::Update(window);
    this->setDmgBoxPosition(sf::Vector2f(this->position.x - 32, this->position.y - 32));
    this->setDefenseBox(this->sprite.getGlobalBounds());
}

bool FightingObject::operator==(const FightingObject &rhs) const {
    return static_cast<const Staticstics &>(*this) == static_cast<const Staticstics &>(rhs) &&
           static_cast<const MovableObjects &>(*this) == static_cast<const MovableObjects &>(rhs) &&
           dmgBox == rhs.dmgBox &&
           defenseBox == rhs.defenseBox;
}

bool FightingObject::operator!=(const FightingObject &rhs) const {
    return !(rhs == *this);
}

bool FightingObject::operator!=(const CollisionObject &rhs) const {
    return rhs.getPosition() != position;
}
