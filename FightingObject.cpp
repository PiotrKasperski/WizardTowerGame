//
// Created by klonek on 21.01.20.
//

#include "FightingObject.h"

void FightingObject::TakeDamage(int gainedDmg) {
    Staticstics::setCurrentLife(Staticstics::getCurrentLife() - gainedDmg);
}

void FightingObject::MakeDamage(std::vector<FightingObject> fightingObjects) {
    for (auto &fightObject: fightingObjects) {
        this->dmgBox.intersects(fightObject.defenseBox) ||
        this->dmgBox.contains(fightObject.defenseBox.left, fightObject.defenseBox.top) ? fightObject.TakeDamage(
                this->getStrenght()) : this->setStamina(this->getStamina() - 1);
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
