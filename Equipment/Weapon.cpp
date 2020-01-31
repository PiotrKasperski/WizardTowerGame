//
// Created by klonek on 29.01.20.
//

#include "Weapon.h"

Weapon::Weapon(std::string name, bool isEquiped, int AP, int defense) {
    this->isEquiped = isEquiped;
    this->name = name;
    this->AttackPower = AP;
    this->defense = defense;
    this->projectile = Projectile(sf::Vector2f(32.0f, 32.0f), this->name, 2.0f, 10.0f, this->AttackPower);
}

Weapon::~Weapon() {}

void Weapon::use(std::vector<Equipment *> eqVector) {
    // player handling
    if (this->isEquiped) {
        this->isEquiped = false;
    } else {
        for (auto &eq : eqVector) {
            if (eq->isEquiped && dynamic_cast<Weapon *>(eq) != nullptr) eq->isEquiped = false;
            this->isEquiped = true;
        }
    }
    // loot handling

}